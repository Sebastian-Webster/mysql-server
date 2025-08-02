/* Copyright (c) 2025, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is designed to work with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have either included with
   the program or referenced in the documentation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#include "utils.h"

#include "sql/auth/auth_common.h"  // append_identifier_with_backtick
#include "sql/sql_const.h"
#include "sql_string.h"

namespace jdv {

/**
  Append an identifier to a string using backtick quotes.
  Pointer to String to use as buffer passed in.
 */
void append_identifier(std::string *sbuf, std::string_view id, String *bufp) {
  assert(sbuf != nullptr);
  assert(bufp != nullptr);
  append_identifier_with_backtick(bufp, id.data(), id.length());
  sbuf->append(bufp->ptr(), bufp->length());
}

/**
  Append an identifier to a string using backtick quotes using a String on the
  stack as buffer.
 */
void append_identifier(std::string *sbuf, std::string_view id) {
  StringBuffer<STRING_BUFFER_USUAL_SIZE> buf;
  jdv::append_identifier(sbuf, id, &buf);
}

}  // namespace jdv
