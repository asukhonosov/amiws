/* Generated by re2c 0.16 */
#line 1 "src/lib/amipack_parse.re"
/**
 * amiws -- Library with functions for read/create AMI packets
 * Copyright (C) 2016, Stas Kobzar <staskobzar@modulis.ca>
 *
 * This file is part of amiws.
 *
 * amiws is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * amiws is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with amiws.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file amipack_parse.c
 * @brief AMI (Asterisk Management Interface) packet parser.
 *
 * @author Stas Kobzar <stas.kobzar@modulis.ca>
 */

#include <stdio.h>
#include <string.h>
#include "amipack.h"

/**
 * Commands to run when known header parsed.
 * @param name    Header type
 */
#define SET_HEADER(name)  len = cur - tok; \
                          hdr_name = strdup(name); \
                          goto yyc_key;

/**
 * Commands to run on Command AMI response header.
 * @param offset  Header name offset
 * @param name    Header type
 */
#define CMD_HEADER(offset, name) len = cur - tok - offset; tok += offset; \
                          while(*tok == ' ') { tok++; len--; } \
                          len -= 2; \
                          char *val = strndup(tok, len); \
                          amipack_append (pack, strdup(name), strlen(name), val, len); \
                          tok = cur; goto yyc_command;

// introducing types:re2c for AMI packet
/*! re2c parcing conditions. */
enum yycond_pack {
  yyckey,
  yycvalue,
  yyccommand,
};

AMIPacket *amiparse_pack (const char *pack_str)
{
  AMIPacket *pack = amipack_init ();
  const char *marker = pack_str;
  const char *cur    = marker;
  const char *ctxmarker;
  int c = yyckey;
  int len = 0;

  const char *tok = marker;
  char *hdr_name;


#line 76 "src/lib/amipack_parse.c"
{
	unsigned char yych;
	unsigned int yyaccept = 0;
	switch (c) {
	case yyckey: goto yyc_key;
	case yycvalue: goto yyc_value;
	case yyccommand: goto yyc_command;
	}
/* *********************************** */
yyc_command:
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy5;
	case '-':	goto yy7;
	case 'A':
	case 'a':	goto yy8;
	case 'M':
	case 'm':	goto yy9;
	case 'O':
	case 'o':	goto yy10;
	case 'P':
	case 'p':	goto yy11;
	default:	goto yy3;
	}
yy3:
	yyaccept = 0;
	yych = *(marker = ++cur);
	goto yy13;
yy4:
#line 96 "src/lib/amipack_parse.re"
	{
              if (hdr_name) free (hdr_name);
              amipack_destroy (pack);
              return NULL;
            }
#line 112 "src/lib/amipack_parse.c"
yy5:
	++cur;
yy6:
#line 152 "src/lib/amipack_parse.re"
	{ goto yyc_command; }
#line 118 "src/lib/amipack_parse.c"
yy7:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case '-':	goto yy14;
	default:	goto yy13;
	}
yy8:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'C':
	case 'c':	goto yy15;
	default:	goto yy13;
	}
yy9:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'E':
	case 'e':	goto yy16;
	default:	goto yy13;
	}
yy10:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'U':
	case 'u':	goto yy17;
	default:	goto yy13;
	}
yy11:
	yyaccept = 0;
	yych = *(marker = ++cur);
	switch (yych) {
	case 'R':
	case 'r':	goto yy18;
	default:	goto yy13;
	}
yy12:
	++cur;
	yych = *cur;
yy13:
	switch (yych) {
	case '\n':	goto yy5;
	default:	goto yy12;
	}
yy14:
	yych = *++cur;
	switch (yych) {
	case 'E':	goto yy19;
	default:	goto yy13;
	}
yy15:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy20;
	default:	goto yy13;
	}
yy16:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy21;
	default:	goto yy13;
	}
yy17:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy22;
	default:	goto yy13;
	}
yy18:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy23;
	default:	goto yy13;
	}
yy19:
	yych = *++cur;
	switch (yych) {
	case 'N':	goto yy24;
	default:	goto yy13;
	}
yy20:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy25;
	default:	goto yy13;
	}
yy21:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy26;
	default:	goto yy13;
	}
yy22:
	yych = *++cur;
	switch (yych) {
	case 'P':
	case 'p':	goto yy27;
	default:	goto yy13;
	}
yy23:
	yych = *++cur;
	switch (yych) {
	case 'V':
	case 'v':	goto yy28;
	default:	goto yy13;
	}
yy24:
	yych = *++cur;
	switch (yych) {
	case 'D':	goto yy29;
	default:	goto yy13;
	}
yy25:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy30;
	default:	goto yy13;
	}
yy26:
	yych = *++cur;
	switch (yych) {
	case 'A':
	case 'a':	goto yy31;
	default:	goto yy13;
	}
yy27:
	yych = *++cur;
	switch (yych) {
	case 'U':
	case 'u':	goto yy32;
	default:	goto yy13;
	}
yy28:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy33;
	default:	goto yy13;
	}
yy29:
	yych = *++cur;
	switch (yych) {
	case ' ':	goto yy34;
	default:	goto yy13;
	}
yy30:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy35;
	default:	goto yy13;
	}
yy31:
	yych = *++cur;
	switch (yych) {
	case 'G':
	case 'g':	goto yy36;
	default:	goto yy13;
	}
yy32:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy37;
	default:	goto yy13;
	}
yy33:
	yych = *++cur;
	switch (yych) {
	case 'L':
	case 'l':	goto yy38;
	default:	goto yy13;
	}
yy34:
	yych = *++cur;
	switch (yych) {
	case 'C':	goto yy39;
	default:	goto yy13;
	}
yy35:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy40;
	default:	goto yy13;
	}
yy36:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy41;
	default:	goto yy13;
	}
yy37:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy42;
	default:	goto yy13;
	}
yy38:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy44;
	default:	goto yy13;
	}
yy39:
	yych = *++cur;
	switch (yych) {
	case 'O':	goto yy45;
	default:	goto yy13;
	}
yy40:
	yych = *++cur;
	switch (yych) {
	case 'D':
	case 'd':	goto yy46;
	default:	goto yy13;
	}
yy41:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy47;
	default:	goto yy13;
	}
yy42:
	yyaccept = 1;
	yych = *(marker = ++cur);
	switch (yych) {
	case ' ':	goto yy49;
	default:	goto yy13;
	}
yy43:
#line 151 "src/lib/amipack_parse.re"
	{ tok = cur; goto yyc_command; }
#line 364 "src/lib/amipack_parse.c"
yy44:
	yych = *++cur;
	switch (yych) {
	case 'G':
	case 'g':	goto yy50;
	default:	goto yy13;
	}
yy45:
	yych = *++cur;
	switch (yych) {
	case 'M':	goto yy51;
	default:	goto yy13;
	}
yy46:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy52;
	default:	goto yy13;
	}
yy47:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy5;
	case '\r':	goto yy54;
	default:	goto yy47;
	}
yy49:
	yyaccept = 1;
	yych = *(marker = ++cur);
	goto yy13;
yy50:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy56;
	default:	goto yy13;
	}
yy51:
	yych = *++cur;
	switch (yych) {
	case 'M':	goto yy57;
	default:	goto yy13;
	}
yy52:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy5;
	case '\r':	goto yy58;
	default:	goto yy52;
	}
yy54:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy60;
	case '\r':	goto yy54;
	default:	goto yy47;
	}
yy56:
	yych = *++cur;
	switch (yych) {
	case ':':	goto yy62;
	default:	goto yy13;
	}
yy57:
	yych = *++cur;
	switch (yych) {
	case 'A':	goto yy64;
	default:	goto yy13;
	}
yy58:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy65;
	case '\r':	goto yy58;
	default:	goto yy52;
	}
yy60:
	++cur;
#line 150 "src/lib/amipack_parse.re"
	{ CMD_HEADER(8, "Message"); }
#line 449 "src/lib/amipack_parse.c"
yy62:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy5;
	case '\r':	goto yy67;
	default:	goto yy62;
	}
yy64:
	yych = *++cur;
	switch (yych) {
	case 'N':	goto yy69;
	default:	goto yy13;
	}
yy65:
	++cur;
#line 149 "src/lib/amipack_parse.re"
	{ CMD_HEADER(9, "ActionID"); }
#line 468 "src/lib/amipack_parse.c"
yy67:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy70;
	case '\r':	goto yy67;
	default:	goto yy62;
	}
yy69:
	yych = *++cur;
	switch (yych) {
	case 'D':	goto yy72;
	default:	goto yy13;
	}
yy70:
	++cur;
#line 148 "src/lib/amipack_parse.re"
	{ CMD_HEADER(10, "Privilege"); }
#line 487 "src/lib/amipack_parse.c"
yy72:
	yych = *++cur;
	switch (yych) {
	case '-':	goto yy73;
	default:	goto yy13;
	}
yy73:
	yych = *++cur;
	switch (yych) {
	case '-':	goto yy74;
	default:	goto yy13;
	}
yy74:
	yych = *++cur;
	switch (yych) {
	case '\r':	goto yy75;
	default:	goto yy13;
	}
yy75:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy76;
	default:	goto yy12;
	}
yy76:
	yyaccept = 2;
	yych = *(marker = ++cur);
	switch (yych) {
	case '\r':	goto yy77;
	default:	goto yy6;
	}
yy77:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy79;
	default:	goto yy78;
	}
yy78:
	cur = marker;
	switch (yyaccept) {
	case 0: 	goto yy4;
	case 1: 	goto yy43;
	default:	goto yy6;
	}
yy79:
	++cur;
#line 153 "src/lib/amipack_parse.re"
	{
              len = cur - tok - 19; // output minus command end tag
              char *val = strndup(tok, len);
              amipack_append (pack, strdup("Output"), 6, val, len);
              goto done;
            }
#line 541 "src/lib/amipack_parse.c"
/* *********************************** */
yyc_key:
	yych = *cur;
	switch (yych) {
	case '\r':	goto yy86;
	case ' ':	goto yy87;
	case ':':	goto yy89;
	case 'A':
	case 'a':	goto yy92;
	case 'E':
	case 'e':	goto yy93;
	case 'R':
	case 'r':	goto yy94;
	default:	goto yy83;
	}
yy83:
	++cur;
	yych = *cur;
yy84:
	switch (yych) {
	case ' ':
	case ':':	goto yy85;
	default:	goto yy83;
	}
yy85:
#line 134 "src/lib/amipack_parse.re"
	{
              len = cur - tok;
              hdr_name = strndup(tok, len);
              goto yyc_key;
            }
#line 573 "src/lib/amipack_parse.c"
yy86:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy95;
	default:	goto yy84;
	}
yy87:
	++cur;
#line 96 "src/lib/amipack_parse.re"
	{
              if (hdr_name) free (hdr_name);
              amipack_destroy (pack);
              return NULL;
            }
#line 588 "src/lib/amipack_parse.c"
yy89:
	yyaccept = 0;
	marker = ++cur;
	yych = *cur;
	switch (yych) {
	case '\r':	goto yy96;
	case ' ':	goto yy89;
	default:	goto yy91;
	}
yy91:
#line 103 "src/lib/amipack_parse.re"
	{ tok = cur; goto yyc_value; }
#line 601 "src/lib/amipack_parse.c"
yy92:
	yych = *++cur;
	switch (yych) {
	case 'C':
	case 'c':	goto yy98;
	default:	goto yy84;
	}
yy93:
	yych = *++cur;
	switch (yych) {
	case 'V':
	case 'v':	goto yy99;
	default:	goto yy84;
	}
yy94:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy100;
	default:	goto yy84;
	}
yy95:
	yych = *++cur;
	switch (yych) {
	case '\r':	goto yy101;
	default:	goto yy84;
	}
yy96:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy102;
	default:	goto yy97;
	}
yy97:
	cur = marker;
	if (yyaccept == 0) {
		goto yy91;
	} else {
		goto yy125;
	}
yy98:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy103;
	default:	goto yy84;
	}
yy99:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy104;
	default:	goto yy84;
	}
yy100:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy105;
	default:	goto yy84;
	}
yy101:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy106;
	default:	goto yy84;
	}
yy102:
	yych = *++cur;
	ctxmarker = cur;
	switch (yych) {
	case '\r':	goto yy108;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy109;
	default:	goto yy97;
	}
yy103:
	yych = *++cur;
	switch (yych) {
	case 'I':
	case 'i':	goto yy111;
	default:	goto yy84;
	}
yy104:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy112;
	default:	goto yy84;
	}
yy105:
	yych = *++cur;
	switch (yych) {
	case 'P':
	case 'p':	goto yy113;
	default:	goto yy84;
	}
yy106:
	++cur;
	switch ((yych = *cur)) {
	case ' ':
	case ':':	goto yy107;
	default:	goto yy83;
	}
yy107:
#line 101 "src/lib/amipack_parse.re"
	{ goto done; }
#line 759 "src/lib/amipack_parse.c"
yy108:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy114;
	default:	goto yy97;
	}
yy109:
	++cur;
	cur = ctxmarker;
#line 104 "src/lib/amipack_parse.re"
	{
              tok = cur;
              amipack_append(pack, hdr_name, strlen(hdr_name), strdup(""), 0);
              goto yyc_key;
            }
#line 775 "src/lib/amipack_parse.c"
yy111:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy116;
	default:	goto yy84;
	}
yy112:
	yych = *++cur;
	switch (yych) {
	case 'T':
	case 't':	goto yy117;
	default:	goto yy84;
	}
yy113:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy119;
	default:	goto yy84;
	}
yy114:
	++cur;
#line 109 "src/lib/amipack_parse.re"
	{
              tok = cur;
              amipack_append(pack, hdr_name, strlen(hdr_name), strdup(""), 0);
              goto done;
            }
#line 805 "src/lib/amipack_parse.c"
yy116:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy120;
	default:	goto yy84;
	}
yy117:
	++cur;
	switch ((yych = *cur)) {
	case ' ':
	case ':':	goto yy118;
	default:	goto yy83;
	}
yy118:
#line 129 "src/lib/amipack_parse.re"
	{
              amipack_type (pack, AMI_EVENT);
              SET_HEADER("Event");
            }
#line 826 "src/lib/amipack_parse.c"
yy119:
	yych = *++cur;
	switch (yych) {
	case 'N':
	case 'n':	goto yy122;
	default:	goto yy84;
	}
yy120:
	++cur;
	switch ((yych = *cur)) {
	case ' ':
	case ':':	goto yy121;
	default:	goto yy83;
	}
yy121:
#line 125 "src/lib/amipack_parse.re"
	{
              amipack_type (pack, AMI_ACTION);
              SET_HEADER("Action");
            }
#line 847 "src/lib/amipack_parse.c"
yy122:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy123;
	default:	goto yy84;
	}
yy123:
	yych = *++cur;
	switch (yych) {
	case 'E':
	case 'e':	goto yy124;
	default:	goto yy84;
	}
yy124:
	yyaccept = 1;
	yych = *(marker = ++cur);
	switch (yych) {
	case ' ':	goto yy125;
	case ':':	goto yy126;
	default:	goto yy83;
	}
yy125:
#line 121 "src/lib/amipack_parse.re"
	{
              amipack_type (pack, AMI_RESPONSE);
              SET_HEADER("Response");
            }
#line 876 "src/lib/amipack_parse.c"
yy126:
	++cur;
	yych = *cur;
	switch (yych) {
	case ' ':	goto yy126;
	case 'F':
	case 'f':	goto yy128;
	default:	goto yy97;
	}
yy128:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy129;
	default:	goto yy97;
	}
yy129:
	yych = *++cur;
	switch (yych) {
	case 'L':
	case 'l':	goto yy130;
	default:	goto yy97;
	}
yy130:
	yych = *++cur;
	switch (yych) {
	case 'L':
	case 'l':	goto yy131;
	default:	goto yy97;
	}
yy131:
	yych = *++cur;
	switch (yych) {
	case 'O':
	case 'o':	goto yy132;
	default:	goto yy97;
	}
yy132:
	yych = *++cur;
	switch (yych) {
	case 'W':
	case 'w':	goto yy133;
	default:	goto yy97;
	}
yy133:
	yych = *++cur;
	switch (yych) {
	case 'S':
	case 's':	goto yy134;
	default:	goto yy97;
	}
yy134:
	yych = *++cur;
	switch (yych) {
	case '\r':	goto yy135;
	default:	goto yy97;
	}
yy135:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy136;
	default:	goto yy97;
	}
yy136:
	++cur;
#line 114 "src/lib/amipack_parse.re"
	{
              len = cur - tok;
              tok = cur;
              amipack_type (pack, AMI_RESPONSE);
              amipack_append(pack, strdup("Response"), 8, strdup("Follows"), 7);
              goto yyc_command;
            }
#line 950 "src/lib/amipack_parse.c"
/* *********************************** */
yyc_value:
	yych = *cur;
	switch (yych) {
	case '\n':	goto yy143;
	case '\r':	goto yy145;
	default:	goto yy141;
	}
yy140:
#line 141 "src/lib/amipack_parse.re"
	{
              len = cur - tok;
              char *val = strndup(tok, len);
              amipack_append(pack, hdr_name, strlen(hdr_name), val, len);
              goto yyc_value;
            }
#line 967 "src/lib/amipack_parse.c"
yy141:
	++cur;
	yych = *cur;
	switch (yych) {
	case '\n':
	case '\r':	goto yy140;
	default:	goto yy141;
	}
yy143:
	++cur;
yy144:
#line 96 "src/lib/amipack_parse.re"
	{
              if (hdr_name) free (hdr_name);
              amipack_destroy (pack);
              return NULL;
            }
#line 985 "src/lib/amipack_parse.c"
yy145:
	yych = *(marker = ++cur);
	switch (yych) {
	case '\n':	goto yy146;
	default:	goto yy144;
	}
yy146:
	yych = *++cur;
	ctxmarker = cur;
	switch (yych) {
	case '\r':	goto yy148;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy149;
	default:	goto yy147;
	}
yy147:
	cur = marker;
	goto yy144;
yy148:
	yych = *++cur;
	switch (yych) {
	case '\n':	goto yy151;
	default:	goto yy147;
	}
yy149:
	++cur;
	cur = ctxmarker;
#line 140 "src/lib/amipack_parse.re"
	{ tok = cur; goto yyc_key; }
#line 1065 "src/lib/amipack_parse.c"
yy151:
	++cur;
#line 101 "src/lib/amipack_parse.re"
	{ goto done; }
#line 1070 "src/lib/amipack_parse.c"
}
#line 159 "src/lib/amipack_parse.re"


done:
  return pack;
}
