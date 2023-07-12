/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_HTML_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_COMMON_HTMLPARSE_H_INCLUDED
# define YY_HTML_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_COMMON_HTMLPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef HTMLDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HTMLDEBUG 1
#  else
#   define HTMLDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HTMLDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HTMLDEBUG */
#if HTMLDEBUG
extern int htmldebug;
#endif

/* Token kinds.  */
#ifndef HTMLTOKENTYPE
# define HTMLTOKENTYPE
  enum htmltokentype
  {
    HTMLEMPTY = -2,
    HTMLEOF = 0,                   /* "end of file"  */
    HTMLerror = 256,               /* error  */
    HTMLUNDEF = 257,               /* "invalid token"  */
    T_end_br = 258,                /* T_end_br  */
    T_end_img = 259,               /* T_end_img  */
    T_row = 260,                   /* T_row  */
    T_end_row = 261,               /* T_end_row  */
    T_html = 262,                  /* T_html  */
    T_end_html = 263,              /* T_end_html  */
    T_end_table = 264,             /* T_end_table  */
    T_end_cell = 265,              /* T_end_cell  */
    T_end_font = 266,              /* T_end_font  */
    T_string = 267,                /* T_string  */
    T_error = 268,                 /* T_error  */
    T_n_italic = 269,              /* T_n_italic  */
    T_n_bold = 270,                /* T_n_bold  */
    T_n_underline = 271,           /* T_n_underline  */
    T_n_overline = 272,            /* T_n_overline  */
    T_n_sup = 273,                 /* T_n_sup  */
    T_n_sub = 274,                 /* T_n_sub  */
    T_n_s = 275,                   /* T_n_s  */
    T_HR = 276,                    /* T_HR  */
    T_hr = 277,                    /* T_hr  */
    T_end_hr = 278,                /* T_end_hr  */
    T_VR = 279,                    /* T_VR  */
    T_vr = 280,                    /* T_vr  */
    T_end_vr = 281,                /* T_end_vr  */
    T_BR = 282,                    /* T_BR  */
    T_br = 283,                    /* T_br  */
    T_IMG = 284,                   /* T_IMG  */
    T_img = 285,                   /* T_img  */
    T_table = 286,                 /* T_table  */
    T_cell = 287,                  /* T_cell  */
    T_font = 288,                  /* T_font  */
    T_italic = 289,                /* T_italic  */
    T_bold = 290,                  /* T_bold  */
    T_underline = 291,             /* T_underline  */
    T_overline = 292,              /* T_overline  */
    T_sup = 293,                   /* T_sup  */
    T_sub = 294,                   /* T_sub  */
    T_s = 295                      /* T_s  */
  };
  typedef enum htmltokentype htmltoken_kind_t;
#endif

/* Value type.  */
#if ! defined HTMLSTYPE && ! defined HTMLSTYPE_IS_DECLARED
union HTMLSTYPE
{
#line 405 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/common/htmlparse.y"

  int    i;
  htmltxt_t*  txt;
  htmlcell_t*  cell;
  htmltbl_t*   tbl;
  textfont_t*  font;
  htmlimg_t*   img;
  pitem*       p;

#line 122 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/common/htmlparse.h"

};
typedef union HTMLSTYPE HTMLSTYPE;
# define HTMLSTYPE_IS_TRIVIAL 1
# define HTMLSTYPE_IS_DECLARED 1
#endif


extern HTMLSTYPE htmllval;


int htmlparse (void);


#endif /* !YY_HTML_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_COMMON_HTMLPARSE_H_INCLUDED  */
