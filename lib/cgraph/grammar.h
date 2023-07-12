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

#ifndef YY_AAG_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_CGRAPH_GRAMMAR_H_INCLUDED
# define YY_AAG_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_CGRAPH_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef AAGDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define AAGDEBUG 1
#  else
#   define AAGDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define AAGDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined AAGDEBUG */
#if AAGDEBUG
extern int aagdebug;
#endif

/* Token kinds.  */
#ifndef AAGTOKENTYPE
# define AAGTOKENTYPE
  enum aagtokentype
  {
    AAGEMPTY = -2,
    AAGEOF = 0,                    /* "end of file"  */
    AAGerror = 256,                /* error  */
    AAGUNDEF = 257,                /* "invalid token"  */
    T_graph = 258,                 /* T_graph  */
    T_node = 259,                  /* T_node  */
    T_edge = 260,                  /* T_edge  */
    T_digraph = 261,               /* T_digraph  */
    T_subgraph = 262,              /* T_subgraph  */
    T_strict = 263,                /* T_strict  */
    T_edgeop = 264,                /* T_edgeop  */
    T_list = 265,                  /* T_list  */
    T_attr = 266,                  /* T_attr  */
    T_atom = 267,                  /* T_atom  */
    T_qatom = 268                  /* T_qatom  */
  };
  typedef enum aagtokentype aagtoken_kind_t;
#endif

/* Value type.  */
#if ! defined AAGSTYPE && ! defined AAGSTYPE_IS_DECLARED
union AAGSTYPE
{
#line 87 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/cgraph/grammar.y"

			int				i;
			char			*str;
			struct Agnode_s	*n;

#line 91 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/cgraph/grammar.h"

};
typedef union AAGSTYPE AAGSTYPE;
# define AAGSTYPE_IS_TRIVIAL 1
# define AAGSTYPE_IS_DECLARED 1
#endif


extern AAGSTYPE aaglval;


int aagparse (void);


#endif /* !YY_AAG_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_CGRAPH_GRAMMAR_H_INCLUDED  */
