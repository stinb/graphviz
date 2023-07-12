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

#ifndef YY_EX_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_EXPR_EXPARSE_H_INCLUDED
# define YY_EX_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_EXPR_EXPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef EX_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define EX_DEBUG 1
#  else
#   define EX_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define EX_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined EX_DEBUG */
#if EX_DEBUG
extern int ex_debug;
#endif

/* Token kinds.  */
#ifndef EX_TOKENTYPE
# define EX_TOKENTYPE
  enum ex_tokentype
  {
    EX_EMPTY = -2,
    EX_EOF = 0,                    /* "end of file"  */
    EX_error = 256,                /* error  */
    EX_UNDEF = 257,                /* "invalid token"  */
    MINTOKEN = 258,                /* MINTOKEN  */
    INTEGER = 259,                 /* INTEGER  */
    UNSIGNED = 260,                /* UNSIGNED  */
    CHARACTER = 261,               /* CHARACTER  */
    FLOATING = 262,                /* FLOATING  */
    STRING = 263,                  /* STRING  */
    VOIDTYPE = 264,                /* VOIDTYPE  */
    STATIC = 265,                  /* STATIC  */
    ADDRESS = 266,                 /* ADDRESS  */
    ARRAY = 267,                   /* ARRAY  */
    BREAK = 268,                   /* BREAK  */
    CALL = 269,                    /* CALL  */
    CASE = 270,                    /* CASE  */
    CONSTANT = 271,                /* CONSTANT  */
    CONTINUE = 272,                /* CONTINUE  */
    DECLARE = 273,                 /* DECLARE  */
    DEFAULT = 274,                 /* DEFAULT  */
    DYNAMIC = 275,                 /* DYNAMIC  */
    ELSE = 276,                    /* ELSE  */
    EXIT = 277,                    /* EXIT  */
    FOR = 278,                     /* FOR  */
    FUNCTION = 279,                /* FUNCTION  */
    GSUB = 280,                    /* GSUB  */
    ITERATE = 281,                 /* ITERATE  */
    ITERATER = 282,                /* ITERATER  */
    ID = 283,                      /* ID  */
    IF = 284,                      /* IF  */
    LABEL = 285,                   /* LABEL  */
    MEMBER = 286,                  /* MEMBER  */
    NAME = 287,                    /* NAME  */
    POS = 288,                     /* POS  */
    PRAGMA = 289,                  /* PRAGMA  */
    PRE = 290,                     /* PRE  */
    PRINT = 291,                   /* PRINT  */
    PRINTF = 292,                  /* PRINTF  */
    PROCEDURE = 293,               /* PROCEDURE  */
    QUERY = 294,                   /* QUERY  */
    RAND = 295,                    /* RAND  */
    RETURN = 296,                  /* RETURN  */
    SCANF = 297,                   /* SCANF  */
    SPLIT = 298,                   /* SPLIT  */
    SPRINTF = 299,                 /* SPRINTF  */
    SRAND = 300,                   /* SRAND  */
    SSCANF = 301,                  /* SSCANF  */
    SUB = 302,                     /* SUB  */
    SUBSTR = 303,                  /* SUBSTR  */
    SWITCH = 304,                  /* SWITCH  */
    TOKENS = 305,                  /* TOKENS  */
    UNSET = 306,                   /* UNSET  */
    WHILE = 307,                   /* WHILE  */
    F2I = 308,                     /* F2I  */
    F2S = 309,                     /* F2S  */
    I2F = 310,                     /* I2F  */
    I2S = 311,                     /* I2S  */
    S2B = 312,                     /* S2B  */
    S2F = 313,                     /* S2F  */
    S2I = 314,                     /* S2I  */
    F2X = 315,                     /* F2X  */
    I2X = 316,                     /* I2X  */
    S2X = 317,                     /* S2X  */
    X2F = 318,                     /* X2F  */
    X2I = 319,                     /* X2I  */
    X2S = 320,                     /* X2S  */
    X2X = 321,                     /* X2X  */
    XPRINT = 322,                  /* XPRINT  */
    OR = 323,                      /* OR  */
    AND = 324,                     /* AND  */
    EQ = 325,                      /* EQ  */
    NE = 326,                      /* NE  */
    LE = 327,                      /* LE  */
    GE = 328,                      /* GE  */
    LSH = 329,                     /* LSH  */
    RSH = 330,                     /* RSH  */
    IN_OP = 331,                   /* IN_OP  */
    UNARY = 332,                   /* UNARY  */
    INC = 333,                     /* INC  */
    DEC = 334,                     /* DEC  */
    CAST = 335,                    /* CAST  */
    MAXTOKEN = 336                 /* MAXTOKEN  */
  };
  typedef enum ex_tokentype ex_token_kind_t;
#endif
/* Token kinds.  */
#define EX_EMPTY -2
#define EX_EOF 0
#define EX_error 256
#define EX_UNDEF 257
#define MINTOKEN 258
#define INTEGER 259
#define UNSIGNED 260
#define CHARACTER 261
#define FLOATING 262
#define STRING 263
#define VOIDTYPE 264
#define STATIC 265
#define ADDRESS 266
#define ARRAY 267
#define BREAK 268
#define CALL 269
#define CASE 270
#define CONSTANT 271
#define CONTINUE 272
#define DECLARE 273
#define DEFAULT 274
#define DYNAMIC 275
#define ELSE 276
#define EXIT 277
#define FOR 278
#define FUNCTION 279
#define GSUB 280
#define ITERATE 281
#define ITERATER 282
#define ID 283
#define IF 284
#define LABEL 285
#define MEMBER 286
#define NAME 287
#define POS 288
#define PRAGMA 289
#define PRE 290
#define PRINT 291
#define PRINTF 292
#define PROCEDURE 293
#define QUERY 294
#define RAND 295
#define RETURN 296
#define SCANF 297
#define SPLIT 298
#define SPRINTF 299
#define SRAND 300
#define SSCANF 301
#define SUB 302
#define SUBSTR 303
#define SWITCH 304
#define TOKENS 305
#define UNSET 306
#define WHILE 307
#define F2I 308
#define F2S 309
#define I2F 310
#define I2S 311
#define S2B 312
#define S2F 313
#define S2I 314
#define F2X 315
#define I2X 316
#define S2X 317
#define X2F 318
#define X2I 319
#define X2S 320
#define X2X 321
#define XPRINT 322
#define OR 323
#define AND 324
#define EQ 325
#define NE 326
#define LE 327
#define GE 328
#define LSH 329
#define RSH 330
#define IN_OP 331
#define UNARY 332
#define INC 333
#define DEC 334
#define CAST 335
#define MAXTOKEN 336

/* Value type.  */
#if ! defined EX_STYPE && ! defined EX_STYPE_IS_DECLARED
union EX_STYPE
{
#line 47 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"

	struct Exnode_s*expr;
	double		floating;
	struct Exref_s*	reference;
	struct Exid_s*	id;
	Sflong_t	integer;
	int		op;
	char*		string;

#line 247 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.h"

};
typedef union EX_STYPE EX_STYPE;
# define EX_STYPE_IS_TRIVIAL 1
# define EX_STYPE_IS_DECLARED 1
#endif


extern EX_STYPE ex_lval;

#if !defined ex_error && !defined EX_ERROR_IS_DECLARED
void ex_error (const char *msg);
#endif
#if !defined ex_lex && !defined EX_LEX_IS_DECLARED
int ex_lex (void);
#endif

int ex_parse (void);


#endif /* !YY_EX_USERS_JASON_SOURCES_STI_BUILD_RELEASE_SRC_LIB_GRAPHVIZ_GRAPHVIZ_LIB_EXPR_EXPARSE_H_INCLUDED  */
