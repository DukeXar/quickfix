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

#include "FieldMap.h"
#include "Group.h"
#include <algorithm>
#include <iterator>

namespace FIX
{
FieldMap::FieldMap( const FieldMap& rhs )
  : m_fields( rhs.m_fields.key_comp() )
{
  for ( Fields::const_iterator i = rhs.m_fields.begin(), end = rhs.m_fields.end(); i != end; ++i )
  {
    m_fields.insert( std::make_pair( i->first, i->second.copy() ) );
  }

  for ( Groups::const_iterator i = rhs.m_groups.begin(), end = rhs.m_groups.end(); i != end; ++i )
  {
    for ( FieldMaps::const_iterator j = i->second.begin(), end = i->second.end(); j != end; ++j )
    {
      addGroup( i->first, **j );
    }
  }
}

void FieldMap::addGroup( int groupId, const FieldMap& group, bool setCount )
{ QF_STACK_PUSH(FieldMap::addGroup)

  FieldMap * pGroup = new FieldMap( group );

  FieldMaps & maps = m_groups[ groupId ];
  maps.push_back( pGroup );

  if( setCount )
  {
    setField( IntField( groupId, maps.size() ) );
  }

  QF_STACK_POP
}

Group & FieldMap::addGroup( int groupId, int field, int delim, const message_order & order, bool setCount )
{
  Group * pGroup = new Group( field, delim, order );

  FieldMaps & maps = m_groups[ groupId ];
  maps.push_back( pGroup );

  if( setCount )
  {
    setField( IntField( groupId, maps.size() ) );
  }

  return *pGroup;
}

void FieldMap::replaceGroup( int num, int field, const FieldMap& group )
{ QF_STACK_PUSH(FieldMap::replaceGroup)

  Groups::const_iterator i = m_groups.find( field );
  if ( i == m_groups.end() ) return;
  if ( num <= 0 ) return;
  if ( i->second.size() < ( unsigned ) num ) return;
  *( *( i->second.begin() + ( num - 1 ) ) ) = group;

  QF_STACK_POP
}

void FieldMap::removeGroup( int num, int field )
{
  Groups::iterator i = m_groups.find( field );
  if ( i == m_groups.end() ) return;
  if ( num <= 0 ) return;
  std::vector< FieldMap* >& vector = i->second;
  if ( vector.size() < ( unsigned ) num ) return;

  std::deque< FieldMap* > queue;
  while( vector.size() > (unsigned)num )
  {
    queue.push_back( vector.back() );
    vector.pop_back();
  }
  delete vector.back();
  vector.pop_back();
  while( queue.size() )
  {
    vector.push_back( queue.front() );
    queue.pop_front();
  }

  if( vector.size() == 0 )
  {
    m_groups.erase( field );
  }
  else
  {
    IntField groupCount( field, vector.size() );
    setField( groupCount, true );
  }
}

void FieldMap::removeGroup( int field )
{ QF_STACK_PUSH(FieldMap::removeGroup)
  removeGroup( groupCount(field), field );
  QF_STACK_POP
}

void FieldMap::removeField( int field )
{ QF_STACK_PUSH(FieldMap::removeField)

  Fields::iterator i = m_fields.find( field );
  if ( i != m_fields.end() )
    m_fields.erase( i );

  QF_STACK_POP
}

bool FieldMap::hasGroup( int num, int field ) const
{ QF_STACK_PUSH(FieldMap::hasGroup)

  return groupCount(field) >= num;

  QF_STACK_POP
}

bool FieldMap::hasGroup( int field ) const
{ QF_STACK_PUSH(FieldMap::hasGroup)

  Groups::const_iterator i = m_groups.find( field );
  return i != m_groups.end();

  QF_STACK_POP
}

int FieldMap::groupCount( int field ) const
{ QF_STACK_PUSH(FieldMap::groupCount)

  Groups::const_iterator i = m_groups.find( field );
  if( i == m_groups.end() )
    return 0;
  return i->second.size();

  QF_STACK_POP
}

void FieldMap::releaseGroups()
{
  for ( Groups::iterator it = m_groups.begin(), end = m_groups.end(); it != end; ++it )
  {
    for ( Groups::mapped_type::iterator ptrIt = it->second.begin(), ptrEnd = it->second.end(); ptrIt != ptrEnd; ++ptrIt )
    {
      delete *ptrIt;
    }
  }
}

void FieldMap::clear()
{ QF_STACK_PUSH(FieldMap::clear)

  releaseGroups();

  m_fields.clear();
  m_groups.clear();

  QF_STACK_POP
}

int FieldMap::totalFields() const
{
  int result = m_fields.size();
    
  Groups::const_iterator i;
  for ( i = m_groups.begin(); i != m_groups.end(); ++i )
  {
    std::vector < FieldMap* > ::const_iterator j;
    for ( j = i->second.begin(); j != i->second.end(); ++j )
      result += ( *j ) ->totalFields();
  }
  return result;
}

std::string& FieldMap::calculateString( std::string& result, bool clear ) const
{ QF_STACK_PUSH(FieldMap::calculateString)

#if defined(_MSC_VER) && _MSC_VER < 1300
  if( clear ) result = "";
#else
  if( clear ) result.clear();
#endif

  if( !result.size() )
    result.reserve( totalFields() * 32 );
    
  Fields::const_iterator i;
  for ( i = m_fields.begin(); i != m_fields.end(); ++i )
  {
    result += i->second.getValue();

    // add groups if they exist
    if( !m_groups.size() ) continue;
    Groups::const_iterator j = m_groups.find( i->first );
    if ( j == m_groups.end() ) continue;
    std::vector < FieldMap* > ::const_iterator k;
    for ( k = j->second.begin(); k != j->second.end(); ++k )
      ( *k ) ->calculateString( result, false );
  }
  return result;

  QF_STACK_POP
}

int FieldMap::calculateLength( int beginStringField,
                               int bodyLengthField,
                               int checkSumField ) const
{
  int result = 0;
  Fields::const_iterator i;
  for ( i = m_fields.begin(); i != m_fields.end(); ++i )
  {
    if ( i->first != beginStringField
         && i->first != bodyLengthField
         && i->first != checkSumField )
    { result += i->second.getLength(); }
  }

  Groups::const_iterator j;
  for ( j = m_groups.begin(); j != m_groups.end(); ++j )
  {
    std::vector < FieldMap* > ::const_iterator k;
    for ( k = j->second.begin(); k != j->second.end(); ++k )
      result += ( *k ) ->calculateLength();
  }
  return result;
}

int FieldMap::calculateTotal( int checkSumField ) const
{ QF_STACK_PUSH(FieldMap::calculateTotal)

  int result = 0;
  Fields::const_iterator i;
  for ( i = m_fields.begin(); i != m_fields.end(); ++i )
  {
    if ( i->first != checkSumField )
      result += i->second.getTotal();
  }

  Groups::const_iterator j;
  for ( j = m_groups.begin(); j != m_groups.end(); ++j )
  {
    std::vector < FieldMap* > ::const_iterator k;
    for ( k = j->second.begin(); k != j->second.end(); ++k )
      result += ( *k ) ->calculateTotal();
  }
  return result;

  QF_STACK_POP
}
}
// vim: sw=2 :
