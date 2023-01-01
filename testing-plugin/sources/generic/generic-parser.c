/*
 * Copyright (c) 2022 Shikhar Vashistha
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */

#include "driver.h"
#include "cfg-parser.h"
#include "generic-grammar.h"

extern int generic_debug;

int generic_parse(CfgLexer *lexer, LogDriver **instance, gpointer arg);

static CfgLexerKeyword generic_keywords[] =
{
  { "generic", KW_GENERIC_PLUGIN},
};

CfgParser generic_parser =
{
#if SYSLOG_NG_ENABLE_DEBUG
  .debug_flag = &generic_debug,
#endif
  .name = "generic",
  .keywords = generic_keywords,
  .parse = (gint (*)(CfgLexer *, gpointer *, gpointer)) generic_parse,
  .cleanup = (void (*)(gpointer)) log_pipe_unref,
};

CFG_PARSER_IMPLEMENT_LEXER_BINDING(generic_, GENERIC_, LogDriver **)
