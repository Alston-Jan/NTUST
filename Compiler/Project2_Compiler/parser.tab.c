/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

symboltable* global_table = NULL;

int yylex(void);
void yyerror(const char *msg);
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
#define Trace(t) printf(t)
int current_type = -1;

#line 88 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTNUM = 3,                     /* INTNUM  */
  YYSYMBOL_FLOATNUM = 4,                   /* FLOATNUM  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_BOOL = 7,                       /* BOOL  */
  YYSYMBOL_TRUE = 8,                       /* TRUE  */
  YYSYMBOL_FALSE = 9,                      /* FALSE  */
  YYSYMBOL_CONST = 10,                     /* CONST  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_INT = 12,                       /* INT  */
  YYSYMBOL_FLOAT = 13,                     /* FLOAT  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_FOREACH = 18,                   /* FOREACH  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_PRINT = 20,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 21,                   /* PRINTLN  */
  YYSYMBOL_READ = 22,                      /* READ  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_STAR = 25,                      /* STAR  */
  YYSYMBOL_SLASH = 26,                     /* SLASH  */
  YYSYMBOL_MOD = 27,                       /* MOD  */
  YYSYMBOL_UMINUS = 28,                    /* UMINUS  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_ASSIGN = 38,                    /* ASSIGN  */
  YYSYMBOL_INC = 39,                       /* INC  */
  YYSYMBOL_DEC = 40,                       /* DEC  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_DOTDOT = 44,                    /* DOTDOT  */
  YYSYMBOL_LPAREN = 45,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 46,                    /* RPAREN  */
  YYSYMBOL_LBRACK = 47,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 48,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 49,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 50,                    /* RBRACE  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_for_init_opt = 52,              /* for_init_opt  */
  YYSYMBOL_expression_opt = 53,            /* expression_opt  */
  YYSYMBOL_for_step_opt = 54,              /* for_step_opt  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_decl_list = 56,                 /* decl_list  */
  YYSYMBOL_declaration = 57,               /* declaration  */
  YYSYMBOL_func_decl = 58,                 /* func_decl  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_param_list_opt = 60,            /* param_list_opt  */
  YYSYMBOL_param_list = 61,                /* param_list  */
  YYSYMBOL_param = 62,                     /* param  */
  YYSYMBOL_var_decl = 63,                  /* var_decl  */
  YYSYMBOL_const_decl = 64,                /* const_decl  */
  YYSYMBOL_array_size_list = 65,           /* array_size_list  */
  YYSYMBOL_array_size = 66,                /* array_size  */
  YYSYMBOL_block = 67,                     /* block  */
  YYSYMBOL_decl_or_stmt_list = 68,         /* decl_or_stmt_list  */
  YYSYMBOL_decl_or_stmt = 69,              /* decl_or_stmt  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_print_args = 71,                /* print_args  */
  YYSYMBOL_proc_call_stmt = 72,            /* proc_call_stmt  */
  YYSYMBOL_arg_list_opt = 73,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 74,                  /* arg_list  */
  YYSYMBOL_expression_list = 75,           /* expression_list  */
  YYSYMBOL_expression = 76                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_uint8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    43,    46,    47,    50,    51,    52,    53,
      54,    57,    61,    62,    66,    67,    68,    72,    73,    77,
      78,    79,    80,    81,    85,    86,    90,    91,    95,    99,
     106,   110,   114,   121,   128,   129,   133,   137,   141,   142,
     146,   147,   148,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   175,   176,   180,   184,   185,   189,   190,
     194,   195,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTNUM", "FLOATNUM",
  "STRING", "ID", "BOOL", "TRUE", "FALSE", "CONST", "VOID", "INT", "FLOAT",
  "IF", "ELSE", "WHILE", "FOR", "FOREACH", "RETURN", "PRINT", "PRINTLN",
  "READ", "PLUS", "MINUS", "STAR", "SLASH", "MOD", "UMINUS", "LT", "LE",
  "EQ", "GE", "GT", "NE", "AND", "OR", "NOT", "ASSIGN", "INC", "DEC",
  "SEMICOLON", "COMMA", "COLON", "DOTDOT", "LPAREN", "RPAREN", "LBRACK",
  "RBRACK", "LBRACE", "RBRACE", "$accept", "for_init_opt",
  "expression_opt", "for_step_opt", "program", "decl_list", "declaration",
  "func_decl", "type", "param_list_opt", "param_list", "param", "var_decl",
  "const_decl", "array_size_list", "array_size", "block",
  "decl_or_stmt_list", "decl_or_stmt", "statement", "print_args",
  "proc_call_stmt", "arg_list_opt", "arg_list", "expression_list",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     122,   -89,   -89,   131,     9,   -89,   -89,    30,   122,   -89,
     -89,    48,   -89,   -89,   -89,    64,    35,   -89,   -89,   -33,
      43,   131,   179,   -89,   131,    80,   -14,   -89,   179,    78,
      42,    51,   -89,   -89,   -89,   -89,   -34,   -89,   -89,   179,
     179,   179,   179,   179,   354,    52,    53,   -89,   -89,   373,
      58,    50,   131,   179,   179,   449,   449,   449,   449,   260,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   179,   179,   -89,   -89,   -89,    50,   -89,   -89,    58,
     -89,   -89,   -89,    54,    69,   449,   204,   -89,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   -89,    46,   -89,   179,   -89,   -16,    67,    68,    70,
      71,   117,   165,   172,   111,   -89,   113,   -89,   -89,   -89,
     -89,   -89,   -89,   449,   179,    83,    87,   179,   179,   179,
     179,   124,   125,   -89,   392,   -89,   179,    -7,   449,   -89,
     179,    -5,    98,   -31,   411,   -89,   -89,    94,   240,   278,
     296,   107,   108,   109,   -89,   104,   118,   260,   -89,   179,
     105,   -89,   -89,   -89,   114,   121,    55,    55,   179,   179,
     179,   120,   449,   126,   -89,   179,   148,   -89,   449,   138,
     449,   332,   -89,   -89,   430,    55,   217,   179,   -89,   -89,
      47,   140,   449,   314,   179,   -89,   -89,    55,    55,   449,
     -89,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    22,    21,     0,     0,    19,    20,     0,    11,    13,
      14,     0,    15,    16,    23,     0,     0,     1,    12,     0,
       0,    25,     0,    30,    25,     0,     0,    34,     0,     0,
       0,    24,    26,    72,    73,    75,    74,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    35,     0,
      28,     0,     0,    67,     0,    92,    91,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    31,     0,    36,    33,    29,
      39,    18,    27,     0,    66,    68,     0,    98,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    17,     0,    97,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    40,    41,    43,
      38,    42,    50,    69,     0,     0,     0,    67,     0,     0,
       0,     3,     0,    52,     0,    48,    64,     0,    70,    49,
      64,     0,     0,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    53,     0,    63,    70,    46,     0,
       0,    47,    51,    58,     0,     0,     0,     0,     0,     5,
       0,     0,    71,     0,    65,     0,    54,    56,     2,     0,
       4,     0,    44,    45,     0,     0,    10,     0,    62,    55,
      74,     0,     9,     0,     0,     7,     8,     0,     0,     6,
      61,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,   -89,   158,   -89,     1,   166,
     -89,   139,    90,    91,   144,   -24,   -48,   -89,   -89,   -88,
      57,   -89,    72,   -89,   -87,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   152,   179,   191,     7,     8,     9,    10,    29,    30,
      31,    32,    12,    13,    26,    27,   119,   102,   120,   121,
     155,   122,    83,    84,   156,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    11,    48,    81,    15,    22,    49,    22,    23,    11,
      23,    53,    24,    54,    25,    16,    25,    55,    56,    57,
      58,    59,   124,   125,   126,   137,   141,    47,   101,   127,
      17,   128,    86,    25,   158,   159,   161,   159,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     1,   106,     2,    19,    48,     3,    14,     5,     6,
     107,   106,   108,   109,   110,   111,   112,   113,   114,   107,
      20,   108,   109,   110,   111,   112,   113,   114,   176,   177,
      21,    28,   123,    46,    50,   194,   195,   196,    51,   134,
     138,   138,    53,    52,    54,    80,   115,   189,    76,    80,
     103,    77,   144,   116,    80,    25,   148,   149,   150,   200,
     201,   104,   129,   130,   157,   131,   132,   142,   157,   143,
      33,    34,    35,    36,   145,    37,    38,     1,   146,     2,
     151,   153,     3,     4,     5,     6,     1,   172,     2,   162,
     164,    39,    14,     5,     6,   168,   178,   180,   181,   169,
     171,   173,   170,   184,    40,   174,    41,    42,   133,   175,
     159,   182,    43,   185,   192,   193,    18,   183,    33,    34,
      35,    36,   199,    37,    38,    33,    34,    35,    36,   186,
      37,    38,    33,    34,    35,    36,   197,    37,    38,    39,
      45,    82,   117,   118,    79,     0,    39,   160,     0,   147,
       0,     0,    40,    39,    41,    42,   135,     0,     0,    40,
     136,    41,    42,   139,     0,     0,    40,   140,    41,    42,
      33,    34,    35,   190,    43,    37,    38,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    39,     0,    73,    74,     0,     0,     0,     0,     0,
       0,     0,   105,     0,    40,     0,    41,    42,     0,     0,
       0,     0,    43,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,     0,     0,    60,    61,    62,    63,    64,   165,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,    60,    61,    62,    63,    64,    87,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    73,    74,    60,
      61,    62,    63,    64,   166,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,    73,    74,    60,    61,    62,
      63,    64,   167,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,    60,    61,    62,    63,    64,
     198,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,     0,     0,     0,   187,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    73,    74,    75,    60,    61,    62,    63,
      64,     0,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,    73,    74,    78,    60,    61,    62,    63,    64,
       0,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,    73,    74,   154,    60,    61,    62,    63,    64,     0,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      73,    74,   163,    60,    61,    62,    63,    64,     0,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,    73,
      74,   188,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,    73,    74
};

static const yytype_int16 yycheck[] =
{
      22,     0,    26,    51,     3,    38,    28,    38,    41,     8,
      41,    45,    45,    47,    47,     6,    47,    39,    40,    41,
      42,    43,    38,    39,    40,   112,   113,    41,    76,    45,
       0,    47,    54,    47,    41,    42,    41,    42,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     5,     6,     7,     6,    79,    10,    11,    12,    13,
      14,     6,    16,    17,    18,    19,    20,    21,    22,    14,
       6,    16,    17,    18,    19,    20,    21,    22,   166,   167,
      45,    38,   104,     3,     6,    38,    39,    40,    46,   111,
     112,   113,    45,    42,    47,    49,    50,   185,    46,    49,
      46,    48,   124,   102,    49,    47,   128,   129,   130,   197,
     198,    42,    45,    45,   136,    45,    45,     6,   140,     6,
       3,     4,     5,     6,    41,     8,     9,     5,    41,     7,
       6,     6,    10,    11,    12,    13,     5,   159,     7,    41,
      46,    24,    11,    12,    13,    38,   168,   169,   170,    41,
      46,    46,    43,   175,    37,    41,    39,    40,    41,    38,
      42,    41,    45,    15,   186,   187,     8,    41,     3,     4,
       5,     6,   194,     8,     9,     3,     4,     5,     6,    41,
       8,     9,     3,     4,     5,     6,    46,     8,     9,    24,
      24,    52,   102,   102,    50,    -1,    24,   140,    -1,   127,
      -1,    -1,    37,    24,    39,    40,    41,    -1,    -1,    37,
      45,    39,    40,    41,    -1,    -1,    37,    45,    39,    40,
       3,     4,     5,     6,    45,     8,     9,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    24,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    37,    -1,    39,    40,    -1,    -1,
      -1,    -1,    45,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    -1,    -1,    23,    24,    25,    26,    27,    48,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    23,    24,    25,    26,    27,    46,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    40,    23,
      24,    25,    26,    27,    46,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    40,    23,    24,    25,
      26,    27,    46,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    40,    23,    24,    25,    26,    27,
      46,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    40,    41,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    41,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    40,    41,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    40,    41,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    41,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    10,    11,    12,    13,    55,    56,    57,
      58,    59,    63,    64,    11,    59,     6,     0,    57,     6,
       6,    45,    38,    41,    45,    47,    65,    66,    38,    59,
      60,    61,    62,     3,     4,     5,     6,     8,     9,    24,
      37,    39,    40,    45,    76,    60,     3,    41,    66,    76,
       6,    46,    42,    45,    47,    76,    76,    76,    76,    76,
      23,    24,    25,    26,    27,    29,    30,    31,    32,    33,
      34,    35,    36,    39,    40,    41,    46,    48,    41,    65,
      49,    67,    62,    73,    74,    76,    76,    46,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    67,    68,    46,    42,    48,     6,    14,    16,    17,
      18,    19,    20,    21,    22,    50,    59,    63,    64,    67,
      69,    70,    72,    76,    38,    39,    40,    45,    47,    45,
      45,    45,    45,    41,    76,    41,    45,    75,    76,    41,
      45,    75,     6,     6,    76,    41,    41,    73,    76,    76,
      76,     6,    52,     6,    41,    71,    75,    76,    41,    42,
      71,    41,    41,    41,    46,    48,    46,    46,    38,    41,
      43,    46,    76,    46,    41,    38,    70,    70,    76,    53,
      76,    76,    41,    41,    76,    15,    41,    44,    41,    70,
       6,    54,    76,    76,    38,    39,    40,    46,    46,    76,
      70,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    55,    56,    56,    57,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    64,    65,    65,    66,    67,    68,    68,
      69,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     1,     0,     3,     2,     2,     1,
       0,     1,     2,     1,     1,     1,     1,     6,     6,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     2,     3,
       3,     5,     4,     6,     1,     2,     3,     3,     2,     0,
       1,     1,     1,     1,     5,     5,     3,     3,     2,     2,
       1,     3,     2,     3,     5,     7,     5,     9,     4,     3,
       3,     9,     7,     1,     0,     5,     1,     0,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     4,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
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
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

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
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


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

  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
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
  yychar = YYEMPTY;
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
  case 2: /* for_init_opt: ID ASSIGN expression  */
#line 42 "parser.y"
                         { Trace("Reducing to for_init\n"); }
#line 1340 "parser.tab.c"
    break;

  case 3: /* for_init_opt: %empty  */
#line 43 "parser.y"
                { Trace("Reducing to for_init (empty)\n"); }
#line 1346 "parser.tab.c"
    break;

  case 4: /* expression_opt: expression  */
#line 46 "parser.y"
               { Trace("Reducing to for_condition\n"); }
#line 1352 "parser.tab.c"
    break;

  case 5: /* expression_opt: %empty  */
#line 47 "parser.y"
                { Trace("Reducing to for_condition (empty)\n"); }
#line 1358 "parser.tab.c"
    break;

  case 6: /* for_step_opt: ID ASSIGN expression  */
#line 50 "parser.y"
                         { Trace("Reducing to for_step (assign)\n"); }
#line 1364 "parser.tab.c"
    break;

  case 7: /* for_step_opt: ID INC  */
#line 51 "parser.y"
           { Trace("Reducing to for_step (inc)\n"); }
#line 1370 "parser.tab.c"
    break;

  case 8: /* for_step_opt: ID DEC  */
#line 52 "parser.y"
           { Trace("Reducing to for_step (dec)\n"); }
#line 1376 "parser.tab.c"
    break;

  case 9: /* for_step_opt: expression  */
#line 53 "parser.y"
               { Trace("Reducing to for_step (expr)\n"); }
#line 1382 "parser.tab.c"
    break;

  case 10: /* for_step_opt: %empty  */
#line 54 "parser.y"
                { Trace("Reducing to for_step (empty)\n"); }
#line 1388 "parser.tab.c"
    break;

  case 11: /* program: decl_list  */
#line 57 "parser.y"
              { Trace("Reducing to program\n"); }
#line 1394 "parser.tab.c"
    break;

  case 12: /* decl_list: decl_list declaration  */
#line 61 "parser.y"
                          { Trace("Reducing to decl_list\n"); }
#line 1400 "parser.tab.c"
    break;

  case 13: /* decl_list: declaration  */
#line 62 "parser.y"
                  { Trace("Reducing to decl_list\n"); }
#line 1406 "parser.tab.c"
    break;

  case 14: /* declaration: func_decl  */
#line 66 "parser.y"
                { Trace("Reducing to func_decl\n"); }
#line 1412 "parser.tab.c"
    break;

  case 15: /* declaration: var_decl  */
#line 67 "parser.y"
               { Trace("Reducing to var_decl\n"); }
#line 1418 "parser.tab.c"
    break;

  case 16: /* declaration: const_decl  */
#line 68 "parser.y"
                 { Trace("Reducing to const_decl\n"); }
#line 1424 "parser.tab.c"
    break;

  case 17: /* func_decl: type ID LPAREN param_list_opt RPAREN block  */
#line 72 "parser.y"
                                                 { Trace("Reducing to func_decl (typed)\n"); }
#line 1430 "parser.tab.c"
    break;

  case 18: /* func_decl: VOID ID LPAREN param_list_opt RPAREN block  */
#line 73 "parser.y"
                                                 { Trace("Reducing to func_decl (void)\n"); }
#line 1436 "parser.tab.c"
    break;

  case 19: /* type: INT  */
#line 77 "parser.y"
             { Trace("Reducing to type (int)\n"); (yyval.ival) = 0; }
#line 1442 "parser.tab.c"
    break;

  case 20: /* type: FLOAT  */
#line 78 "parser.y"
             { Trace("Reducing to type (float)\n"); (yyval.ival) = 1; }
#line 1448 "parser.tab.c"
    break;

  case 21: /* type: BOOL  */
#line 79 "parser.y"
             { Trace("Reducing to type (bool)\n"); (yyval.ival) = 2; }
#line 1454 "parser.tab.c"
    break;

  case 22: /* type: STRING  */
#line 80 "parser.y"
             { Trace("Reducing to type (string)\n"); (yyval.ival) = 3; }
#line 1460 "parser.tab.c"
    break;

  case 23: /* type: VOID  */
#line 81 "parser.y"
             { Trace("Reducing to type (void)\n"); (yyval.ival) = 4; }
#line 1466 "parser.tab.c"
    break;

  case 24: /* param_list_opt: param_list  */
#line 85 "parser.y"
               { Trace("Reducing to param_list_opt\n"); }
#line 1472 "parser.tab.c"
    break;

  case 25: /* param_list_opt: %empty  */
#line 86 "parser.y"
                  { Trace("Reducing to param_list_opt (empty)\n"); }
#line 1478 "parser.tab.c"
    break;

  case 26: /* param_list: param  */
#line 90 "parser.y"
          { Trace("Reducing to param_list\n"); }
#line 1484 "parser.tab.c"
    break;

  case 27: /* param_list: param_list COMMA param  */
#line 91 "parser.y"
                             { Trace("Reducing to param_list\n"); }
#line 1490 "parser.tab.c"
    break;

  case 28: /* param: type ID  */
#line 95 "parser.y"
              {
          Trace("Reducing to param\n");
          symboltable_insert(global_table, (yyvsp[0].sval), (yyvsp[-1].ival));
      }
#line 1499 "parser.tab.c"
    break;

  case 29: /* param: type ID array_size_list  */
#line 99 "parser.y"
                              {
          Trace("Reducing to array_param\n");
          symboltable_insert(global_table, (yyvsp[-1].sval), (yyvsp[-2].ival));
      }
#line 1508 "parser.tab.c"
    break;

  case 30: /* var_decl: type ID SEMICOLON  */
#line 106 "parser.y"
                        {
        Trace("Reducing to var_decl (single)\n");
        symboltable_insert(global_table, (yyvsp[-1].sval), (yyvsp[-2].ival));
    }
#line 1517 "parser.tab.c"
    break;

  case 31: /* var_decl: type ID ASSIGN expression SEMICOLON  */
#line 110 "parser.y"
                                          {
        Trace("Reducing to var_decl (init)\n");
        symboltable_insert(global_table, (yyvsp[-3].sval), (yyvsp[-4].ival));
    }
#line 1526 "parser.tab.c"
    break;

  case 32: /* var_decl: type ID array_size_list SEMICOLON  */
#line 114 "parser.y"
                                        {
        Trace("Reducing to var_decl (array)\n");
        symboltable_insert(global_table, (yyvsp[-2].sval), (yyvsp[-3].ival)); 
    }
#line 1535 "parser.tab.c"
    break;

  case 33: /* const_decl: CONST type ID ASSIGN expression SEMICOLON  */
#line 121 "parser.y"
                                              {
        Trace("Reducing to const_decl\n");
        symboltable_insert(global_table, (yyvsp[-3].sval), (yyvsp[-4].ival));
    }
#line 1544 "parser.tab.c"
    break;

  case 34: /* array_size_list: array_size  */
#line 128 "parser.y"
               { Trace("Reducing to array_size_list\n"); }
#line 1550 "parser.tab.c"
    break;

  case 35: /* array_size_list: array_size_list array_size  */
#line 129 "parser.y"
                                 { Trace("Reducing to array_size_list\n"); }
#line 1556 "parser.tab.c"
    break;

  case 36: /* array_size: LBRACK INTNUM RBRACK  */
#line 133 "parser.y"
                         { Trace("Reducing to array_size\n"); }
#line 1562 "parser.tab.c"
    break;

  case 37: /* block: LBRACE decl_or_stmt_list RBRACE  */
#line 137 "parser.y"
                                    { Trace("Reducing to block\n"); }
#line 1568 "parser.tab.c"
    break;

  case 38: /* decl_or_stmt_list: decl_or_stmt_list decl_or_stmt  */
#line 141 "parser.y"
                                   { Trace("Reducing to decl_or_stmt_list\n"); }
#line 1574 "parser.tab.c"
    break;

  case 39: /* decl_or_stmt_list: %empty  */
#line 142 "parser.y"
                  { Trace("Reducing to decl_or_stmt_list (empty)\n"); }
#line 1580 "parser.tab.c"
    break;

  case 43: /* statement: block  */
#line 152 "parser.y"
            { Trace("Reducing to block as statement\n"); }
#line 1586 "parser.tab.c"
    break;

  case 44: /* statement: PRINT LPAREN print_args RPAREN SEMICOLON  */
#line 153 "parser.y"
                                               { Trace("Reducing to print_stmt\n"); }
#line 1592 "parser.tab.c"
    break;

  case 45: /* statement: PRINTLN LPAREN print_args RPAREN SEMICOLON  */
#line 154 "parser.y"
                                                 { Trace("Reducing to println_stmt\n"); }
#line 1598 "parser.tab.c"
    break;

  case 46: /* statement: PRINT expression_list SEMICOLON  */
#line 155 "parser.y"
                                      { Trace("Reducing to print_stmt (no parens)\n"); }
#line 1604 "parser.tab.c"
    break;

  case 47: /* statement: PRINTLN expression_list SEMICOLON  */
#line 156 "parser.y"
                                        { Trace("Reducing to println_stmt (no parens)\n"); }
#line 1610 "parser.tab.c"
    break;

  case 48: /* statement: PRINT SEMICOLON  */
#line 157 "parser.y"
                      { Trace("Reducing to print_stmt (empty)\n"); }
#line 1616 "parser.tab.c"
    break;

  case 49: /* statement: PRINTLN SEMICOLON  */
#line 158 "parser.y"
                        { Trace("Reducing to println_stmt (empty)\n"); }
#line 1622 "parser.tab.c"
    break;

  case 50: /* statement: proc_call_stmt  */
#line 159 "parser.y"
                     { Trace("Reducing to proc_call_stmt\n"); }
#line 1628 "parser.tab.c"
    break;

  case 51: /* statement: READ ID SEMICOLON  */
#line 160 "parser.y"
                        { Trace("Reducing to read_stmt\n"); }
#line 1634 "parser.tab.c"
    break;

  case 52: /* statement: RETURN SEMICOLON  */
#line 161 "parser.y"
                       { Trace("Reducing to return_stmt (empty)\n"); }
#line 1640 "parser.tab.c"
    break;

  case 53: /* statement: RETURN expression SEMICOLON  */
#line 162 "parser.y"
                                  { Trace("Reducing to return_stmt\n"); }
#line 1646 "parser.tab.c"
    break;

  case 54: /* statement: IF LPAREN expression RPAREN statement  */
#line 163 "parser.y"
                                            { Trace("Reducing to if_stmt\n"); }
#line 1652 "parser.tab.c"
    break;

  case 55: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 164 "parser.y"
                                                           { Trace("Reducing to if_else_stmt\n"); }
#line 1658 "parser.tab.c"
    break;

  case 56: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 165 "parser.y"
                                               { Trace("Reducing to while_stmt\n"); }
#line 1664 "parser.tab.c"
    break;

  case 57: /* statement: FOREACH LPAREN ID COLON expression DOTDOT expression RPAREN statement  */
#line 166 "parser.y"
                                                                            { Trace("Reducing to foreach_stmt\n"); }
#line 1670 "parser.tab.c"
    break;

  case 58: /* statement: ID ASSIGN expression SEMICOLON  */
#line 167 "parser.y"
                                     { Trace("Reducing to assignment_stmt\n"); }
#line 1676 "parser.tab.c"
    break;

  case 59: /* statement: ID INC SEMICOLON  */
#line 168 "parser.y"
                       { Trace("Reducing to inc_stmt\n"); }
#line 1682 "parser.tab.c"
    break;

  case 60: /* statement: ID DEC SEMICOLON  */
#line 169 "parser.y"
                       { Trace("Reducing to dec_stmt\n"); }
#line 1688 "parser.tab.c"
    break;

  case 61: /* statement: FOR LPAREN for_init_opt SEMICOLON expression_opt SEMICOLON for_step_opt RPAREN statement  */
#line 170 "parser.y"
                                                                                               { Trace("Reducing to for_stmt (with options)\n"); }
#line 1694 "parser.tab.c"
    break;

  case 62: /* statement: ID LBRACK expression RBRACK ASSIGN expression SEMICOLON  */
#line 171 "parser.y"
                                                              { Trace("Reducing to array_assign_stmt\n"); }
#line 1700 "parser.tab.c"
    break;

  case 63: /* print_args: expression_list  */
#line 175 "parser.y"
                    { Trace("Reducing to print_args\n"); }
#line 1706 "parser.tab.c"
    break;

  case 64: /* print_args: %empty  */
#line 176 "parser.y"
                  { Trace("Reducing to print_args (empty)\n"); }
#line 1712 "parser.tab.c"
    break;

  case 65: /* proc_call_stmt: ID LPAREN arg_list_opt RPAREN SEMICOLON  */
#line 180 "parser.y"
                                            { Trace("Reducing to proc_call_stmt\n"); }
#line 1718 "parser.tab.c"
    break;

  case 66: /* arg_list_opt: arg_list  */
#line 184 "parser.y"
             { Trace("Reducing to arg_list_opt\n"); }
#line 1724 "parser.tab.c"
    break;

  case 67: /* arg_list_opt: %empty  */
#line 185 "parser.y"
                  { Trace("Reducing to arg_list_opt (empty)\n"); }
#line 1730 "parser.tab.c"
    break;

  case 68: /* arg_list: expression  */
#line 189 "parser.y"
               { Trace("Reducing to arg_list\n"); }
#line 1736 "parser.tab.c"
    break;

  case 69: /* arg_list: arg_list COMMA expression  */
#line 190 "parser.y"
                                { Trace("Reducing to arg_list\n"); }
#line 1742 "parser.tab.c"
    break;

  case 70: /* expression_list: expression  */
#line 194 "parser.y"
               { Trace("Reducing to expression_list\n"); }
#line 1748 "parser.tab.c"
    break;

  case 71: /* expression_list: expression_list COMMA expression  */
#line 195 "parser.y"
                                       { Trace("Reducing to expression_list\n"); }
#line 1754 "parser.tab.c"
    break;

  case 72: /* expression: INTNUM  */
#line 199 "parser.y"
             { Trace("Reducing to expression (int)\n"); }
#line 1760 "parser.tab.c"
    break;

  case 73: /* expression: FLOATNUM  */
#line 200 "parser.y"
               { Trace("Reducing to expression (float)\n"); }
#line 1766 "parser.tab.c"
    break;

  case 74: /* expression: ID  */
#line 201 "parser.y"
         { Trace("Reducing to expression (id)\n"); }
#line 1772 "parser.tab.c"
    break;

  case 75: /* expression: STRING  */
#line 202 "parser.y"
             { Trace("Reducing to expression (string)\n"); }
#line 1778 "parser.tab.c"
    break;

  case 76: /* expression: TRUE  */
#line 203 "parser.y"
           { Trace("Reducing to expression (true)\n"); }
#line 1784 "parser.tab.c"
    break;

  case 77: /* expression: FALSE  */
#line 204 "parser.y"
            { Trace("Reducing to expression (false)\n"); }
#line 1790 "parser.tab.c"
    break;

  case 78: /* expression: expression PLUS expression  */
#line 205 "parser.y"
                                 { Trace("Reducing to expression (+)\n"); }
#line 1796 "parser.tab.c"
    break;

  case 79: /* expression: expression MINUS expression  */
#line 206 "parser.y"
                                  { Trace("Reducing to expression (-)\n"); }
#line 1802 "parser.tab.c"
    break;

  case 80: /* expression: expression STAR expression  */
#line 207 "parser.y"
                                 { Trace("Reducing to expression (*)\n"); }
#line 1808 "parser.tab.c"
    break;

  case 81: /* expression: expression SLASH expression  */
#line 208 "parser.y"
                                  { Trace("Reducing to expression (/)\n"); }
#line 1814 "parser.tab.c"
    break;

  case 82: /* expression: expression MOD expression  */
#line 209 "parser.y"
                                { Trace("Reducing to expression (%%)\n"); }
#line 1820 "parser.tab.c"
    break;

  case 83: /* expression: expression LT expression  */
#line 210 "parser.y"
                               { Trace("Reducing to expression (<)\n"); }
#line 1826 "parser.tab.c"
    break;

  case 84: /* expression: expression LE expression  */
#line 211 "parser.y"
                               { Trace("Reducing to expression (<=)\n"); }
#line 1832 "parser.tab.c"
    break;

  case 85: /* expression: expression EQ expression  */
#line 212 "parser.y"
                               { Trace("Reducing to expression (==)\n"); }
#line 1838 "parser.tab.c"
    break;

  case 86: /* expression: expression GE expression  */
#line 213 "parser.y"
                               { Trace("Reducing to expression (>=)\n"); }
#line 1844 "parser.tab.c"
    break;

  case 87: /* expression: expression GT expression  */
#line 214 "parser.y"
                               { Trace("Reducing to expression (>)\n"); }
#line 1850 "parser.tab.c"
    break;

  case 88: /* expression: expression NE expression  */
#line 215 "parser.y"
                               { Trace("Reducing to expression (!=)\n"); }
#line 1856 "parser.tab.c"
    break;

  case 89: /* expression: expression AND expression  */
#line 216 "parser.y"
                                { Trace("Reducing to expression (&&)\n"); }
#line 1862 "parser.tab.c"
    break;

  case 90: /* expression: expression OR expression  */
#line 217 "parser.y"
                               { Trace("Reducing to expression (||)\n"); }
#line 1868 "parser.tab.c"
    break;

  case 91: /* expression: NOT expression  */
#line 218 "parser.y"
                     { Trace("Reducing to expression (!)\n"); }
#line 1874 "parser.tab.c"
    break;

  case 92: /* expression: MINUS expression  */
#line 219 "parser.y"
                                    { Trace("Reducing to expression (unary -)\n"); }
#line 1880 "parser.tab.c"
    break;

  case 93: /* expression: INC expression  */
#line 220 "parser.y"
                     { Trace("Reducing to expression (prefix ++)\n"); }
#line 1886 "parser.tab.c"
    break;

  case 94: /* expression: DEC expression  */
#line 221 "parser.y"
                     { Trace("Reducing to expression (prefix --)\n"); }
#line 1892 "parser.tab.c"
    break;

  case 95: /* expression: expression INC  */
#line 222 "parser.y"
                     { Trace("Reducing to expression (postfix ++)\n"); }
#line 1898 "parser.tab.c"
    break;

  case 96: /* expression: expression DEC  */
#line 223 "parser.y"
                     { Trace("Reducing to expression (postfix --)\n"); }
#line 1904 "parser.tab.c"
    break;

  case 97: /* expression: ID LPAREN arg_list_opt RPAREN  */
#line 224 "parser.y"
                                    { Trace("Reducing to function_call_expr\n"); }
#line 1910 "parser.tab.c"
    break;

  case 98: /* expression: LPAREN expression RPAREN  */
#line 225 "parser.y"
                               { Trace("Reducing to expression (group)\n"); }
#line 1916 "parser.tab.c"
    break;

  case 99: /* expression: ID LBRACK expression RBRACK  */
#line 226 "parser.y"
                                  { Trace("Reducing to array_access_expr\n"); }
#line 1922 "parser.tab.c"
    break;


#line 1926 "parser.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
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
  if (yychar != YYEMPTY)
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

#line 229 "parser.y"


void yyerror(const char *msg) {
    fprintf(stderr, "Error at line %d: %s (token: %s)\n", yylineno, msg, yytext);
}

int main(int argc, char *argv[]) {
    global_table = symboltable_create(256);

    if (argc == 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    } else {
        yyin = stdin;
    }

    int result = yyparse();

    printf("\n=== Symbol Table Dump ===\n");
    symboltable_dump(global_table); 

    return result;
}
