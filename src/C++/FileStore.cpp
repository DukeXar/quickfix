/****************************************************************************
** Copyright (c) quickfixengine.org  All rights reserved.
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifdef _MSC_VER
#include "stdafx.h"
#else
#include "config.h"
#endif
#include "CallStack.h"

#include "FileStore.h"
#include "SessionID.h"
#include "Parser.h"
#include "Utility.h"
#include <fstream>

namespace FIX
{
FileStore::FileStore( std::string path, const SessionID& s )
: m_msgFile( 0 ), m_headerFile( 0 ), m_seqNumsFile( 0 ), m_sessionFile( 0 )
{
  file_mkdir( path.c_str() );

  if ( path.empty() ) path = ".";
  const std::string& begin =
    s.getBeginString().getString();
  const std::string& sender =
    s.getSenderCompID().getString();
  const std::string& target =
    s.getTargetCompID().getString();
  const std::string& qualifier =
    s.getSessionQualifier();

  std::string sessionid = begin + "-" + sender + "-" + target;
  if( qualifier.size() )
    sessionid += "-" + qualifier;

  std::string prefix
    = file_appendpath(path, sessionid + ".");

  m_msgFileName = prefix + "body";
  m_headerFileName = prefix + "header";
  m_seqNumsFileName = prefix + "seqnums";
  m_sessionFileName = prefix + "session";

  try
  {
    open( false );
  }
  catch ( IOException & e )
  {
    throw ConfigError( e.what() );
  }
}

FileStore::~FileStore()
{
  if( m_msgFile ) fclose( m_msgFile );
  if( m_headerFile ) fclose( m_headerFile );
  if( m_seqNumsFile ) fclose( m_seqNumsFile );
  if( m_sessionFile ) fclose( m_sessionFile );
}

void FileStore::open( bool deleteFile )
{ QF_STACK_PUSH(FileStore::open)

  if ( m_msgFile ) fclose( m_msgFile );
  if ( m_headerFile ) fclose( m_headerFile );
  if ( m_seqNumsFile ) fclose( m_seqNumsFile );
  if ( m_sessionFile ) fclose( m_sessionFile );

  m_msgFile = 0;
  m_headerFile = 0;
  m_seqNumsFile = 0;
  m_sessionFile = 0;

  if ( deleteFile )
  {
    file_unlink( m_msgFileName.c_str() );
    file_unlink( m_headerFileName.c_str() );
    file_unlink( m_seqNumsFileName.c_str() );
    file_unlink( m_sessionFileName.c_str() );
  }

  populateCache();
  m_msgFile = file_fopen( m_msgFileName.c_str(), "r+" );
  if ( !m_msgFile ) m_msgFile = file_fopen( m_msgFileName.c_str(), "w+" );
  if ( !m_msgFile ) throw ConfigError( "Could not open body file: " + m_msgFileName );

  m_headerFile = file_fopen( m_headerFileName.c_str(), "r+" );
  if ( !m_headerFile ) m_headerFile = file_fopen( m_headerFileName.c_str(), "w+" );
  if ( !m_headerFile ) throw ConfigError( "Could not open header file: " + m_headerFileName );

  m_seqNumsFile = file_fopen( m_seqNumsFileName.c_str(), "r+" );
  if ( !m_seqNumsFile ) m_seqNumsFile = file_fopen( m_seqNumsFileName.c_str(), "w+" );
  if ( !m_seqNumsFile ) throw ConfigError( "Could not open seqnums file: " + m_seqNumsFileName );

  bool setCreationTime = false;
  m_sessionFile = file_fopen( m_sessionFileName.c_str(), "r" );
  if ( !m_sessionFile ) setCreationTime = true;
  else fclose( m_sessionFile );

  m_sessionFile = file_fopen( m_sessionFileName.c_str(), "r+" );
  if ( !m_sessionFile ) m_sessionFile = file_fopen( m_sessionFileName.c_str(), "w+" );
  if ( !m_sessionFile ) throw ConfigError( "Could not open session file" );
  if ( setCreationTime ) setSession();

  setNextSenderMsgSeqNum( getNextSenderMsgSeqNum() );
  setNextTargetMsgSeqNum( getNextTargetMsgSeqNum() );

  QF_STACK_POP
}

void FileStore::populateCache()
{ QF_STACK_PUSH(FileStore::populateCache)

  std::string msg;
  Message message;

  FILE* headerFile;
  headerFile = file_fopen( m_headerFileName.c_str(), "r+" );
  if ( headerFile )
  {
    int num, offset, size;
    while ( FILE_FSCANF( headerFile, "%d,%d,%d ", &num, &offset, &size ) == 3 )
      m_offsets[ num ] = std::make_pair( offset, size );
    fclose( headerFile );
  }

  FILE* seqNumsFile;
  seqNumsFile = file_fopen( m_seqNumsFileName.c_str(), "r+" );
  if ( seqNumsFile )
  {
    int sender, target;
    if ( FILE_FSCANF( seqNumsFile, "%d : %d", &sender, &target ) == 2 )
    {
      m_cache.setNextSenderMsgSeqNum( sender );
      m_cache.setNextTargetMsgSeqNum( target );
    }
    fclose( seqNumsFile );
  }

  FILE* sessionFile;
  sessionFile = file_fopen( m_sessionFileName.c_str(), "r+" );
  if ( sessionFile )
  {
    char time[ 22 ];
#ifdef HAVE_FSCANF_S
    int result = FILE_FSCANF( sessionFile, "%s", time, 22 );
#else
    int result = FILE_FSCANF( sessionFile, "%s", time );
#endif
    if( result == 1 )
    {
      m_cache.setCreationTime( UtcTimeStampConvertor::convert( time ) );
    }
    fclose( sessionFile );
  }

  QF_STACK_POP
}

MessageStore* FileStoreFactory::create( const SessionID& s )
{ QF_STACK_PUSH(FileStoreFactory::create)

  if ( m_path.size() ) return new FileStore( m_path, s );

  std::string path;
  Dictionary settings = m_settings.get( s );
  path = settings.getString( FILE_STORE_PATH );
  return new FileStore( path, s );

  QF_STACK_POP
}

void FileStoreFactory::destroy( MessageStore* pStore )
{ QF_STACK_PUSH(FileStoreFactory::destroy)
  delete pStore;
  QF_STACK_POP
}

bool FileStore::set( int msgSeqNum, const std::string& msg )
throw ( IOException )
{ QF_STACK_PUSH(FileStore::set)

  if ( fseek( m_msgFile, 0, SEEK_END ) ) 
    throw IOException( "Cannot seek to end of " + m_msgFileName );
  if ( fseek( m_headerFile, 0, SEEK_END ) ) 
    throw IOException( "Cannot seek to end of " + m_headerFileName );

  int offset = ftell( m_msgFile );
  if ( offset < 0 ) 
    throw IOException( "Unable to get file pointer position from " + m_msgFileName );
  int size = msg.size();

  if ( fprintf( m_headerFile, "%d,%d,%d ", msgSeqNum, offset, size ) < 0 )
    throw IOException( "Unable to write to file " + m_headerFileName );
  m_offsets[ msgSeqNum ] = std::make_pair( offset, size );
  fwrite( msg.c_str(), sizeof( char ), msg.size(), m_msgFile );
  if ( ferror( m_msgFile ) ) 
    throw IOException( "Unable to write to file " + m_msgFileName );
  if ( fflush( m_msgFile ) == EOF ) 
    throw IOException( "Unable to flush file " + m_msgFileName );
  if ( fflush( m_headerFile ) == EOF ) 
    throw IOException( "Unable to flush file " + m_headerFileName );
  return true;

  QF_STACK_POP
}

void FileStore::get( int begin, int end,
                     std::vector < std::string > & result ) const
throw ( IOException )
{ QF_STACK_PUSH(FileStore::get)

  result.clear();
  std::string msg;
  for ( int i = begin; i <= end; ++i )
  {
    if ( get( i, msg ) )
      result.push_back( msg );
  }

  QF_STACK_POP
}

int FileStore::getNextSenderMsgSeqNum() const throw ( IOException )
{ QF_STACK_PUSH(FileStore::getNextSenderMsgSeqNum)
  return m_cache.getNextSenderMsgSeqNum();
  QF_STACK_POP
}

int FileStore::getNextTargetMsgSeqNum() const throw ( IOException )
{ QF_STACK_PUSH(FileStore::getNextTargetMsgSeqNum)
  return m_cache.getNextTargetMsgSeqNum();
  QF_STACK_POP
}

void FileStore::setNextSenderMsgSeqNum( int value ) throw ( IOException )
{ QF_STACK_PUSH(FileStore::setNextSenderMsgSeqNum)
  m_cache.setNextSenderMsgSeqNum( value );
  setSeqNum();
  QF_STACK_POP
}

void FileStore::setNextTargetMsgSeqNum( int value ) throw ( IOException )
{ QF_STACK_PUSH(FileStore::setNextTargetMsgSeqNum)
  m_cache.setNextTargetMsgSeqNum( value );
  setSeqNum();
  QF_STACK_POP
}

void FileStore::incrNextSenderMsgSeqNum() throw ( IOException )
{ QF_STACK_PUSH(FileStore::incrNextSenderMsgSeqNum)
  m_cache.incrNextSenderMsgSeqNum();
  setSeqNum();
  QF_STACK_POP
}

void FileStore::incrNextTargetMsgSeqNum() throw ( IOException )
{ QF_STACK_PUSH(FileStore::incrNextTargetMsgSeqNum)
  m_cache.incrNextTargetMsgSeqNum();
  setSeqNum();
  QF_STACK_POP
}

UtcTimeStamp FileStore::getCreationTime() const throw ( IOException )
{ QF_STACK_PUSH(FileStore::getCreationTime)
  return m_cache.getCreationTime();
  QF_STACK_POP
}

void FileStore::reset() throw ( IOException )
{ QF_STACK_PUSH(FileStore::reset)

  m_cache.reset();
  open( true );
  setSession();

  QF_STACK_POP
}

void FileStore::refresh() throw ( IOException )
{ QF_STACK_PUSH(FileStore::refresh)

  m_cache.reset();
  open( false );

  QF_STACK_POP
}

void FileStore::setSeqNum()
{ QF_STACK_PUSH(FileStore::setSeqNum)

  rewind( m_seqNumsFile );
  fprintf( m_seqNumsFile, "%10.10d : %10.10d",
           getNextSenderMsgSeqNum(), getNextTargetMsgSeqNum() );
  if ( ferror( m_seqNumsFile ) ) 
    throw IOException( "Unable to write to file " + m_seqNumsFileName );
  if ( fflush( m_seqNumsFile ) ) 
    throw IOException( "Unable to flush file " + m_seqNumsFileName );

  QF_STACK_POP
}

void FileStore::setSession()
{ QF_STACK_PUSH(FileStore::setSession)

  rewind( m_sessionFile );
  fprintf( m_sessionFile, "%s",
           UtcTimeStampConvertor::convert( m_cache.getCreationTime() ).c_str() );
  if ( ferror( m_sessionFile ) ) 
    throw IOException( "Unable to write to file " + m_sessionFileName );
  if ( fflush( m_sessionFile ) ) 
    throw IOException( "Unable to flush file " + m_sessionFileName );

  QF_STACK_POP
}

bool FileStore::get( int msgSeqNum, std::string& msg ) const
throw ( IOException )
{ QF_STACK_PUSH(FileStore::get)

  NumToOffset::const_iterator find = m_offsets.find( msgSeqNum );
  if ( find == m_offsets.end() ) return false;
  const OffsetSize& offset = find->second;
  if ( fseek( m_msgFile, offset.first, SEEK_SET ) ) 
    throw IOException( "Unable to seek in file " + m_msgFileName );
  char* buffer = new char[ offset.second + 1 ];
  fread( buffer, sizeof( char ), offset.second, m_msgFile );
  if ( ferror( m_msgFile ) ) 
    throw IOException( "Unable to read from file " + m_msgFileName );
  buffer[ offset.second ] = 0;
  msg = buffer;
  delete [] buffer;
  return true;

  QF_STACK_POP
}

} //namespace FIX
