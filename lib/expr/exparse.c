/* A Bison parser, made by GNU Bison 3.8.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30800

/* Bison version string.  */
#define YYBISON_VERSION "3.8"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         EX_STYPE
/* Substitute the variable and function names.  */
#define yyparse         ex_parse
#define yylex           ex_lex
#define yyerror         ex_error
#define yydebug         ex_debug
#define yynerrs         ex_nerrs
#define yylval          ex_lval
#define yychar          ex_char

/* First part of user prologue.  */
#line 19 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"


/*
 * Glenn Fowler
 * AT&T Research
 *
 * expression library grammar and compiler
 */

#ifdef _WIN32
#include <config.h>

#ifdef GVDLL
#define _BLD_sfio 1
#endif
#endif

#include <assert.h>
#include <ctype.h>
#include <expr/exop.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ast/ast.h>


#line 106 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "exparse.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MINTOKEN = 3,                   /* MINTOKEN  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_UNSIGNED = 5,                   /* UNSIGNED  */
  YYSYMBOL_CHARACTER = 6,                  /* CHARACTER  */
  YYSYMBOL_FLOATING = 7,                   /* FLOATING  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_VOIDTYPE = 9,                   /* VOIDTYPE  */
  YYSYMBOL_STATIC = 10,                    /* STATIC  */
  YYSYMBOL_ADDRESS = 11,                   /* ADDRESS  */
  YYSYMBOL_ARRAY = 12,                     /* ARRAY  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CALL = 14,                      /* CALL  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_CONSTANT = 16,                  /* CONSTANT  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_DECLARE = 18,                   /* DECLARE  */
  YYSYMBOL_DEFAULT = 19,                   /* DEFAULT  */
  YYSYMBOL_DYNAMIC = 20,                   /* DYNAMIC  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_EXIT = 22,                      /* EXIT  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_FUNCTION = 24,                  /* FUNCTION  */
  YYSYMBOL_GSUB = 25,                      /* GSUB  */
  YYSYMBOL_ITERATE = 26,                   /* ITERATE  */
  YYSYMBOL_ITERATER = 27,                  /* ITERATER  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_LABEL = 30,                     /* LABEL  */
  YYSYMBOL_MEMBER = 31,                    /* MEMBER  */
  YYSYMBOL_NAME = 32,                      /* NAME  */
  YYSYMBOL_POS = 33,                       /* POS  */
  YYSYMBOL_PRAGMA = 34,                    /* PRAGMA  */
  YYSYMBOL_PRE = 35,                       /* PRE  */
  YYSYMBOL_PRINT = 36,                     /* PRINT  */
  YYSYMBOL_PRINTF = 37,                    /* PRINTF  */
  YYSYMBOL_PROCEDURE = 38,                 /* PROCEDURE  */
  YYSYMBOL_QUERY = 39,                     /* QUERY  */
  YYSYMBOL_RAND = 40,                      /* RAND  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_SCANF = 42,                     /* SCANF  */
  YYSYMBOL_SPLIT = 43,                     /* SPLIT  */
  YYSYMBOL_SPRINTF = 44,                   /* SPRINTF  */
  YYSYMBOL_SRAND = 45,                     /* SRAND  */
  YYSYMBOL_SSCANF = 46,                    /* SSCANF  */
  YYSYMBOL_SUB = 47,                       /* SUB  */
  YYSYMBOL_SUBSTR = 48,                    /* SUBSTR  */
  YYSYMBOL_SWITCH = 49,                    /* SWITCH  */
  YYSYMBOL_TOKENS = 50,                    /* TOKENS  */
  YYSYMBOL_UNSET = 51,                     /* UNSET  */
  YYSYMBOL_WHILE = 52,                     /* WHILE  */
  YYSYMBOL_F2I = 53,                       /* F2I  */
  YYSYMBOL_F2S = 54,                       /* F2S  */
  YYSYMBOL_I2F = 55,                       /* I2F  */
  YYSYMBOL_I2S = 56,                       /* I2S  */
  YYSYMBOL_S2B = 57,                       /* S2B  */
  YYSYMBOL_S2F = 58,                       /* S2F  */
  YYSYMBOL_S2I = 59,                       /* S2I  */
  YYSYMBOL_F2X = 60,                       /* F2X  */
  YYSYMBOL_I2X = 61,                       /* I2X  */
  YYSYMBOL_S2X = 62,                       /* S2X  */
  YYSYMBOL_X2F = 63,                       /* X2F  */
  YYSYMBOL_X2I = 64,                       /* X2I  */
  YYSYMBOL_X2S = 65,                       /* X2S  */
  YYSYMBOL_X2X = 66,                       /* X2X  */
  YYSYMBOL_XPRINT = 67,                    /* XPRINT  */
  YYSYMBOL_68_ = 68,                       /* ','  */
  YYSYMBOL_69_ = 69,                       /* '='  */
  YYSYMBOL_70_ = 70,                       /* '?'  */
  YYSYMBOL_71_ = 71,                       /* ':'  */
  YYSYMBOL_OR = 72,                        /* OR  */
  YYSYMBOL_AND = 73,                       /* AND  */
  YYSYMBOL_74_ = 74,                       /* '|'  */
  YYSYMBOL_75_ = 75,                       /* '^'  */
  YYSYMBOL_76_ = 76,                       /* '&'  */
  YYSYMBOL_EQ = 77,                        /* EQ  */
  YYSYMBOL_NE = 78,                        /* NE  */
  YYSYMBOL_79_ = 79,                       /* '<'  */
  YYSYMBOL_80_ = 80,                       /* '>'  */
  YYSYMBOL_LE = 81,                        /* LE  */
  YYSYMBOL_GE = 82,                        /* GE  */
  YYSYMBOL_LSH = 83,                       /* LSH  */
  YYSYMBOL_RSH = 84,                       /* RSH  */
  YYSYMBOL_85_ = 85,                       /* '+'  */
  YYSYMBOL_86_ = 86,                       /* '-'  */
  YYSYMBOL_IN_OP = 87,                     /* IN_OP  */
  YYSYMBOL_88_ = 88,                       /* '*'  */
  YYSYMBOL_89_ = 89,                       /* '/'  */
  YYSYMBOL_90_ = 90,                       /* '%'  */
  YYSYMBOL_91_ = 91,                       /* '!'  */
  YYSYMBOL_92_ = 92,                       /* '~'  */
  YYSYMBOL_93_ = 93,                       /* '#'  */
  YYSYMBOL_UNARY = 94,                     /* UNARY  */
  YYSYMBOL_INC = 95,                       /* INC  */
  YYSYMBOL_DEC = 96,                       /* DEC  */
  YYSYMBOL_CAST = 97,                      /* CAST  */
  YYSYMBOL_98_ = 98,                       /* '('  */
  YYSYMBOL_MAXTOKEN = 99,                  /* MAXTOKEN  */
  YYSYMBOL_100_ = 100,                     /* '{'  */
  YYSYMBOL_101_ = 101,                     /* '}'  */
  YYSYMBOL_102_ = 102,                     /* ';'  */
  YYSYMBOL_103_ = 103,                     /* ')'  */
  YYSYMBOL_104_ = 104,                     /* '['  */
  YYSYMBOL_105_ = 105,                     /* ']'  */
  YYSYMBOL_106_ = 106,                     /* '.'  */
  YYSYMBOL_YYACCEPT = 107,                 /* $accept  */
  YYSYMBOL_program = 108,                  /* program  */
  YYSYMBOL_action_list = 109,              /* action_list  */
  YYSYMBOL_action = 110,                   /* action  */
  YYSYMBOL_111_1 = 111,                    /* $@1  */
  YYSYMBOL_statement_list = 112,           /* statement_list  */
  YYSYMBOL_statement = 113,                /* statement  */
  YYSYMBOL_114_2 = 114,                    /* $@2  */
  YYSYMBOL_115_3 = 115,                    /* $@3  */
  YYSYMBOL_116_4 = 116,                    /* $@4  */
  YYSYMBOL_switch_list = 117,              /* switch_list  */
  YYSYMBOL_switch_item = 118,              /* switch_item  */
  YYSYMBOL_case_list = 119,                /* case_list  */
  YYSYMBOL_case_item = 120,                /* case_item  */
  YYSYMBOL_static = 121,                   /* static  */
  YYSYMBOL_dcl_list = 122,                 /* dcl_list  */
  YYSYMBOL_dcl_item = 123,                 /* dcl_item  */
  YYSYMBOL_124_5 = 124,                    /* $@5  */
  YYSYMBOL_dcl_name = 125,                 /* dcl_name  */
  YYSYMBOL_name = 126,                     /* name  */
  YYSYMBOL_else_opt = 127,                 /* else_opt  */
  YYSYMBOL_expr_opt = 128,                 /* expr_opt  */
  YYSYMBOL_expr = 129,                     /* expr  */
  YYSYMBOL_130_6 = 130,                    /* $@6  */
  YYSYMBOL_131_7 = 131,                    /* $@7  */
  YYSYMBOL_splitop = 132,                  /* splitop  */
  YYSYMBOL_constant = 133,                 /* constant  */
  YYSYMBOL_print = 134,                    /* print  */
  YYSYMBOL_scan = 135,                     /* scan  */
  YYSYMBOL_variable = 136,                 /* variable  */
  YYSYMBOL_array = 137,                    /* array  */
  YYSYMBOL_index = 138,                    /* index  */
  YYSYMBOL_args = 139,                     /* args  */
  YYSYMBOL_arg_list = 140,                 /* arg_list  */
  YYSYMBOL_formals = 141,                  /* formals  */
  YYSYMBOL_formal_list = 142,              /* formal_list  */
  YYSYMBOL_formal_item = 143,              /* formal_item  */
  YYSYMBOL_144_8 = 144,                    /* $@8  */
  YYSYMBOL_members = 145,                  /* members  */
  YYSYMBOL_member = 146,                   /* member  */
  YYSYMBOL_assign = 147,                   /* assign  */
  YYSYMBOL_initialize = 148,               /* initialize  */
  YYSYMBOL_149_9 = 149,                    /* $@9  */
  YYSYMBOL_150_10 = 150                    /* $@10  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 177 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"


#include <expr/exgram.h>

void ex_error(const char *message);


#line 298 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined EX_STYPE_IS_TRIVIAL && EX_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   336


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,     2,    93,     2,    90,    76,     2,
      98,   103,    88,    85,    68,    86,   106,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,   102,
      79,    69,    80,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   104,     2,   105,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    74,   101,    92,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    72,    73,    77,    78,    81,    82,    83,
      84,    87,    94,    95,    96,    97,    99
};

#if EX_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   187,   187,   208,   209,   212,   212,   252,   255,   270,
     274,   278,   278,   278,   283,   293,   306,   321,   334,   342,
     353,   363,   363,   374,   386,   390,   403,   432,   435,   466,
     467,   470,   489,   496,   499,   505,   506,   513,   513,   562,
     563,   564,   565,   568,   569,   573,   576,   583,   586,   589,
     593,   597,   650,   654,   658,   662,   666,   670,   674,   678,
     682,   686,   690,   694,   698,   702,   706,   710,   723,   727,
     737,   737,   737,   778,   798,   805,   809,   813,   817,   821,
     825,   829,   833,   837,   841,   845,   849,   855,   859,   863,
     869,   874,   878,   903,   939,   959,   967,   975,   986,   990,
     994,   997,   998,  1000,  1008,  1013,  1018,  1023,  1030,  1031,
    1032,  1035,  1036,  1039,  1043,  1063,  1076,  1079,  1083,  1097,
    1100,  1107,  1110,  1118,  1123,  1130,  1133,  1139,  1142,  1146,
    1157,  1157,  1170,  1173,  1186,  1207,  1211,  1217,  1220,  1227,
    1228,  1245,  1228
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if EX_DEBUG || 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MINTOKEN", "INTEGER",
  "UNSIGNED", "CHARACTER", "FLOATING", "STRING", "VOIDTYPE", "STATIC",
  "ADDRESS", "ARRAY", "BREAK", "CALL", "CASE", "CONSTANT", "CONTINUE",
  "DECLARE", "DEFAULT", "DYNAMIC", "ELSE", "EXIT", "FOR", "FUNCTION",
  "GSUB", "ITERATE", "ITERATER", "ID", "IF", "LABEL", "MEMBER", "NAME",
  "POS", "PRAGMA", "PRE", "PRINT", "PRINTF", "PROCEDURE", "QUERY", "RAND",
  "RETURN", "SCANF", "SPLIT", "SPRINTF", "SRAND", "SSCANF", "SUB",
  "SUBSTR", "SWITCH", "TOKENS", "UNSET", "WHILE", "F2I", "F2S", "I2F",
  "I2S", "S2B", "S2F", "S2I", "F2X", "I2X", "S2X", "X2F", "X2I", "X2S",
  "X2X", "XPRINT", "','", "'='", "'?'", "':'", "OR", "AND", "'|'", "'^'",
  "'&'", "EQ", "NE", "'<'", "'>'", "LE", "GE", "LSH", "RSH", "'+'", "'-'",
  "IN_OP", "'*'", "'/'", "'%'", "'!'", "'~'", "'#'", "UNARY", "INC", "DEC",
  "CAST", "'('", "MAXTOKEN", "'{'", "'}'", "';'", "')'", "'['", "']'",
  "'.'", "$accept", "program", "action_list", "action", "$@1",
  "statement_list", "statement", "$@2", "$@3", "$@4", "switch_list",
  "switch_item", "case_list", "case_item", "static", "dcl_list",
  "dcl_item", "$@5", "dcl_name", "name", "else_opt", "expr_opt", "expr",
  "$@6", "$@7", "splitop", "constant", "print", "scan", "variable",
  "array", "index", "args", "arg_list", "formals", "formal_list",
  "formal_item", "$@8", "members", "member", "assign", "initialize", "$@9",
  "$@10", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-144)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-127)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -144,     9,   200,  -144,  -144,  -144,  -144,  -144,  -144,   -89,
     691,  -144,   691,   -80,   -71,   -64,   -63,   -43,   -35,   -27,
     -11,  -144,    11,  -144,    16,  -144,    20,   691,  -144,  -144,
    -144,    23,  -144,    31,    39,    41,  -144,    56,    57,     1,
     691,   691,   691,   691,    79,     1,     1,   596,  -144,    92,
    -144,  -144,    49,   872,    58,  -144,    60,    61,   -37,   691,
      65,    66,   691,   -27,   691,   691,   691,   691,     1,   -12,
    -144,  -144,   691,   691,   691,    59,    68,    88,   691,   691,
     691,   140,   691,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,    72,   284,   299,   100,  -144,   158,  -144,   691,  -144,
     691,   691,   691,   691,   691,   691,   691,   691,   691,   691,
     691,   691,   691,   691,   691,   143,   691,   691,   691,   691,
     691,   691,   691,  -144,  -144,  -144,   916,    77,   109,  -144,
    -144,   185,  -144,   383,    83,   -56,    84,    85,    95,    93,
    -144,   482,    97,    98,  -144,  -144,  -144,   577,   106,   108,
     872,   -51,   672,   691,  -144,  -144,  -144,  -144,   916,   691,
     934,   951,   967,   982,   996,  1010,  1010,  1022,  1022,  1022,
    1022,   107,   107,    53,    53,  -144,  -144,  -144,  -144,   895,
     111,   112,   916,  -144,   691,  -144,  -144,   691,   497,  -144,
    -144,   497,    29,  -144,   497,  -144,  -144,  -144,  -144,  -144,
     116,   691,  -144,   497,  -144,  -144,    87,   849,   786,  -144,
    -144,   916,   124,  -144,  -144,  -144,   168,    90,   767,  -144,
     200,  -144,  -144,  -144,  -144,   -49,  -144,  -144,  -144,   -54,
     691,   497,  -144,  -144,  -144,    87,  -144,   126,   691,   691,
    -144,   128,  -144,    -7,  -144,   -16,   -44,   916,   815,   497,
     145,   162,  -144,  -144,    86,  -144,   129,  -144,  -144,  -144,
    -144,  -144,  -144,   183,  -144,   200,  -144,  -144,   238,  -144,
     174,  -144,   210,  -144,   -10,   176,   262,  -144,  -144,  -144,
     181,  -144,  -144,  -144,   398,  -144
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     3,     1,   105,   107,   104,   106,    34,     0,
      47,   103,    47,   119,     0,     0,     0,     0,     0,   132,
       0,   115,     0,   108,     0,   109,     0,    47,   111,   101,
     110,     0,   112,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     2,
       8,    11,     0,    48,     0,   100,     0,     0,   137,   121,
       0,     0,     0,   132,     0,    47,   121,   121,     0,     0,
     113,   133,     0,   121,   121,     0,     0,     0,   121,   121,
       0,     0,     0,    78,    77,    76,    73,    75,    74,    95,
      98,     0,     0,    33,     0,     4,     0,    10,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,   121,     0,    96,    99,    94,   123,     0,   122,    23,
      24,     0,   114,     0,     0,   137,     0,     0,     0,   135,
     136,     0,     0,     0,    87,    25,    88,     0,     0,     0,
      21,     0,     0,     0,    49,     9,     5,    12,    69,     0,
      68,    67,    64,    65,    63,    61,    62,    51,    58,    59,
      60,    56,    57,    66,    52,    97,    53,    54,    55,     0,
       0,     0,   138,    79,     0,   120,    86,    47,    33,    80,
      81,    33,     0,   134,    33,    91,    90,    89,    82,    83,
       0,     0,    18,    33,    50,     7,     0,     0,     0,    92,
      93,   124,     0,    15,    17,   135,    45,     0,     0,    20,
       6,    40,    42,    41,    39,     0,    35,    37,    71,   119,
      47,    33,    14,    26,    19,     0,    13,   116,     0,     0,
      84,     0,    46,     0,    36,     0,   137,    72,     0,    33,
       0,     0,    22,    27,     7,    29,     0,   117,   140,   139,
      38,    85,    16,     0,    32,    28,    30,   118,   125,    31,
     130,   141,   127,   128,     0,     0,     0,    44,    43,   131,
       0,   130,   129,     7,    33,   142
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,   -48,  -143,  -144,  -144,  -144,
    -144,  -144,  -144,    28,  -144,  -144,    48,  -144,  -144,  -144,
    -144,    -9,   -36,  -144,  -144,  -144,    34,  -144,  -144,   101,
    -144,  -144,    24,  -144,  -144,  -144,    12,  -144,   224,   150,
      51,  -144,  -144,  -144
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    49,    95,   205,     2,    50,    96,   206,   200,
     243,   253,   254,   255,    51,   225,   226,   237,   227,   279,
     232,    52,    53,   159,   238,    54,    55,    56,    57,    58,
     246,    63,   127,   128,   271,   272,   273,   274,    70,    71,
     125,   260,   268,   275
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    60,   256,    61,    84,    85,    86,    87,   250,     3,
     277,    92,   251,   122,   239,    59,   139,   201,    76,   235,
     140,    13,   278,   126,    62,   122,   131,    64,   133,    19,
     126,   126,   122,    21,    65,    66,   141,   126,   126,   123,
     124,   147,   126,   126,   150,   213,   152,   188,   214,   240,
      62,   216,   202,   236,   258,    67,   134,   215,   123,   124,
     219,   140,   158,    68,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    69,
     176,   177,   178,   179,   126,   126,   182,    72,   242,   257,
     136,   137,     4,     5,   252,     6,     7,   142,   143,    88,
       9,   250,   148,   149,    11,   251,   262,   221,    13,    73,
      14,   222,    16,    17,    74,   223,    19,   204,    75,   224,
      21,    77,    94,   207,    22,    23,    24,    25,    26,    78,
      28,    29,    30,    31,    32,    33,    34,    79,    36,    80,
      83,   116,   117,   118,   180,   181,    89,    90,   211,     4,
       5,    97,     6,     7,    81,    82,   119,   220,   120,   121,
     151,    11,   144,   175,    39,   218,   135,   129,   130,   138,
     145,   156,   158,    40,    41,   153,   157,   184,   212,    42,
      43,    44,   183,    45,    46,   187,    47,   189,   190,   231,
     233,   146,   113,   114,   115,   116,   117,   118,   191,   192,
     195,   196,   247,   248,     4,     5,   265,     6,     7,   198,
       8,   199,     9,    10,   209,   210,    11,    12,   -33,   217,
      13,   241,    14,    15,    16,    17,   230,    18,    19,    20,
     245,   249,    21,   264,   267,   284,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    98,   269,    99,   270,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    39,  -126,   276,   280,
     281,   283,   266,   244,   263,    40,    41,   132,   282,   193,
     185,    42,    43,    44,     0,    45,    46,   259,    47,     0,
      48,     0,   -47,     4,     5,     0,     6,     7,     0,     8,
       0,     9,    10,     0,     0,    11,    12,     0,     0,    13,
       0,    14,    15,    16,    17,     0,    18,    19,    20,     0,
       0,    21,     0,     0,     0,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    98,     0,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    41,     0,   154,     0,     0,
      42,    43,    44,     0,    45,    46,     0,    47,     0,    48,
     155,   -47,     4,     5,     0,     6,     7,     0,     8,     0,
       9,    10,     0,     0,    11,    12,     0,     0,    13,     0,
      14,    15,    16,    17,     0,    18,    19,    20,     0,     0,
      21,     0,     0,     0,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    98,     0,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    39,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,   186,     0,     0,    42,
      43,    44,     0,    45,    46,     0,    47,     0,    48,   285,
     -47,     4,     5,     0,     6,     7,     0,     8,     0,     9,
      10,     0,     0,    11,    12,     0,     0,    13,     0,    14,
      15,    16,    17,     0,    18,    19,    20,     0,     0,    21,
       0,     0,     0,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      98,     0,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    41,     0,   194,     0,     0,    42,    43,
      44,     0,    45,    46,     0,    47,     0,    48,     0,   -47,
       4,     5,     0,     6,     7,     0,     0,     0,     9,     0,
       0,     0,    11,     0,    91,     0,    13,     0,    14,     0,
      16,    17,     0,     0,    19,     0,     0,     0,    21,     0,
       0,     0,    22,    23,    24,    25,    26,     0,    28,    29,
      30,    31,    32,    33,    34,    98,    36,    99,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
     197,    40,    41,     0,     0,     0,     0,    42,    43,    44,
       0,    45,    46,     0,    47,     4,     5,     0,     6,     7,
       0,     0,     0,     9,     0,     0,     0,    11,     0,     0,
       0,    13,     0,    14,     0,    16,    17,     0,     0,    19,
       0,     0,     0,    21,     0,     0,     0,    22,    23,    24,
      25,    26,     0,    28,    29,    30,    31,    32,    33,    34,
      98,    36,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,     0,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,   203,    40,    41,     0,     0,
       0,     0,    42,    43,    44,     0,    45,    46,     0,    47,
       4,     5,     0,     6,     7,     0,     0,     0,     9,     0,
       0,     0,    11,     0,     0,     0,   229,     0,    14,     0,
      16,    17,     0,     0,    19,     0,     0,     0,    21,     0,
       0,     0,    22,    23,    24,    25,    26,     0,    28,    29,
      30,    31,    32,    33,    34,    98,    36,    99,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
     234,    40,    41,     0,     0,     0,     0,    42,    43,    44,
       0,    45,    46,    98,    47,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,   261,    99,
     228,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      98,     0,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   208,     0,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,  -127,  -127,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,  -127,  -127,  -127,  -127,   111,   112,   113,   114,   115,
     116,   117,   118
};

static const yytype_int16 yycheck[] =
{
      48,    10,    18,    12,    40,    41,    42,    43,    15,     0,
      20,    47,    19,    69,    68,   104,    28,    68,    27,    68,
      32,    20,    32,    59,   104,    69,    62,    98,    64,    28,
      66,    67,    69,    32,    98,    98,    72,    73,    74,    95,
      96,    77,    78,    79,    80,   188,    82,   103,   191,   103,
     104,   194,   103,   102,    98,    98,    65,    28,    95,    96,
     203,    32,    98,    98,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   106,
     116,   117,   118,   119,   120,   121,   122,    98,   231,   105,
      66,    67,     4,     5,   101,     7,     8,    73,    74,    20,
      12,    15,    78,    79,    16,    19,   249,    20,    20,    98,
      22,    24,    24,    25,    98,    28,    28,   153,    98,    32,
      32,    98,    30,   159,    36,    37,    38,    39,    40,    98,
      42,    43,    44,    45,    46,    47,    48,    98,    50,    98,
      39,    88,    89,    90,   120,   121,    45,    46,   184,     4,
       5,   102,     7,     8,    98,    98,    98,   205,    98,    98,
      20,    16,   103,    20,    76,   201,    65,   102,   102,    68,
     102,    71,   208,    85,    86,   103,    18,    68,   187,    91,
      92,    93,   105,    95,    96,   102,    98,   103,   103,    21,
     100,   103,    85,    86,    87,    88,    89,    90,   103,   106,
     103,   103,   238,   239,     4,     5,   254,     7,     8,   103,
      10,   103,    12,    13,   103,   103,    16,    17,    18,   103,
      20,   230,    22,    23,    24,    25,   102,    27,    28,    29,
     104,   103,    32,    71,   105,   283,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    68,    71,    70,    18,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    76,   103,    68,   103,
      18,   100,   254,   235,   250,    85,    86,    63,   276,   139,
     105,    91,    92,    93,    -1,    95,    96,   246,    98,    -1,
     100,    -1,   102,     4,     5,    -1,     7,     8,    -1,    10,
      -1,    12,    13,    -1,    -1,    16,    17,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    -1,    27,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    68,    -1,    70,    -1,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,   103,    -1,    -1,
      91,    92,    93,    -1,    95,    96,    -1,    98,    -1,   100,
     101,   102,     4,     5,    -1,     7,     8,    -1,    10,    -1,
      12,    13,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,
      22,    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    68,    -1,    70,    -1,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,   103,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    -1,    98,    -1,   100,   101,
     102,     4,     5,    -1,     7,     8,    -1,    10,    -1,    12,
      13,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    -1,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      68,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,   103,    -1,    -1,    91,    92,
      93,    -1,    95,    96,    -1,    98,    -1,   100,    -1,   102,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    16,    -1,    18,    -1,    20,    -1,    22,    -1,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    68,    50,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    85,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      -1,    95,    96,    -1,    98,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    -1,    22,    -1,    24,    25,    -1,    -1,    28,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    42,    43,    44,    45,    46,    47,    48,
      68,    50,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    85,    86,    -1,    -1,
      -1,    -1,    91,    92,    93,    -1,    95,    96,    -1,    98,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,    -1,
      24,    25,    -1,    -1,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    42,    43,
      44,    45,    46,    47,    48,    68,    50,    70,    -1,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    85,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      -1,    95,    96,    68,    98,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,   103,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      68,    -1,    70,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    68,    -1,    70,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    70,    -1,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   108,   112,     0,     4,     5,     7,     8,    10,    12,
      13,    16,    17,    20,    22,    23,    24,    25,    27,    28,
      29,    32,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    76,
      85,    86,    91,    92,    93,    95,    96,    98,   100,   109,
     113,   121,   128,   129,   132,   133,   134,   135,   136,   104,
     128,   128,   104,   138,    98,    98,    98,    98,    98,   106,
     145,   146,    98,    98,    98,    98,   128,    98,    98,    98,
      98,    98,    98,   136,   129,   129,   129,   129,    20,   136,
     136,    18,   129,   112,    30,   110,   114,   102,    68,    70,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    98,
      98,    98,    69,    95,    96,   147,   129,   139,   140,   102,
     102,   129,   145,   129,   128,   136,   139,   139,   136,    28,
      32,   129,   139,   139,   103,   102,   103,   129,   139,   139,
     129,    20,   129,   103,   103,   101,    71,    18,   129,   130,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,    20,   129,   129,   129,   129,
     139,   139,   129,   105,    68,   105,   103,   102,   103,   103,
     103,   103,   106,   146,   103,   103,   103,   103,   103,   103,
     116,    68,   103,   103,   129,   111,   115,   129,    68,   103,
     103,   129,   128,   113,   113,    28,   113,   103,   129,   113,
     112,    20,    24,    28,    32,   122,   123,   125,    71,    20,
     102,    21,   127,   100,   103,    68,   102,   124,   131,    68,
     103,   128,   113,   117,   123,   104,   137,   129,   129,   103,
      15,    19,   101,   118,   119,   120,    18,   105,    98,   147,
     148,   103,   113,   133,    71,   112,   120,   105,   149,    71,
      18,   141,   142,   143,   144,   150,    68,    20,    32,   126,
     103,    18,   143,   100,   112,   101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   109,   109,   111,   110,   112,   112,   113,
     113,   114,   115,   113,   113,   113,   113,   113,   113,   113,
     113,   116,   113,   113,   113,   113,   117,   117,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   124,   123,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     130,   131,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   132,   132,   133,   133,   133,   133,   133,   134,   134,
     134,   135,   135,   136,   136,   136,   137,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   141,   142,   142,
     144,   143,   145,   145,   145,   146,   146,   147,   147,   148,
     149,   150,   148
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     4,     0,     2,     3,
       2,     0,     0,     6,     6,     5,     9,     5,     4,     6,
       5,     0,     8,     3,     3,     3,     0,     2,     2,     1,
       2,     3,     2,     0,     1,     1,     3,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     2,     0,     1,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     0,     7,     2,     2,     2,     2,     2,     2,     4,
       4,     4,     4,     4,     6,     8,     4,     3,     3,     4,
       4,     4,     4,     4,     2,     2,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     0,     2,     3,     0,
       3,     0,     1,     1,     3,     0,     1,     1,     1,     3,
       0,     3,     0,     1,     3,     2,     2,     0,     2,     1,
       0,     0,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = EX_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == EX_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use EX_error or EX_UNDEF. */
#define YYERRCODE EX_UNDEF


/* Enable debugging if requested.  */
#if EX_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !EX_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !EX_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = EX_EMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == EX_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= EX_EOF)
    {
      yychar = EX_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == EX_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = EX_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = EX_EMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list action_list  */
#line 188 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[-1].expr) && !(expr.program->disc->flags & EX_STRICT))
			{
				if (expr.program->main.value && !(expr.program->disc->flags & EX_RETAIN))
					exfreenode(expr.program, expr.program->main.value);
				if ((yyvsp[-1].expr)->op == S2B)
				{
					Exnode_t*	x;

					x = (yyvsp[-1].expr);
					(yyvsp[-1].expr) = x->data.operand.left;
					x->data.operand.left = 0;
					exfreenode(expr.program, x);
				}
				expr.program->main.lex = PROCEDURE;
				expr.program->main.value = exnewnode(expr.program, PROCEDURE, 1, (yyvsp[-1].expr)->type, NULL, (yyvsp[-1].expr));
			}
		}
#line 1639 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 5: /* $@1: %empty  */
#line 212 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                  {
				Dtdisc_t*	disc;

				if (expr.procedure)
					exerror("no nested function definitions");
				(yyvsp[-1].id)->lex = PROCEDURE;
				expr.procedure = (yyvsp[-1].id)->value = exnewnode(expr.program, PROCEDURE, 1, (yyvsp[-1].id)->type, NULL, NULL);
				expr.procedure->type = INTEGER;
				if (!(disc = calloc(1, sizeof(Dtdisc_t))))
					exnospace();
				disc->key = offsetof(Exid_t, name);
				if (expr.assigned && !streq((yyvsp[-1].id)->name, "begin"))
				{
					if (!(expr.procedure->data.procedure.frame = dtopen(disc, Dtset)) || !dtview(expr.procedure->data.procedure.frame, expr.program->symbols))
						exnospace();
					expr.program->symbols = expr.program->frame = expr.procedure->data.procedure.frame;
				}
			}
#line 1662 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 6: /* action: LABEL ':' $@1 statement_list  */
#line 230 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			expr.procedure = 0;
			if (expr.program->frame)
			{
				expr.program->symbols = expr.program->frame->view;
				dtview(expr.program->frame, NULL);
				expr.program->frame = 0;
			}
			if ((yyvsp[0].expr) && (yyvsp[0].expr)->op == S2B)
			{
				Exnode_t*	x;

				x = (yyvsp[0].expr);
				(yyvsp[0].expr) = x->data.operand.left;
				x->data.operand.left = 0;
				exfreenode(expr.program, x);
			}
			(yyvsp[-3].id)->value->data.operand.right = excast(expr.program, (yyvsp[0].expr), (yyvsp[-3].id)->type, NULL, 0);
		}
#line 1686 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 7: /* statement_list: %empty  */
#line 252 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
		}
#line 1694 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 256 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (!(yyvsp[-1].expr))
				(yyval.expr) = (yyvsp[0].expr);
			else if (!(yyvsp[0].expr))
				(yyval.expr) = (yyvsp[-1].expr);
			else if ((yyvsp[-1].expr)->op == CONSTANT)
			{
				exfreenode(expr.program, (yyvsp[-1].expr));
				(yyval.expr) = (yyvsp[0].expr);
			}
			else (yyval.expr) = exnewnode(expr.program, ';', 1, (yyvsp[0].expr)->type, (yyvsp[-1].expr), (yyvsp[0].expr));
		}
#line 1711 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 9: /* statement: '{' statement_list '}'  */
#line 271 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = (yyvsp[-1].expr);
		}
#line 1719 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 10: /* statement: expr_opt ';'  */
#line 275 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = ((yyvsp[-1].expr) && (yyvsp[-1].expr)->type == STRING) ? exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[-1].expr), NULL) : (yyvsp[-1].expr);
		}
#line 1727 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 11: /* $@2: %empty  */
#line 278 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                               {expr.instatic=(yyvsp[0].integer);}
#line 1733 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 12: /* $@3: %empty  */
#line 278 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                                           {expr.declare=(yyvsp[0].id)->type;}
#line 1739 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 13: /* statement: static $@2 DECLARE $@3 dcl_list ';'  */
#line 279 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = (yyvsp[-1].expr);
			expr.declare = 0;
		}
#line 1748 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 14: /* statement: IF '(' expr ')' statement else_opt  */
#line 284 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (exisAssign ((yyvsp[-3].expr)))
				exwarn ("assignment used as boolean in if statement");
			if ((yyvsp[-3].expr)->type == STRING)
				(yyvsp[-3].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[-3].expr), NULL);
			else if (!INTEGRAL((yyvsp[-3].expr)->type))
				(yyvsp[-3].expr) = excast(expr.program, (yyvsp[-3].expr), INTEGER, NULL, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-5].id)->index, 1, INTEGER, (yyvsp[-3].expr), exnewnode(expr.program, ':', 1, (yyvsp[-1].expr) ? (yyvsp[-1].expr)->type : 0, (yyvsp[-1].expr), (yyvsp[0].expr)));
		}
#line 1762 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 15: /* statement: FOR '(' variable ')' statement  */
#line 294 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ITERATE, 0, INTEGER, NULL, NULL);
			(yyval.expr)->data.generate.array = (yyvsp[-2].expr);
			if (!(yyvsp[-2].expr)->data.variable.index || (yyvsp[-2].expr)->data.variable.index->op != DYNAMIC)
				exerror("simple index variable expected");
			(yyval.expr)->data.generate.index = (yyvsp[-2].expr)->data.variable.index->data.variable.symbol;
			if ((yyvsp[-2].expr)->op == ID && (yyval.expr)->data.generate.index->type != INTEGER)
				exerror("integer index variable expected");
			exfreenode(expr.program, (yyvsp[-2].expr)->data.variable.index);
			(yyvsp[-2].expr)->data.variable.index = 0;
			(yyval.expr)->data.generate.statement = (yyvsp[0].expr);
		}
#line 1779 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 16: /* statement: FOR '(' expr_opt ';' expr_opt ';' expr_opt ')' statement  */
#line 307 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (!(yyvsp[-4].expr))
			{
				(yyvsp[-4].expr) = exnewnode(expr.program, CONSTANT, 0, INTEGER, NULL, NULL);
				(yyvsp[-4].expr)->data.constant.value.integer = 1;
			}
			else if ((yyvsp[-4].expr)->type == STRING)
				(yyvsp[-4].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[-4].expr), NULL);
			else if (!INTEGRAL((yyvsp[-4].expr)->type))
				(yyvsp[-4].expr) = excast(expr.program, (yyvsp[-4].expr), INTEGER, NULL, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-8].id)->index, 1, INTEGER, (yyvsp[-4].expr), exnewnode(expr.program, ';', 1, 0, (yyvsp[-2].expr), (yyvsp[0].expr)));
			if ((yyvsp[-6].expr))
				(yyval.expr) = exnewnode(expr.program, ';', 1, INTEGER, (yyvsp[-6].expr), (yyval.expr));
		}
#line 1798 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 17: /* statement: ITERATER '(' variable ')' statement  */
#line 322 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ITERATER, 0, INTEGER, NULL, NULL);
			(yyval.expr)->data.generate.array = (yyvsp[-2].expr);
			if (!(yyvsp[-2].expr)->data.variable.index || (yyvsp[-2].expr)->data.variable.index->op != DYNAMIC)
				exerror("simple index variable expected");
			(yyval.expr)->data.generate.index = (yyvsp[-2].expr)->data.variable.index->data.variable.symbol;
			if ((yyvsp[-2].expr)->op == ID && (yyval.expr)->data.generate.index->type != INTEGER)
				exerror("integer index variable expected");
			exfreenode(expr.program, (yyvsp[-2].expr)->data.variable.index);
			(yyvsp[-2].expr)->data.variable.index = 0;
			(yyval.expr)->data.generate.statement = (yyvsp[0].expr);
		}
#line 1815 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 18: /* statement: UNSET '(' DYNAMIC ')'  */
#line 335 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[-1].id)->local.pointer == 0)
              			exerror("cannot apply unset to non-array %s", (yyvsp[-1].id)->name);
			(yyval.expr) = exnewnode(expr.program, UNSET, 0, INTEGER, NULL, NULL);
			(yyval.expr)->data.variable.symbol = (yyvsp[-1].id);
			(yyval.expr)->data.variable.index = NULL;
		}
#line 1827 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 19: /* statement: UNSET '(' DYNAMIC ',' expr ')'  */
#line 343 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[-3].id)->local.pointer == 0)
              			exerror("cannot apply unset to non-array %s", (yyvsp[-3].id)->name);
			if (((yyvsp[-3].id)->index_type > 0) && ((yyvsp[-1].expr)->type != (yyvsp[-3].id)->index_type))
            		    exerror("%s indices must have type %s, not %s", 
				(yyvsp[-3].id)->name, extypename(expr.program, (yyvsp[-3].id)->index_type),extypename(expr.program, (yyvsp[-1].expr)->type));
			(yyval.expr) = exnewnode(expr.program, UNSET, 0, INTEGER, NULL, NULL);
			(yyval.expr)->data.variable.symbol = (yyvsp[-3].id);
			(yyval.expr)->data.variable.index = (yyvsp[-1].expr);
		}
#line 1842 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 20: /* statement: WHILE '(' expr ')' statement  */
#line 354 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (exisAssign ((yyvsp[-2].expr)))
				exwarn ("assignment used as boolean in while statement");
			if ((yyvsp[-2].expr)->type == STRING)
				(yyvsp[-2].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[-2].expr), NULL);
			else if (!INTEGRAL((yyvsp[-2].expr)->type))
				(yyvsp[-2].expr) = excast(expr.program, (yyvsp[-2].expr), INTEGER, NULL, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-4].id)->index, 1, INTEGER, (yyvsp[-2].expr), exnewnode(expr.program, ';', 1, 0, NULL, (yyvsp[0].expr)));
		}
#line 1856 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 21: /* $@4: %empty  */
#line 363 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                        {expr.declare=(yyvsp[0].expr)->type;}
#line 1862 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 22: /* statement: SWITCH '(' expr $@4 ')' '{' switch_list '}'  */
#line 364 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Switch_t*	sw = expr.swstate;

			(yyval.expr) = exnewnode(expr.program, (yyvsp[-7].id)->index, 1, INTEGER, (yyvsp[-5].expr), exnewnode(expr.program, DEFAULT, 1, 0, sw->defcase, sw->firstcase));
			expr.swstate = expr.swstate->prev;
			free(sw->base);
			if (sw != &swstate)
				free(sw);
			expr.declare = 0;
		}
#line 1877 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 23: /* statement: BREAK expr_opt ';'  */
#line 375 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
		loopop:
			if (!(yyvsp[-1].expr))
			{
				(yyvsp[-1].expr) = exnewnode(expr.program, CONSTANT, 0, INTEGER, NULL, NULL);
				(yyvsp[-1].expr)->data.constant.value.integer = 1;
			}
			else if (!INTEGRAL((yyvsp[-1].expr)->type))
				(yyvsp[-1].expr) = excast(expr.program, (yyvsp[-1].expr), INTEGER, NULL, 0);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-2].id)->index, 1, INTEGER, (yyvsp[-1].expr), NULL);
		}
#line 1893 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 24: /* statement: CONTINUE expr_opt ';'  */
#line 387 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto loopop;
		}
#line 1901 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 25: /* statement: RETURN expr_opt ';'  */
#line 391 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[-1].expr))
			{
				if (expr.procedure && !expr.procedure->type)
					exerror("return in void function");
				(yyvsp[-1].expr) = excast(expr.program, (yyvsp[-1].expr), expr.procedure ? expr.procedure->type : INTEGER, NULL, 0);
			}
			(yyval.expr) = exnewnode(expr.program, RETURN, 1, (yyvsp[-1].expr) ? (yyvsp[-1].expr)->type : 0, (yyvsp[-1].expr), NULL);
		}
#line 1915 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 26: /* switch_list: %empty  */
#line 403 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Switch_t*		sw;

			if (expr.swstate)
			{
				if (!(sw = calloc(1, sizeof(Switch_t))))
				{
					exnospace();
					sw = &swstate;
				}
				sw->prev = expr.swstate;
			}
			else
				sw = &swstate;
			expr.swstate = sw;
			sw->type = expr.declare;
			sw->firstcase = 0;
			sw->lastcase = 0;
			sw->defcase = 0;
			sw->def = 0;
			size_t n = 8;
			if (!(sw->base = calloc(n, sizeof(Extype_t*))))
			{
				exnospace();
				n = 0;
			}
			sw->cur = sw->base;
			sw->last = sw->base + n;
		}
#line 1949 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 28: /* switch_item: case_list statement_list  */
#line 436 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Switch_t*	sw = expr.swstate;

			(yyval.expr) = exnewnode(expr.program, CASE, 1, 0, (yyvsp[0].expr), NULL);
			if (sw->cur > sw->base)
			{
				if (sw->lastcase)
					sw->lastcase->data.select.next = (yyval.expr);
				else
					sw->firstcase = (yyval.expr);
				sw->lastcase = (yyval.expr);
				size_t n = (size_t)(sw->cur - sw->base);
				sw->cur = sw->base;
				(yyval.expr)->data.select.constant = exalloc(expr.program, (n + 1) * sizeof(Extype_t*));
				memcpy((yyval.expr)->data.select.constant, sw->base, n * sizeof(Extype_t*));
				(yyval.expr)->data.select.constant[n] = 0;
			}
			else
				(yyval.expr)->data.select.constant = 0;
			if (sw->def)
			{
				sw->def = 0;
				if (sw->defcase)
					exerror("duplicate default in switch");
				else
					sw->defcase = (yyvsp[0].expr);
			}
		}
#line 1982 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 31: /* case_item: CASE constant ':'  */
#line 471 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (expr.swstate->cur >= expr.swstate->last)
			{
				size_t n = (size_t)(expr.swstate->cur - expr.swstate->base);
				if (!(expr.swstate->base = realloc(expr.swstate->base, sizeof(Extype_t*) * 2 * n)))
				{
					exerror("too many case labels for switch");
					n = 0;
				}
				expr.swstate->cur = expr.swstate->base + n;
				expr.swstate->last = expr.swstate->base + 2 * n;
			}
			if (expr.swstate->cur)
			{
				(yyvsp[-1].expr) = excast(expr.program, (yyvsp[-1].expr), expr.swstate->type, NULL, 0);
				*expr.swstate->cur++ = &((yyvsp[-1].expr)->data.constant.value);
			}
		}
#line 2005 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 32: /* case_item: DEFAULT ':'  */
#line 490 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			expr.swstate->def = 1;
		}
#line 2013 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 33: /* static: %empty  */
#line 496 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.integer) = 0;
		}
#line 2021 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 34: /* static: STATIC  */
#line 500 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.integer) = 1;
		}
#line 2029 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 36: /* dcl_list: dcl_list ',' dcl_item  */
#line 507 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[0].expr))
				(yyval.expr) = (yyvsp[-2].expr) ? exnewnode(expr.program, ',', 1, (yyvsp[0].expr)->type, (yyvsp[-2].expr), (yyvsp[0].expr)) : (yyvsp[0].expr);
		}
#line 2038 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 37: /* $@5: %empty  */
#line 513 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                 {checkName ((yyvsp[0].id)); expr.id=(yyvsp[0].id);}
#line 2044 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 38: /* dcl_item: dcl_name $@5 array initialize  */
#line 514 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
			if (!(yyvsp[-3].id)->type || expr.declare)
				(yyvsp[-3].id)->type = expr.declare;
			if ((yyvsp[0].expr) && (yyvsp[0].expr)->op == PROCEDURE)
			{
				(yyvsp[-3].id)->lex = PROCEDURE;
				(yyvsp[-3].id)->type = (yyvsp[0].expr)->type;
				(yyvsp[-3].id)->value = (yyvsp[0].expr);
			}
			else
			{
				(yyvsp[-3].id)->lex = DYNAMIC;
				(yyvsp[-3].id)->value = exnewnode(expr.program, 0, 0, 0, NULL, NULL);
				if ((yyvsp[-1].integer) && !(yyvsp[-3].id)->local.pointer)
				{
					Dtdisc_t*	disc;

					if (!(disc = calloc(1, sizeof(Dtdisc_t))))
						exnospace();
					if ((yyvsp[-1].integer) == INTEGER) {
						disc->key = offsetof(Exassoc_t, key);
						disc->size = sizeof(Extype_t);
						disc->comparf = (Dtcompar_f)cmpKey;
					}
					else
						disc->key = offsetof(Exassoc_t, name);
					if (!((yyvsp[-3].id)->local.pointer = (char*)dtopen(disc, Dtoset)))
						exerror("%s: cannot initialize associative array", (yyvsp[-3].id)->name);
					(yyvsp[-3].id)->index_type = (yyvsp[-1].integer); /* -1 indicates no typechecking */
				}
				if ((yyvsp[0].expr))
				{
					if ((yyvsp[0].expr)->type != (yyvsp[-3].id)->type)
					{
						(yyvsp[0].expr)->type = (yyvsp[-3].id)->type;
						(yyvsp[0].expr)->data.operand.right = excast(expr.program, (yyvsp[0].expr)->data.operand.right, (yyvsp[-3].id)->type, NULL, 0);
					}
					(yyvsp[0].expr)->data.operand.left = exnewnode(expr.program, DYNAMIC, 0, (yyvsp[-3].id)->type, NULL, NULL);
					(yyvsp[0].expr)->data.operand.left->data.variable.symbol = (yyvsp[-3].id);
					(yyval.expr) = (yyvsp[0].expr);
				}
				else if (!(yyvsp[-1].integer))
					(yyvsp[-3].id)->value->data.value = exzero((yyvsp[-3].id)->type);
			}
		}
#line 2095 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 45: /* else_opt: %empty  */
#line 573 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
		}
#line 2103 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 46: /* else_opt: ELSE statement  */
#line 577 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = (yyvsp[0].expr);
		}
#line 2111 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 47: /* expr_opt: %empty  */
#line 583 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
		}
#line 2119 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 49: /* expr: '(' expr ')'  */
#line 590 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = (yyvsp[-1].expr);
		}
#line 2127 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 50: /* expr: '(' DECLARE ')' expr  */
#line 594 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = ((yyvsp[0].expr)->type == (yyvsp[-2].id)->type) ? (yyvsp[0].expr) : excast(expr.program, (yyvsp[0].expr), (yyvsp[-2].id)->type, NULL, 0);
		}
#line 2135 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 51: /* expr: expr '<' expr  */
#line 598 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			int	rel;

		relational:
			rel = INTEGER;
			goto coerce;
		binary:
			rel = 0;
		coerce:
			if (!(yyvsp[-2].expr)->type)
			{
				if (!(yyvsp[0].expr)->type)
					(yyvsp[-2].expr)->type = (yyvsp[0].expr)->type = rel ? STRING : INTEGER;
				else
					(yyvsp[-2].expr)->type = (yyvsp[0].expr)->type;
			}
			else if (!(yyvsp[0].expr)->type)
				(yyvsp[0].expr)->type = (yyvsp[-2].expr)->type;
			if ((yyvsp[-2].expr)->type != (yyvsp[0].expr)->type)
			{
				if ((yyvsp[-2].expr)->type == STRING)
					(yyvsp[-2].expr) = excast(expr.program, (yyvsp[-2].expr), (yyvsp[0].expr)->type, (yyvsp[0].expr), 0);
				else if ((yyvsp[0].expr)->type == STRING)
					(yyvsp[0].expr) = excast(expr.program, (yyvsp[0].expr), (yyvsp[-2].expr)->type, (yyvsp[-2].expr), 0);
				else if ((yyvsp[-2].expr)->type == FLOATING)
					(yyvsp[0].expr) = excast(expr.program, (yyvsp[0].expr), FLOATING, (yyvsp[-2].expr), 0);
				else if ((yyvsp[0].expr)->type == FLOATING)
					(yyvsp[-2].expr) = excast(expr.program, (yyvsp[-2].expr), FLOATING, (yyvsp[0].expr), 0);
			}
			if (!rel)
				rel = ((yyvsp[-2].expr)->type == STRING) ? STRING : (((yyvsp[-2].expr)->type == UNSIGNED) ? UNSIGNED : (yyvsp[0].expr)->type);
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-1].op), 1, rel, (yyvsp[-2].expr), (yyvsp[0].expr));
			if (!expr.program->errors && (yyvsp[-2].expr)->op == CONSTANT && (yyvsp[0].expr)->op == CONSTANT)
			{
				(yyval.expr)->data.constant.value = exeval(expr.program, (yyval.expr), NULL);
				/* If a constant string, re-allocate from program heap. This is because the
				 * value was constructed from string operators, which create a value in the 
				 * temporary heap, which is cleared when exeval is called again. 
				 */
				if ((yyval.expr)->type == STRING) {
					(yyval.expr)->data.constant.value.string =
						vmstrdup(expr.program->vm, (yyval.expr)->data.constant.value.string);
				}
				(yyval.expr)->binary = 0;
				(yyval.expr)->op = CONSTANT;
				exfreenode(expr.program, (yyvsp[-2].expr));
				exfreenode(expr.program, (yyvsp[0].expr));
			}
			else if (!BUILTIN((yyvsp[-2].expr)->type) || !BUILTIN((yyvsp[0].expr)->type)) {
				checkBinary(expr.program, (yyvsp[-2].expr), (yyval.expr), (yyvsp[0].expr));
			}
		}
#line 2192 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 52: /* expr: expr '-' expr  */
#line 651 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2200 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 53: /* expr: expr '*' expr  */
#line 655 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2208 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 54: /* expr: expr '/' expr  */
#line 659 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2216 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 55: /* expr: expr '%' expr  */
#line 663 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2224 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 56: /* expr: expr LSH expr  */
#line 667 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2232 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 57: /* expr: expr RSH expr  */
#line 671 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2240 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 58: /* expr: expr '>' expr  */
#line 675 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto relational;
		}
#line 2248 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 59: /* expr: expr LE expr  */
#line 679 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto relational;
		}
#line 2256 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 60: /* expr: expr GE expr  */
#line 683 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto relational;
		}
#line 2264 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 61: /* expr: expr EQ expr  */
#line 687 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto relational;
		}
#line 2272 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 62: /* expr: expr NE expr  */
#line 691 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto relational;
		}
#line 2280 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 63: /* expr: expr '&' expr  */
#line 695 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2288 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 64: /* expr: expr '|' expr  */
#line 699 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2296 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 65: /* expr: expr '^' expr  */
#line 703 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2304 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 66: /* expr: expr '+' expr  */
#line 707 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto binary;
		}
#line 2312 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 67: /* expr: expr AND expr  */
#line 711 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
		logical:
			if ((yyvsp[-2].expr)->type == STRING)
				(yyvsp[-2].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[-2].expr), NULL);
			else if (!BUILTIN((yyvsp[-2].expr)->type))
				(yyvsp[-2].expr) = excast(expr.program, (yyvsp[-2].expr), INTEGER, NULL, 0);
			if ((yyvsp[0].expr)->type == STRING)
				(yyvsp[0].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[0].expr), NULL);
			else if (!BUILTIN((yyvsp[0].expr)->type))
				(yyvsp[0].expr) = excast(expr.program, (yyvsp[0].expr), INTEGER, NULL, 0);
			goto binary;
		}
#line 2329 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 68: /* expr: expr OR expr  */
#line 724 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto logical;
		}
#line 2337 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 69: /* expr: expr ',' expr  */
#line 728 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[-2].expr)->op == CONSTANT)
			{
				exfreenode(expr.program, (yyvsp[-2].expr));
				(yyval.expr) = (yyvsp[0].expr);
			}
			else
				(yyval.expr) = exnewnode(expr.program, ',', 1, (yyvsp[0].expr)->type, (yyvsp[-2].expr), (yyvsp[0].expr));
		}
#line 2351 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 70: /* $@6: %empty  */
#line 737 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                 {expr.nolabel=1;}
#line 2357 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 71: /* $@7: %empty  */
#line 737 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                                            {expr.nolabel=0;}
#line 2363 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 72: /* expr: expr '?' $@6 expr ':' $@7 expr  */
#line 738 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (!(yyvsp[-3].expr)->type)
			{
				if (!(yyvsp[0].expr)->type)
					(yyvsp[-3].expr)->type = (yyvsp[0].expr)->type = INTEGER;
				else
					(yyvsp[-3].expr)->type = (yyvsp[0].expr)->type;
			}
			else if (!(yyvsp[0].expr)->type)
				(yyvsp[0].expr)->type = (yyvsp[-3].expr)->type;
			if ((yyvsp[-6].expr)->type == STRING)
				(yyvsp[-6].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[-6].expr), NULL);
			else if (!INTEGRAL((yyvsp[-6].expr)->type))
				(yyvsp[-6].expr) = excast(expr.program, (yyvsp[-6].expr), INTEGER, NULL, 0);
			if ((yyvsp[-3].expr)->type != (yyvsp[0].expr)->type)
			{
				if ((yyvsp[-3].expr)->type == STRING || (yyvsp[0].expr)->type == STRING)
					exerror("if statement string type mismatch");
				else if ((yyvsp[-3].expr)->type == FLOATING)
					(yyvsp[0].expr) = excast(expr.program, (yyvsp[0].expr), FLOATING, NULL, 0);
				else if ((yyvsp[0].expr)->type == FLOATING)
					(yyvsp[-3].expr) = excast(expr.program, (yyvsp[-3].expr), FLOATING, NULL, 0);
			}
			if ((yyvsp[-6].expr)->op == CONSTANT)
			{
				if ((yyvsp[-6].expr)->data.constant.value.integer)
				{
					(yyval.expr) = (yyvsp[-3].expr);
					exfreenode(expr.program, (yyvsp[0].expr));
				}
				else
				{
					(yyval.expr) = (yyvsp[0].expr);
					exfreenode(expr.program, (yyvsp[-3].expr));
				}
				exfreenode(expr.program, (yyvsp[-6].expr));
			}
			else
				(yyval.expr) = exnewnode(expr.program, '?', 1, (yyvsp[-3].expr)->type, (yyvsp[-6].expr), exnewnode(expr.program, ':', 1, (yyvsp[-3].expr)->type, (yyvsp[-3].expr), (yyvsp[0].expr)));
		}
#line 2408 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 73: /* expr: '!' expr  */
#line 779 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
		iunary:
			if ((yyvsp[0].expr)->type == STRING)
				(yyvsp[0].expr) = exnewnode(expr.program, S2B, 1, INTEGER, (yyvsp[0].expr), NULL);
			else if (!INTEGRAL((yyvsp[0].expr)->type))
				(yyvsp[0].expr) = excast(expr.program, (yyvsp[0].expr), INTEGER, NULL, 0);
		unary:
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-1].op), 1, (yyvsp[0].expr)->type == UNSIGNED ? INTEGER : (yyvsp[0].expr)->type, (yyvsp[0].expr), NULL);
			if ((yyvsp[0].expr)->op == CONSTANT)
			{
				(yyval.expr)->data.constant.value = exeval(expr.program, (yyval.expr), NULL);
				(yyval.expr)->binary = 0;
				(yyval.expr)->op = CONSTANT;
				exfreenode(expr.program, (yyvsp[0].expr));
			}
			else if (!BUILTIN((yyvsp[0].expr)->type)) {
				checkBinary(expr.program, (yyvsp[0].expr), (yyval.expr), 0);
			}
		}
#line 2432 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 74: /* expr: '#' DYNAMIC  */
#line 799 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[0].id)->local.pointer == 0)
              			exerror("cannot apply '#' operator to non-array %s", (yyvsp[0].id)->name);
			(yyval.expr) = exnewnode(expr.program, '#', 0, INTEGER, NULL, NULL);
			(yyval.expr)->data.variable.symbol = (yyvsp[0].id);
		}
#line 2443 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 75: /* expr: '~' expr  */
#line 806 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto iunary;
		}
#line 2451 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 76: /* expr: '-' expr  */
#line 810 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto unary;
		}
#line 2459 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 77: /* expr: '+' expr  */
#line 814 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = (yyvsp[0].expr);
		}
#line 2467 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 78: /* expr: '&' variable  */
#line 818 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ADDRESS, 0, T((yyvsp[0].expr)->type), (yyvsp[0].expr), NULL);
		}
#line 2475 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 79: /* expr: ARRAY '[' args ']'  */
#line 822 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ARRAY, 1, T((yyvsp[-3].id)->type), call(0, (yyvsp[-3].id), (yyvsp[-1].expr)), (yyvsp[-1].expr));
		}
#line 2483 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 80: /* expr: FUNCTION '(' args ')'  */
#line 826 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, FUNCTION, 1, T((yyvsp[-3].id)->type), call(0, (yyvsp[-3].id), (yyvsp[-1].expr)), (yyvsp[-1].expr));
		}
#line 2491 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 81: /* expr: GSUB '(' args ')'  */
#line 830 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewsub (expr.program, (yyvsp[-1].expr), GSUB);
		}
#line 2499 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 82: /* expr: SUB '(' args ')'  */
#line 834 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewsub (expr.program, (yyvsp[-1].expr), SUB);
		}
#line 2507 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 83: /* expr: SUBSTR '(' args ')'  */
#line 838 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewsubstr (expr.program, (yyvsp[-1].expr));
		}
#line 2515 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 84: /* expr: splitop '(' expr ',' DYNAMIC ')'  */
#line 842 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewsplit (expr.program, (yyvsp[-5].id)->index, (yyvsp[-1].id), (yyvsp[-3].expr), NULL);
		}
#line 2523 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 85: /* expr: splitop '(' expr ',' DYNAMIC ',' expr ')'  */
#line 846 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewsplit (expr.program, (yyvsp[-7].id)->index, (yyvsp[-3].id), (yyvsp[-5].expr), (yyvsp[-1].expr));
		}
#line 2531 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 86: /* expr: EXIT '(' expr ')'  */
#line 850 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (!INTEGRAL((yyvsp[-1].expr)->type))
				(yyvsp[-1].expr) = excast(expr.program, (yyvsp[-1].expr), INTEGER, NULL, 0);
			(yyval.expr) = exnewnode(expr.program, EXIT, 1, INTEGER, (yyvsp[-1].expr), NULL);
		}
#line 2541 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 87: /* expr: RAND '(' ')'  */
#line 856 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, RAND, 0, FLOATING, NULL, NULL);
		}
#line 2549 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 88: /* expr: SRAND '(' ')'  */
#line 860 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, SRAND, 0, INTEGER, NULL, NULL);
		}
#line 2557 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 89: /* expr: SRAND '(' expr ')'  */
#line 864 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if (!INTEGRAL((yyvsp[-1].expr)->type))
				(yyvsp[-1].expr) = excast(expr.program, (yyvsp[-1].expr), INTEGER, NULL, 0);
			(yyval.expr) = exnewnode(expr.program, SRAND, 1, INTEGER, (yyvsp[-1].expr), NULL);
		}
#line 2567 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 90: /* expr: PROCEDURE '(' args ')'  */
#line 870 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, CALL, 1, (yyvsp[-3].id)->type, NULL, (yyvsp[-1].expr));
			(yyval.expr)->data.call.procedure = (yyvsp[-3].id);
		}
#line 2576 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 91: /* expr: PRINT '(' args ')'  */
#line 875 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exprint(expr.program, (yyvsp[-3].id), (yyvsp[-1].expr));
		}
#line 2584 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 92: /* expr: print '(' args ')'  */
#line 879 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-3].id)->index, 0, (yyvsp[-3].id)->type, NULL, NULL);
			if ((yyvsp[-1].expr) && (yyvsp[-1].expr)->data.operand.left->type == INTEGER)
			{
				(yyval.expr)->data.print.descriptor = (yyvsp[-1].expr)->data.operand.left;
				(yyvsp[-1].expr) = (yyvsp[-1].expr)->data.operand.right;
			}
			else 
				switch ((yyvsp[-3].id)->index)
				{
				case QUERY:
					(yyval.expr)->data.print.descriptor = exnewnode(expr.program, CONSTANT, 0, INTEGER, NULL, NULL);
					(yyval.expr)->data.print.descriptor->data.constant.value.integer = 2;
					break;
				case PRINTF:
					(yyval.expr)->data.print.descriptor = exnewnode(expr.program, CONSTANT, 0, INTEGER, NULL, NULL);
					(yyval.expr)->data.print.descriptor->data.constant.value.integer = 1;
					break;
				case SPRINTF:
					(yyval.expr)->data.print.descriptor = 0;
					break;
				}
			(yyval.expr)->data.print.args = preprint((yyvsp[-1].expr));
		}
#line 2613 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 93: /* expr: scan '(' args ')'  */
#line 904 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Exnode_t*	x;

			(yyval.expr) = exnewnode(expr.program, (yyvsp[-3].id)->index, 0, (yyvsp[-3].id)->type, NULL, NULL);
			if ((yyvsp[-1].expr) && (yyvsp[-1].expr)->data.operand.left->type == INTEGER)
			{
				(yyval.expr)->data.scan.descriptor = (yyvsp[-1].expr)->data.operand.left;
				(yyvsp[-1].expr) = (yyvsp[-1].expr)->data.operand.right;
			}
			else 
				switch ((yyvsp[-3].id)->index)
				{
				case SCANF:
					(yyval.expr)->data.scan.descriptor = 0;
					break;
				case SSCANF:
					if ((yyvsp[-1].expr) && (yyvsp[-1].expr)->data.operand.left->type == STRING)
					{
						(yyval.expr)->data.scan.descriptor = (yyvsp[-1].expr)->data.operand.left;
						(yyvsp[-1].expr) = (yyvsp[-1].expr)->data.operand.right;
					}
					else
						exerror("%s: string argument expected", (yyvsp[-3].id)->name);
					break;
				}
			if (!(yyvsp[-1].expr) || !(yyvsp[-1].expr)->data.operand.left || (yyvsp[-1].expr)->data.operand.left->type != STRING)
				exerror("%s: format argument expected", (yyvsp[-3].id)->name);
			(yyval.expr)->data.scan.format = (yyvsp[-1].expr)->data.operand.left;
			for (x = (yyval.expr)->data.scan.args = (yyvsp[-1].expr)->data.operand.right; x; x = x->data.operand.right)
			{
				if (x->data.operand.left->op != ADDRESS)
					exerror("%s: address argument expected", (yyvsp[-3].id)->name);
				x->data.operand.left = x->data.operand.left->data.operand.left;
			}
		}
#line 2653 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 94: /* expr: variable assign  */
#line 940 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[0].expr))
			{
				if ((yyvsp[-1].expr)->op == ID && !expr.program->disc->setf)
					exerror("%s: variable assignment not supported", (yyvsp[-1].expr)->data.variable.symbol->name);
				else
				{
					if (!(yyvsp[-1].expr)->type)
						(yyvsp[-1].expr)->type = (yyvsp[0].expr)->type;
					else if ((yyvsp[0].expr)->type != (yyvsp[-1].expr)->type)
					{
						(yyvsp[0].expr)->type = (yyvsp[-1].expr)->type;
						(yyvsp[0].expr)->data.operand.right = excast(expr.program, (yyvsp[0].expr)->data.operand.right, (yyvsp[-1].expr)->type, NULL, 0);
					}
					(yyvsp[0].expr)->data.operand.left = (yyvsp[-1].expr);
					(yyval.expr) = (yyvsp[0].expr);
				}
			}
		}
#line 2677 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 95: /* expr: INC variable  */
#line 960 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
		pre:
			if ((yyvsp[0].expr)->type == STRING)
				exerror("++ and -- invalid for string variables");
			(yyval.expr) = exnewnode(expr.program, (yyvsp[-1].op), 0, (yyvsp[0].expr)->type, (yyvsp[0].expr), NULL);
			(yyval.expr)->subop = PRE;
		}
#line 2689 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 96: /* expr: variable INC  */
#line 968 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
		pos:
			if ((yyvsp[-1].expr)->type == STRING)
				exerror("++ and -- invalid for string variables");
			(yyval.expr) = exnewnode(expr.program, (yyvsp[0].op), 0, (yyvsp[-1].expr)->type, (yyvsp[-1].expr), NULL);
			(yyval.expr)->subop = POS;
		}
#line 2701 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 97: /* expr: expr IN_OP DYNAMIC  */
#line 976 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			if ((yyvsp[0].id)->local.pointer == 0)
              			exerror("cannot apply IN to non-array %s", (yyvsp[0].id)->name);
			if (((yyvsp[0].id)->index_type > 0) && ((yyvsp[-2].expr)->type != (yyvsp[0].id)->index_type))
            		    exerror("%s indices must have type %s, not %s", 
				(yyvsp[0].id)->name, extypename(expr.program, (yyvsp[0].id)->index_type),extypename(expr.program, (yyvsp[-2].expr)->type));
			(yyval.expr) = exnewnode(expr.program, IN_OP, 0, INTEGER, NULL, NULL);
			(yyval.expr)->data.variable.symbol = (yyvsp[0].id);
			(yyval.expr)->data.variable.index = (yyvsp[-2].expr);
		}
#line 2716 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 98: /* expr: DEC variable  */
#line 987 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto pre;
		}
#line 2724 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 99: /* expr: variable DEC  */
#line 991 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			goto pos;
		}
#line 2732 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 103: /* constant: CONSTANT  */
#line 1001 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, CONSTANT, 0, (yyvsp[0].id)->type, NULL, NULL);
			if (!expr.program->disc->reff)
				exerror("%s: identifier references not supported", (yyvsp[0].id)->name);
			else
				(yyval.expr)->data.constant.value = expr.program->disc->reff(expr.program, (yyval.expr), (yyvsp[0].id), NULL);
		}
#line 2744 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 104: /* constant: FLOATING  */
#line 1009 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, CONSTANT, 0, FLOATING, NULL, NULL);
			(yyval.expr)->data.constant.value.floating = (yyvsp[0].floating);
		}
#line 2753 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 105: /* constant: INTEGER  */
#line 1014 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, CONSTANT, 0, INTEGER, NULL, NULL);
			(yyval.expr)->data.constant.value.integer = (yyvsp[0].integer);
		}
#line 2762 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 106: /* constant: STRING  */
#line 1019 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, CONSTANT, 0, STRING, NULL, NULL);
			(yyval.expr)->data.constant.value.string = (yyvsp[0].string);
		}
#line 2771 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 107: /* constant: UNSIGNED  */
#line 1024 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, CONSTANT, 0, UNSIGNED, NULL, NULL);
			(yyval.expr)->data.constant.value.integer = (yyvsp[0].integer);
		}
#line 2780 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 113: /* variable: ID members  */
#line 1040 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = makeVar(expr.program, (yyvsp[-1].id), 0, 0, (yyvsp[0].reference));
		}
#line 2788 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 114: /* variable: DYNAMIC index members  */
#line 1044 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Exnode_t*   n;

			n = exnewnode(expr.program, DYNAMIC, 0, (yyvsp[-2].id)->type, NULL, NULL);
			n->data.variable.symbol = (yyvsp[-2].id);
			n->data.variable.reference = 0;
			if (((n->data.variable.index = (yyvsp[-1].expr)) == 0) != ((yyvsp[-2].id)->local.pointer == 0))
				exerror("%s: is%s an array", (yyvsp[-2].id)->name, (yyvsp[-2].id)->local.pointer ? "" : " not");
			if ((yyvsp[-2].id)->local.pointer && ((yyvsp[-2].id)->index_type > 0)) {
				if ((yyvsp[-1].expr)->type != (yyvsp[-2].id)->index_type)
					exerror("%s: indices must have type %s, not %s", 
						(yyvsp[-2].id)->name, extypename(expr.program, (yyvsp[-2].id)->index_type),extypename(expr.program, (yyvsp[-1].expr)->type));
			}
			if ((yyvsp[0].reference)) {
				n->data.variable.dyna =exnewnode(expr.program, 0, 0, 0, NULL, NULL);
				(yyval.expr) = makeVar(expr.program, (yyvsp[-2].id), (yyvsp[-1].expr), n, (yyvsp[0].reference));
			}
			else (yyval.expr) = n;
		}
#line 2812 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 115: /* variable: NAME  */
#line 1064 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ID, 0, STRING, NULL, NULL);
			(yyval.expr)->data.variable.symbol = (yyvsp[0].id);
			(yyval.expr)->data.variable.reference = 0;
			(yyval.expr)->data.variable.index = 0;
			(yyval.expr)->data.variable.dyna = 0;
			if (!(expr.program->disc->flags & EX_UNDECLARED))
				exerror("unknown identifier");
		}
#line 2826 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 116: /* array: %empty  */
#line 1076 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.integer) = 0;
		}
#line 2834 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 117: /* array: '[' ']'  */
#line 1080 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.integer) = -1;
		}
#line 2842 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 118: /* array: '[' DECLARE ']'  */
#line 1084 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			/* If DECLARE is VOID, its type is 0, so this acts like
			 * the empty case.
			 */
			if (INTEGRAL((yyvsp[-1].id)->type))
				(yyval.integer) = INTEGER;
			else
				(yyval.integer) = (yyvsp[-1].id)->type;
				
		}
#line 2857 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 119: /* index: %empty  */
#line 1097 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
		}
#line 2865 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 120: /* index: '[' expr ']'  */
#line 1101 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = (yyvsp[-1].expr);
		}
#line 2873 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 121: /* args: %empty  */
#line 1107 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
		}
#line 2881 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 122: /* args: arg_list  */
#line 1111 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = (yyvsp[0].expr)->data.operand.left;
			(yyvsp[0].expr)->data.operand.left = (yyvsp[0].expr)->data.operand.right = 0;
			exfreenode(expr.program, (yyvsp[0].expr));
		}
#line 2891 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 123: /* arg_list: expr  */
#line 1119 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ',', 1, 0, exnewnode(expr.program, ',', 1, (yyvsp[0].expr)->type, (yyvsp[0].expr), NULL), NULL);
			(yyval.expr)->data.operand.right = (yyval.expr)->data.operand.left;
		}
#line 2900 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 124: /* arg_list: arg_list ',' expr  */
#line 1124 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyvsp[-2].expr)->data.operand.right = (yyvsp[-2].expr)->data.operand.right->data.operand.right = exnewnode(expr.program, ',', 1, (yyvsp[-2].expr)->type, (yyvsp[0].expr), NULL);
		}
#line 2908 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 125: /* formals: %empty  */
#line 1130 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
		}
#line 2916 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 126: /* formals: DECLARE  */
#line 1134 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
			if ((yyvsp[0].id)->type)
				exerror("(void) expected");
		}
#line 2926 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 128: /* formal_list: formal_item  */
#line 1143 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ',', 1, (yyvsp[0].expr)->type, (yyvsp[0].expr), NULL);
		}
#line 2934 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 129: /* formal_list: formal_list ',' formal_item  */
#line 1147 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Exnode_t*	x;
			Exnode_t*	y;

			(yyval.expr) = (yyvsp[-2].expr);
			for (x = (yyvsp[-2].expr); (y = x->data.operand.right); x = y);
			x->data.operand.right = exnewnode(expr.program, ',', 1, (yyvsp[0].expr)->type, (yyvsp[0].expr), NULL);
		}
#line 2947 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 130: /* $@8: %empty  */
#line 1157 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                {expr.declare=(yyvsp[0].id)->type;}
#line 2953 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 131: /* formal_item: DECLARE $@8 name  */
#line 1158 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, ID, 0, (yyvsp[-2].id)->type, NULL, NULL);
			(yyval.expr)->data.variable.symbol = (yyvsp[0].id);
			(yyvsp[0].id)->lex = DYNAMIC;
			(yyvsp[0].id)->type = (yyvsp[-2].id)->type;
			(yyvsp[0].id)->value = exnewnode(expr.program, 0, 0, 0, NULL, NULL);
			expr.procedure->data.procedure.arity++;
			expr.declare = 0;
		}
#line 2967 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 132: /* members: %empty  */
#line 1170 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.reference) = expr.refs = expr.lastref = 0;
		}
#line 2975 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 133: /* members: member  */
#line 1174 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Exref_t*	r;

			r = ALLOCATE(expr.program, Exref_t);
			memzero(r, sizeof(*r));
			r->symbol = (yyvsp[0].id);
			expr.refs = r;
			expr.lastref = r;
			r->next = 0;
			r->index = 0;
			(yyval.reference) = expr.refs;
		}
#line 2992 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 134: /* members: '.' ID member  */
#line 1187 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			Exref_t*	r;
			Exref_t*	l;

			r = ALLOCATE(expr.program, Exref_t);
			memzero(r, sizeof(*r));
			r->symbol = (yyvsp[0].id);
			r->index = 0;
			r->next = 0;
			l = ALLOCATE(expr.program, Exref_t);
			memzero(l, sizeof(*l));
			l->symbol = (yyvsp[-1].id);
			l->index = 0;
			l->next = r;
			expr.refs = l;
			expr.lastref = r;
			(yyval.reference) = expr.refs;
		}
#line 3015 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 135: /* member: '.' ID  */
#line 1208 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.id) = (yyvsp[0].id);
		}
#line 3023 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 136: /* member: '.' NAME  */
#line 1212 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.id) = (yyvsp[0].id);
		}
#line 3031 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 137: /* assign: %empty  */
#line 1217 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = 0;
		}
#line 3039 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 138: /* assign: '=' expr  */
#line 1221 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = exnewnode(expr.program, '=', 1, (yyvsp[0].expr)->type, NULL, (yyvsp[0].expr));
			(yyval.expr)->subop = (yyvsp[-1].op);
		}
#line 3048 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 140: /* $@9: %empty  */
#line 1228 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                            {
				Dtdisc_t*	disc;

				if (expr.procedure)
					exerror("%s: nested function definitions not supported", expr.id->name);
				expr.procedure = exnewnode(expr.program, PROCEDURE, 1, expr.declare, NULL, NULL);
				if (!(disc = calloc(1, sizeof(Dtdisc_t))))
					exnospace();
				disc->key = offsetof(Exid_t, name);
				if (!streq(expr.id->name, "begin"))
				{
					if (!(expr.procedure->data.procedure.frame = dtopen(disc, Dtset)) || !dtview(expr.procedure->data.procedure.frame, expr.program->symbols))
						exnospace();
					expr.program->symbols = expr.program->frame = expr.procedure->data.procedure.frame;
					expr.program->formals = 1;
				}
				expr.declare = 0;
			}
#line 3071 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 141: /* $@10: %empty  */
#line 1245 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                                  {
				expr.id->lex = PROCEDURE;
				expr.id->type = expr.procedure->type;
				expr.program->formals = 0;
				expr.declare = 0;
			}
#line 3082 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;

  case 142: /* initialize: '(' $@9 formals $@10 ')' '{' statement_list '}'  */
#line 1251 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"
                {
			(yyval.expr) = expr.procedure;
			expr.procedure = 0;
			if (expr.program->frame)
			{
				expr.program->symbols = expr.program->frame->view;
				dtview(expr.program->frame, NULL);
				expr.program->frame = 0;
			}
			(yyval.expr)->data.operand.left = (yyvsp[-5].expr);
			(yyval.expr)->data.operand.right = excast(expr.program, (yyvsp[-1].expr), (yyval.expr)->type, NULL, 0);

			/*
			 * NOTE: procedure definition was slipped into the
			 *	 declaration initializer statement production,
			 *	 therefore requiring the statement terminator
			 */

			exunlex(expr.program, ';');
		}
#line 3107 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"
    break;


#line 3111 "/Users/jason/Sources/sti/build/release/src/lib/graphviz/graphviz/lib/expr/exparse.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == EX_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= EX_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == EX_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = EX_EMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != EX_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1273 "/Users/jason/Sources/sti/src/lib/graphviz/graphviz/lib/expr/exparse.y"


const char *exop(size_t index) {

  /* yytname is generated by the %token-table directive */

  /* find the index of MINTOKEN */
  size_t minid;
  for (minid = 0; yytname[minid] != NULL; ++minid) {
    if (strcmp(yytname[minid], "MINTOKEN") == 0) {
      break;
    }
  }

  assert(yytname[minid] != NULL
    && "failed to find MINTOKEN; incorrect token list in exparse.y?");

  /* find the requested token */
  {
    size_t i, j;
    for (i = j = minid; yytname[i] != NULL; ++i) {

      /* if this token is not a word, skip it */
      {
        size_t k;
        for (k = 0; yytname[i][k] != '\0'; ++k) {
          if (yytname[i][k] != '_' && !isalnum((int)yytname[i][k])) {
            break;
          }
        }
        if (yytname[i][k] != '\0') {
          continue;
        }
      }

      if (j == index + minid) {
        return yytname[i];
      }
      ++j;
    }
  }

  /* failed to find the requested token */
  return NULL;
}

void ex_error(const char *message) {
  exerror("%s", message);
}

#include <expr/exgram.h>
