/*******************************************************************************


   Copyright (C) 2011-2014 SequoiaDB Ltd.

   This program is free software: you can redistribute it and/or modify
   it under the term of the GNU Affero General Public License, version 3,
   as published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warrenty of
   MARCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program. If not, see <http://www.gnu.org/license/>.

   Source File Name = aggrGroup.hpp

   Descriptive Name =

   When/how to use: this program may be used on binary and text-formatted
   versions of PMD component. This file contains functions for agent processing.

   Dependencies: N/A

   Restrictions: N/A

   Change Activity:
   defect Date        Who Description
   ====== =========== === ==============================================
          01/27/2015  LZ  Initial Draft

   Last Changed =

*******************************************************************************/
#ifndef _SDB_MONGO_CONVERTER_HPP_
#define _SDB_MONGO_CONVERTER_HPP_

#include "util.hpp"
#include "oss.hpp"
#include "mongodef.hpp"
#include "commands.hpp"

class command ;

class mongoConverter : public baseConverter, public SDBObject
{
public:
   mongoConverter() : _cmd( NULL )
   {
      _bigEndian = checkBigEndian() ;
      parser.setEndian( _bigEndian ) ;
   }

   ~mongoConverter()
   {

   }

   BOOLEAN isBigEndian() const
   {
      return _bigEndian ;
   }

   BOOLEAN isGetLastError() const
   {
      const CHAR *ptr = NULL ;
      ptr = ossStrstr( _cmd->name(), "getLastError" ) ;
      if ( NULL == ptr )
      {
         ptr = ossStrstr( _cmd->name(), "getlasterror" ) ;
      }
      return NULL != ptr ;
   }

   void resetCommand()
   {
      _cmd = NULL ;
   }

   virtual INT32 convert( msgBuffer &out ) ;
   virtual INT32 reConvert( msgBuffer *in, msgBuffer &out ) ;

private:
   BOOLEAN _bigEndian ;
   command *_cmd ;
   mongoParser parser ;
};
#endif
