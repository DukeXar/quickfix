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

#include "MessageSorters.h"

namespace FIX
{
message_order::message_order( int first, ... )
: m_mode( group )
{
  va_list arguments;
  va_start( arguments, first );

  Order order;
  order.reserve(32);
  order.push_back(first);

  while ( true )
  {
    int argument = va_arg( arguments, int );
    if ( argument == 0 )
      break;
    order.push_back( argument );
  }

  setOrder( &order[0], order.size() );

  va_end( arguments );
}

message_order::message_order( int const * order, size_t size )
: m_mode( group )
{
  setOrder( order, size );
}

message_order::message_order( Order const & order )
: m_mode( group )
{
  setOrder( &order[0], order.size() );
}

void message_order::setOrder( int const * order, size_t size )
{
  if (size < 1) return;

  int largest = *(std::max_element(order, order + size));

  Order * target = new Order( largest + 1, 0 );
  m_groupOrder.reset( target );

  for (int i = 0; i < size; ++i)
  {
    (*target)[ order[ i ] ] = i + 1;
  }
}

} // namespace FIX
// vim: set ts=2 ai
