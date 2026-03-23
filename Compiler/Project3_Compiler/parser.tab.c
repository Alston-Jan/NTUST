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
#include "codegen.h"

#define Trace(t) printf(t)

#define TYPE_INT 0
#define TYPE_BOOL 1
#define TYPE_VOID 2

#define MAX_ARGS 10
#define MAX_LINES 1000
char* source_lines[MAX_LINES];  // 一行一個 char*
int source_line_count = 0;
typedef struct {
    char* name;
    int param_types[MAX_ARGS];
    int param_count;
    int return_type;
} func_signature;

func_signature functions[100];
int func_count = 0;
int param_types_temp[MAX_ARGS];
int param_count_temp = 0;
int arg_pass_types[MAX_ARGS];
int arg_pass_count = 0;
int yylex(void);
int current_type = -1;
int current_function_return_type = -1;
int had_error = 0;
int param_index = 0;
void yyerror(const char *msg);
void symboltable_reset_local_index(symboltable* table);
char *classname = NULL;

extern symboltable* symboltable_stack; 
extern int yylineno;
extern char *yytext;
extern FILE *yyin;
extern char current_line[1024];
extern FILE *out; 

const char* yyin_filename;

static int emitted_main_epilogue = 0;
static int emitted_class_closure = 0;
static int parse_completed = 0;

// 從路徑取得 class name（例如 test.sd → test）
char *get_class_name(const char *filepath) {
    const char *base = strrchr(filepath, '/');
    base = base ? base + 1 : filepath;
    char *dot = strrchr(base, '.');
    size_t len = dot ? (size_t)(dot - base) : strlen(base);
    char *classname = malloc(len + 1);
    strncpy(classname, base, len);
    classname[len] = '\0';
    return classname;
}

void emit_source_comment() {
    if (strlen(current_line) > 0)
        fprintf(out, "/* %d: %s */\n", yylineno, current_line);
}

void register_function(const char* name, int ret_type, int* params, int count) {
    functions[func_count].name = strdup(name);
    functions[func_count].return_type = ret_type;
    functions[func_count].param_count = count;
    for (int i = 0; i < count; i++) {
        functions[func_count].param_types[i] = params[i];
    }
    func_count++;
}

func_signature* lookup_function(const char* name) {
    for (int i = 0; i < func_count; i++) {
        if (strcmp(functions[i].name, name) == 0) return &functions[i];
    }
    return NULL;
}

#line 158 "parser.tab.c"

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
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_STRINGLIT = 5,                  /* STRINGLIT  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_COLON = 7,                      /* COLON  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_TRUE = 9,                       /* TRUE  */
  YYSYMBOL_FALSE = 10,                     /* FALSE  */
  YYSYMBOL_CONST = 11,                     /* CONST  */
  YYSYMBOL_VOID = 12,                      /* VOID  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_FOREACH = 18,                   /* FOREACH  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_PRINT = 20,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 21,                   /* PRINTLN  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_STAR = 24,                      /* STAR  */
  YYSYMBOL_SLASH = 25,                     /* SLASH  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_UMINUS = 27,                    /* UMINUS  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_LE = 29,                        /* LE  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_NE = 33,                        /* NE  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_DOTDOT = 37,                    /* DOTDOT  */
  YYSYMBOL_ASSIGN = 38,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_LPAREN = 41,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 42,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 43,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 44,                    /* RBRACE  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_decl_list = 48,                 /* decl_list  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_func_decl = 50,                 /* func_decl  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_var_decl = 55,                  /* var_decl  */
  YYSYMBOL_const_decl = 56,                /* const_decl  */
  YYSYMBOL_block = 57,                     /* block  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_decl_or_stmt_list = 59,         /* decl_or_stmt_list  */
  YYSYMBOL_decl_or_stmt = 60,              /* decl_or_stmt  */
  YYSYMBOL_args_passed = 61,               /* args_passed  */
  YYSYMBOL_param_list = 62,                /* param_list  */
  YYSYMBOL_param = 63,                     /* param  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_expression_list = 65,           /* expression_list  */
  YYSYMBOL_expression = 66                 /* expression  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   119,   119,   119,   144,   145,   149,   150,   151,   156,
     156,   182,   184,   182,   204,   205,   206,   211,   226,   243,
     264,   270,   270,   275,   287,   294,   295,   299,   300,   301,
     305,   306,   310,   316,   317,   321,   328,   329,   345,   349,
     353,   357,   372,   378,   385,   394,   399,   408,   417,   428,
     440,   458,   459,   463,   467,   471,   489,   504,   508,   509,
     513,   517,   521,   525,   529,   533,   537,   541,   545,   549,
     553,   557,   561
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
  "\"end of file\"", "error", "\"invalid token\"", "INTNUM", "STRING",
  "STRINGLIT", "ID", "COLON", "BOOL", "TRUE", "FALSE", "CONST", "VOID",
  "INT", "IF", "ELSE", "WHILE", "FOR", "FOREACH", "RETURN", "PRINT",
  "PRINTLN", "PLUS", "MINUS", "STAR", "SLASH", "MOD", "UMINUS", "LT", "LE",
  "EQ", "GE", "GT", "NE", "AND", "OR", "NOT", "DOTDOT", "ASSIGN",
  "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "$accept",
  "program", "$@1", "decl_list", "declaration", "func_decl", "$@2", "$@3",
  "$@4", "type", "var_decl", "const_decl", "block", "$@5",
  "decl_or_stmt_list", "decl_or_stmt", "args_passed", "param_list",
  "param", "statement", "expression_list", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,     9,    72,   -92,     1,   -92,    41,   -92,   -92,    72,
     -92,   -92,    44,   -92,   -92,    28,    49,   -92,    52,   -92,
     -92,    17,    28,    28,    28,   256,    32,    28,   -92,    39,
      28,   140,   452,   181,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,   -92,    28,   274,
     -92,    41,   -36,   452,   -92,   464,   464,   140,   140,   140,
     452,   452,   452,   452,   452,   452,   452,   452,   292,   -92,
      53,    92,    23,   -92,    28,   -92,   -92,    24,   -92,   -92,
      41,   -92,   452,    71,   -92,   133,   -92,    53,   -92,    93,
      61,    78,    79,    80,    81,    82,    56,    28,   161,   113,
     -92,   -92,   -92,   -92,   -92,   -92,    61,   -92,   -92,    28,
      28,    28,   118,   120,   -92,   310,   -11,   328,    90,    91,
      33,   346,    64,   364,   196,   211,    94,   124,   -92,   -92,
      28,   -92,   -92,   -92,   -92,   -92,   -92,   142,   142,    28,
      28,   452,    95,   125,   -92,   382,   436,    28,   142,    28,
      28,   400,   -92,   418,   226,   -92,   129,   142,   104,   -92,
      28,   241,   142,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    15,     0,    16,    14,     3,
       5,     6,     0,     7,     8,     0,     0,     4,     0,    53,
      54,    55,     0,     0,     0,     0,     0,     0,    17,    11,
      30,    57,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       9,     0,     0,    31,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    68,    69,    67,    70,    71,     0,    18,
       0,     0,     0,    33,     0,    56,    20,     0,    10,    35,
       0,    12,    32,     0,    26,     0,    34,     0,    24,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,    36,    25,    29,    13,     0,    22,    45,     0,
       0,     0,     0,     0,    43,     0,     0,    51,     0,    54,
       0,    51,     0,     0,     0,     0,     0,     0,    44,    38,
       0,    37,    40,    42,    39,    41,    19,     0,     0,     0,
       0,    52,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,    48,     0,     0,     0,    50,
       0,     0,     0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -92,   146,   -92,   -92,   -92,   -92,    -3,
     -78,   -29,   -60,   -92,    73,   -92,   -92,   -92,    97,   -91,
      83,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     9,    10,    11,    70,    51,    87,    12,
      13,    14,   102,    84,    85,   103,    52,    72,    73,   104,
     116,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    32,    33,    16,    74,    49,    75,   100,    53,     3,
      78,   100,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    83,    68,   105,   129,   130,
     -21,    19,   -21,    20,    21,   -21,   -21,   -21,   -21,    15,
     -21,   -21,   -21,   -21,   -21,   -21,   143,   144,    71,     5,
      18,    22,    82,     7,     8,    26,   101,   152,    30,    19,
     101,    20,    21,    80,    23,    81,   159,   -21,   -21,    24,
      48,   163,   134,   130,   115,   117,   121,    71,     4,    22,
       5,    50,    99,     6,     7,     8,    99,   123,   124,   125,
      27,    28,    23,    29,   106,   114,    77,    24,    79,    91,
     108,     5,    27,    28,     6,     7,     8,    92,   141,    93,
      94,    95,    96,    97,    98,    88,   109,   145,   146,   122,
     110,   111,   112,   113,   126,   151,   127,   153,   154,   132,
     133,   140,   139,   147,    90,   158,    77,   107,   161,    91,
     148,     5,   160,   106,     6,     7,     8,    92,   142,    93,
      94,    95,    96,    97,    98,    17,    92,    89,    93,    94,
      95,    96,    97,    98,    19,   118,   119,    21,    39,    40,
      41,    42,    43,    44,    45,    46,    77,    86,     0,     0,
       0,   120,     0,     0,    22,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,    24,    34,    35,    36,    37,    38,     0,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    34,    35,
      36,    37,    38,    54,    39,    40,    41,    42,    43,    44,
      45,    46,     0,    34,    35,    36,    37,    38,   137,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    34,    35,
      36,    37,    38,   138,    39,    40,    41,    42,    43,    44,
      45,    46,     0,    34,    35,    36,    37,    38,   157,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    34,    35,
      36,    37,    38,   162,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,     0,    47,    34,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
       0,     0,     0,    69,    34,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    46,     0,     0,
       0,    76,    34,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,     0,     0,     0,   128,
      34,    35,    36,    37,    38,     0,    39,    40,    41,    42,
      43,    44,    45,    46,     0,     0,     0,   131,    34,    35,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,     0,   135,    34,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
       0,     0,     0,   136,    34,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    46,     0,     0,
       0,   149,    34,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,     0,     0,     0,   155,
      34,    35,    36,    37,    38,     0,    39,    40,    41,    42,
      43,    44,    45,    46,     0,     0,     0,   156,    34,    35,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
      45,    46,     0,   150,    34,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46
};

static const yytype_int16 yycheck[] =
{
      22,    23,    24,     6,    40,    27,    42,    85,    30,     0,
      70,    89,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     1,    48,    87,    39,    40,
       6,     3,     8,     5,     6,    11,    12,    13,    14,    38,
      16,    17,    18,    19,    20,    21,   137,   138,    51,     8,
       6,    23,    74,    12,    13,     6,    85,   148,    41,     3,
      89,     5,     6,    40,    36,    42,   157,    43,    44,    41,
      38,   162,    39,    40,    96,    97,    98,    80,     6,    23,
       8,    42,    85,    11,    12,    13,    89,   109,   110,   111,
      38,    39,    36,    41,     1,    39,    43,    41,     6,     6,
      39,     8,    38,    39,    11,    12,    13,    14,   130,    16,
      17,    18,    19,    20,    21,    44,    38,   139,   140,     6,
      41,    41,    41,    41,     6,   147,     6,   149,   150,    39,
      39,     7,    38,    38,     1,     6,    43,    44,   160,     6,
      15,     8,    38,     1,    11,    12,    13,    14,     6,    16,
      17,    18,    19,    20,    21,     9,    14,    84,    16,    17,
      18,    19,    20,    21,     3,     4,     5,     6,    28,    29,
      30,    31,    32,    33,    34,    35,    43,    80,    -1,    -1,
      -1,    98,    -1,    -1,    23,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    41,    22,    23,    24,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    22,    23,
      24,    25,    26,    42,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    22,    23,    24,    25,    26,    42,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    22,    23,
      24,    25,    26,    42,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    22,    23,    24,    25,    26,    42,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    22,    23,
      24,    25,    26,    42,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    22,    23,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,    22,    23,    24,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,     0,     6,     8,    11,    12,    13,    48,
      49,    50,    54,    55,    56,    38,    54,    49,     6,     3,
       5,     6,    23,    36,    41,    66,     6,    38,    39,    41,
      41,    66,    66,    66,    22,    23,    24,    25,    26,    28,
      29,    30,    31,    32,    33,    34,    35,    39,    38,    66,
      42,    52,    61,    66,    42,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    39,
      51,    54,    62,    63,    40,    42,    39,    43,    57,     6,
      40,    42,    66,     1,    58,    59,    63,    53,    44,    59,
       1,     6,    14,    16,    17,    18,    19,    20,    21,    54,
      55,    56,    57,    60,    64,    57,     1,    44,    39,    38,
      41,    41,    41,    41,    39,    66,    65,    66,     4,     5,
      65,    66,     6,    66,    66,    66,     6,     6,    39,    39,
      40,    39,    39,    39,    39,    39,    39,    42,    42,    38,
       7,    66,     6,    64,    64,    66,    66,    38,    15,    39,
      37,    66,    64,    66,    66,    39,    39,    42,     6,    64,
      38,    66,    42,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    49,    49,    51,
      50,    52,    53,    50,    54,    54,    54,    55,    55,    55,
      56,    58,    57,    57,    57,    59,    59,    60,    60,    60,
      61,    61,    61,    62,    62,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     0,
       6,     0,     0,     8,     1,     1,     1,     3,     5,     4,
       6,     0,     4,     3,     3,     2,     0,     1,     1,     1,
       0,     1,     3,     1,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     2,     3,     2,     7,     5,     4,    13,
       9,     1,     3,     1,     1,     1,     4,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2
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
  case 2: /* $@1: %empty  */
#line 119 "parser.y"
    {
        symboltable_push();
        classname = get_class_name(yyin_filename);
        init_codegen(classname);
        fprintf(out, "class %s {\n", classname);
    }
#line 1385 "parser.tab.c"
    break;

  case 3: /* program: $@1 decl_list  */
#line 126 "parser.y"
    {
        if (!had_error) {
            if (!emitted_main_epilogue) {
                emit_main_epilogue();
                emitted_main_epilogue = 1;
            }
            if (!emitted_class_closure) {
                finalize_codegen(classname);
                emitted_class_closure = 1;
            }
        }
        parse_completed = 1;
        free(classname);
        symboltable_pop();
    }
#line 1405 "parser.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 156 "parser.y"
                          {
        current_function_return_type = (yyvsp[-3].ival);
        register_function((yyvsp[-2].sval), (yyvsp[-3].ival), NULL, 0);

        if (strcmp((yyvsp[-2].sval), "main") == 0) {
            if ((yyvsp[-3].ival) != TYPE_VOID) {
                yyerror("main function must be declared as 'void main()'");
            }
            emit_main_prologue();  // 正確產生 main(java.lang.String[])
        } else {
            const char *ret_str = ((yyvsp[-3].ival) == 0) ? "int" :
                                  ((yyvsp[-3].ival) == 1) ? "boolean" : "void";
            emit_function_start((yyvsp[-2].sval), ret_str, 0, NULL);
        }

        symboltable_push();
    }
#line 1427 "parser.tab.c"
    break;

  case 10: /* func_decl: type ID LPAREN RPAREN $@2 block  */
#line 172 "parser.y"
            {
        // 如果是 void 函式（例如 main），補上 return
        if (current_function_return_type == TYPE_VOID) {
            codegen_emit_return();
        }
        codegen_emit_function_epilogue();
        symboltable_pop();
    }
#line 1440 "parser.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 182 "parser.y"
                     {
        symboltable_push();  // ⚠️ 先建立 scope 再處理 param
      }
#line 1448 "parser.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 184 "parser.y"
                          {
        current_function_return_type = (yyvsp[-5].ival);
        register_function((yyvsp[-4].sval), (yyvsp[-5].ival), param_types_temp, param_count_temp);
        symboltable_reset_local_index(symboltable_top());

        const char *ret_str = ((yyvsp[-5].ival) == 0) ? "int" :
                              ((yyvsp[-5].ival) == 1) ? "boolean" : "void";
        emit_function_start((yyvsp[-4].sval), ret_str, param_count_temp, param_types_temp);

        param_count_temp = 0;
      }
#line 1464 "parser.tab.c"
    break;

  case 13: /* func_decl: type ID LPAREN $@3 param_list RPAREN $@4 block  */
#line 194 "parser.y"
              {
        if (current_function_return_type == TYPE_VOID) {
            codegen_emit_return();
        }
        codegen_emit_function_epilogue();
        symboltable_pop();
      }
#line 1476 "parser.tab.c"
    break;

  case 14: /* type: INT  */
#line 204 "parser.y"
             { (yyval.ival) = 0; }
#line 1482 "parser.tab.c"
    break;

  case 15: /* type: BOOL  */
#line 205 "parser.y"
             { (yyval.ival) = 1; }
#line 1488 "parser.tab.c"
    break;

  case 16: /* type: VOID  */
#line 206 "parser.y"
             { (yyval.ival) = 2; }
#line 1494 "parser.tab.c"
    break;

  case 17: /* var_decl: type ID SEMICOLON  */
#line 211 "parser.y"
                        {
        emit_source_comment();

        if (symboltable_top()->prev == NULL) {
            // 在 global scope
            symboltable_insert_global((yyvsp[-1].sval), (yyvsp[-2].ival));
            fprintf(out, "field static %s %s\n", 
                (yyvsp[-2].ival) == 0 ? "int" : "boolean", (yyvsp[-1].sval));
        } else {
            // local scope
            symboltable_allocate_local(symboltable_top(), (yyvsp[-1].sval), (yyvsp[-2].ival));
        }
      }
#line 1512 "parser.tab.c"
    break;

  case 18: /* var_decl: type ID ASSIGN expression SEMICOLON  */
#line 226 "parser.y"
                                          {
        emit_source_comment();

        if (symboltable_top()->prev == NULL) {
            // global scope
            symboltable_insert_global((yyvsp[-3].sval), (yyvsp[-4].ival));
            fprintf(out, "field static %s %s\n", 
                (yyvsp[-4].ival) == 0 ? "int" : "boolean", (yyvsp[-3].sval));
            codegen_emit_store_variable((yyvsp[-3].sval));  // putstatic
        } else {
            // local scope
            int idx = symboltable_allocate_local(symboltable_top(), (yyvsp[-3].sval), (yyvsp[-4].ival));
            emit_istore(idx);  // istore
        }
      }
#line 1532 "parser.tab.c"
    break;

  case 19: /* var_decl: ID ASSIGN expression SEMICOLON  */
#line 243 "parser.y"
                                     {
        emit_source_comment();

        int tmp;
        if (symboltable_lookup_const(symboltable_top(), (yyvsp[-3].sval), &tmp)) {
            yyerror("assignment error: cannot assign to a constant");
        }

        int idx = symboltable_get_local_index(symboltable_top(), (yyvsp[-3].sval));
        if (idx >= 0) {
            emit_istore(idx);
        } else {
            // 若不是 local，預設為 global
            symboltable_insert_global((yyvsp[-3].sval), 0);
            codegen_emit_store_variable((yyvsp[-3].sval));
        }
      }
#line 1554 "parser.tab.c"
    break;

  case 20: /* const_decl: CONST type ID ASSIGN expression SEMICOLON  */
#line 264 "parser.y"
                                              {
        symboltable_insert_const(symboltable_top(), (yyvsp[-3].sval), (yyvsp[-4].ival), (yyvsp[-1].ival));
      }
#line 1562 "parser.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 270 "parser.y"
           {
        emit_source_comment();
    }
#line 1570 "parser.tab.c"
    break;

  case 22: /* block: LBRACE $@5 decl_or_stmt_list RBRACE  */
#line 272 "parser.y"
                               {
        emit_source_comment();
    }
#line 1578 "parser.tab.c"
    break;

  case 23: /* block: LBRACE decl_or_stmt_list error  */
#line 275 "parser.y"
                                   {
      yyerrok;
      emit_source_comment();
      if (!emitted_main_epilogue) {
          emit_main_epilogue();
          emitted_main_epilogue = 1;
      }
      if (!emitted_class_closure) {
          finalize_codegen(classname);
          emitted_class_closure = 1;
      }
     }
#line 1595 "parser.tab.c"
    break;

  case 24: /* block: LBRACE error RBRACE  */
#line 287 "parser.y"
                          {
        yyerrok;
        emit_source_comment();
    }
#line 1604 "parser.tab.c"
    break;

  case 30: /* args_passed: %empty  */
#line 305 "parser.y"
                  { arg_pass_count = 0; }
#line 1610 "parser.tab.c"
    break;

  case 31: /* args_passed: expression  */
#line 306 "parser.y"
                 {
        arg_pass_types[0] = (yyvsp[0].ival);
        arg_pass_count = 1;
    }
#line 1619 "parser.tab.c"
    break;

  case 32: /* args_passed: args_passed COMMA expression  */
#line 310 "parser.y"
                                   {
        arg_pass_types[arg_pass_count++] = (yyvsp[0].ival);
    }
#line 1627 "parser.tab.c"
    break;

  case 35: /* param: type ID  */
#line 321 "parser.y"
            {
        int idx = param_index++;
        symboltable_allocate_local(symboltable_top(), (yyvsp[0].sval), (yyvsp[-1].ival));
        param_types_temp[param_count_temp++] = (yyvsp[-1].ival);
    }
#line 1637 "parser.tab.c"
    break;

  case 37: /* statement: PRINT expression SEMICOLON  */
#line 329 "parser.y"
                                 {
        emit_source_comment();
    
        // expression 已經先產出值在 stack 上，例如 -c 的結果
        // 現在才 emit getstatic & print
        fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
    
        if ((yyvsp[-1].ival) == 0)
            fprintf(out, "invokevirtual void java.io.PrintStream.print(int)\n");
        else if ((yyvsp[-1].ival) == 1)
            fprintf(out, "invokevirtual void java.io.PrintStream.print(boolean)\n");
        else if ((yyvsp[-1].ival) == 2)
            fprintf(out, "invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
        else
            yyerror("Unsupported print type");
      }
#line 1658 "parser.tab.c"
    break;

  case 38: /* statement: PRINT expression_list SEMICOLON  */
#line 345 "parser.y"
                                      {
        emit_source_comment();
        codegen_emit_print("int", NULL);
      }
#line 1667 "parser.tab.c"
    break;

  case 39: /* statement: PRINTLN expression_list SEMICOLON  */
#line 349 "parser.y"
                                        {
        emit_source_comment();
        codegen_emit_println("int", NULL);
      }
#line 1676 "parser.tab.c"
    break;

  case 40: /* statement: PRINTLN STRING SEMICOLON  */
#line 353 "parser.y"
                               {
        emit_source_comment();
        codegen_emit_println("java.lang.String", (yyvsp[-1].sval));
      }
#line 1685 "parser.tab.c"
    break;

  case 41: /* statement: PRINTLN expression SEMICOLON  */
#line 357 "parser.y"
                                   {
        emit_source_comment();
    
        // expression 的值已經在 stack 上
        fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
    
        if ((yyvsp[-1].ival) == 0)
            fprintf(out, "invokevirtual void java.io.PrintStream.println(int)\n");
        else if ((yyvsp[-1].ival) == 1)
            fprintf(out, "invokevirtual void java.io.PrintStream.println(boolean)\n");
        else if ((yyvsp[-1].ival) == 2)
            fprintf(out, "invokevirtual void java.io.PrintStream.println(java.lang.String)\n");
        else
            yyerror("Unsupported println type");
      }
#line 1705 "parser.tab.c"
    break;

  case 42: /* statement: PRINTLN STRINGLIT SEMICOLON  */
#line 372 "parser.y"
                                  {
          emit_source_comment();
          fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
          codegen_emit_string((yyvsp[-1].sval));
          fprintf(out, "invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
      }
#line 1716 "parser.tab.c"
    break;

  case 43: /* statement: RETURN SEMICOLON  */
#line 378 "parser.y"
                       {
        emit_source_comment();
        if (current_function_return_type != 2) {
            yyerror("type error: return value missing for non-void function");
        }
        codegen_emit_return();
      }
#line 1728 "parser.tab.c"
    break;

  case 44: /* statement: RETURN expression SEMICOLON  */
#line 385 "parser.y"
                                  {
        emit_source_comment();
        if (current_function_return_type == 2) {
            yyerror("type error: void function should not return a value");
        } else if ((yyvsp[-1].ival) != current_function_return_type) {
            yyerror("type error: return type does not match function declaration");
        }
        codegen_emit_return_value();
      }
#line 1742 "parser.tab.c"
    break;

  case 45: /* statement: error SEMICOLON  */
#line 394 "parser.y"
                      {
        emit_source_comment();
        yyerror("invalid statement");
        yyerrok;
      }
#line 1752 "parser.tab.c"
    break;

  case 46: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 399 "parser.y"
                                                           {
        emit_source_comment();
        int label_else = new_label();
        int label_end = new_label();
        codegen_emit_if_eq_zero(label_else);   // if (表達式==0) 跳 else
        codegen_emit_goto(label_end);          // skip else
        codegen_emit_label(label_else);        // ELSE block
        codegen_emit_label(label_end);         // end
      }
#line 1766 "parser.tab.c"
    break;

  case 47: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 408 "parser.y"
                                               {
        emit_source_comment();
        int label_else = new_label();
        int label_end = new_label();
        codegen_emit_if_eq_zero(label_else); // false -> else
        codegen_emit_goto(label_end);        // 跳過 else
        codegen_emit_label(label_else);      // else 標籤
        codegen_emit_label(label_end);       // end 標籤
      }
#line 1780 "parser.tab.c"
    break;

  case 48: /* statement: ID ASSIGN expression SEMICOLON  */
#line 417 "parser.y"
                                     {
        emit_source_comment();
        int tmp;
        if (symboltable_lookup_const(symboltable_top(), (yyvsp[-3].sval), &tmp)) {
            yyerror("assignment error: cannot assign to a constant");
        }

        int idx = symboltable_get_local_index(symboltable_top(), (yyvsp[-3].sval));
        if (idx >= 0) emit_istore(idx);
        else codegen_emit_store_variable((yyvsp[-3].sval));
      }
#line 1796 "parser.tab.c"
    break;

  case 49: /* statement: FOR LPAREN ID ASSIGN expression SEMICOLON expression SEMICOLON ID ASSIGN expression RPAREN statement  */
#line 428 "parser.y"
                                                                                                           {
        emit_source_comment();
        int label_start = new_label();
        int label_end = new_label();
        int idx = symboltable_get_local_index(symboltable_top(), (yyvsp[-10].sval));
        emit_istore(idx);
        codegen_emit_label(label_start);
        codegen_emit_if_eq_zero(label_end);
        emit_istore(idx);
        codegen_emit_goto(label_start);
        codegen_emit_label(label_end);
      }
#line 1813 "parser.tab.c"
    break;

  case 50: /* statement: FOREACH LPAREN ID COLON expression DOTDOT expression RPAREN statement  */
#line 440 "parser.y"
                                                                            {
        emit_source_comment();
        int label_start = new_label();
        int label_end = new_label();
        int idx = symboltable_allocate_local(symboltable_top(), (yyvsp[-6].sval), 0);
        emit_istore(idx);
        codegen_emit_arith_op("isub");
        codegen_emit_if_gt(label_end);
        emit_iload(idx);
        codegen_emit_integer(1);
        codegen_emit_arith_op("iadd");
        emit_istore(idx);
        codegen_emit_goto(label_start);
        codegen_emit_label(label_end);
      }
#line 1833 "parser.tab.c"
    break;

  case 53: /* expression: INTNUM  */
#line 463 "parser.y"
             {
        codegen_emit_integer((yyvsp[0].ival));
        (yyval.ival) = 0;
      }
#line 1842 "parser.tab.c"
    break;

  case 54: /* expression: STRINGLIT  */
#line 467 "parser.y"
                {
        codegen_emit_string((yyvsp[0].sval));
        (yyval.ival) = 2;  // type 2 = string
      }
#line 1851 "parser.tab.c"
    break;

  case 55: /* expression: ID  */
#line 471 "parser.y"
         {
        int const_val;
        if (symboltable_lookup_const(symboltable_top(), (yyvsp[0].sval), &const_val)) {
            codegen_emit_integer(const_val);
            (yyval.ival) = 0;
        } else {
            int type = symboltable_lookup(symboltable_top(), (yyvsp[0].sval));
            if (type == -1) {
                yyerror("use of undeclared variable");
            }

            int idx = symboltable_get_local_index(symboltable_top(), (yyvsp[0].sval));
            if (idx >= 0) emit_iload(idx);
            else codegen_emit_load_variable((yyvsp[0].sval));

            (yyval.ival) = type;  // ← 這樣也省得再呼叫一次 get_type
        }
      }
#line 1874 "parser.tab.c"
    break;

  case 56: /* expression: ID LPAREN args_passed RPAREN  */
#line 489 "parser.y"
                                   {
         func_signature* sig = lookup_function((yyvsp[-3].sval));
         if (!sig) yyerror("function not declared");
         else if (sig->param_count != arg_pass_count) yyerror("function argument count mismatch");
         else {
           for (int i = 0; i < arg_pass_count; i++) {
             if (sig->param_types[i] != arg_pass_types[i]) {
               yyerror("function argument type mismatch");
               break;
             }
           }
         }
         codegen_emit_function_call((yyvsp[-3].sval), arg_pass_count, sig ? (sig->return_type == 0 ? "int" : "boolean") : "int");
         (yyval.ival) = sig ? sig->return_type : 0;
      }
#line 1894 "parser.tab.c"
    break;

  case 57: /* expression: MINUS expression  */
#line 504 "parser.y"
                                    {
        if ((yyvsp[0].ival) != 0) yyerror("type error: unary '-' requires int operand");
        codegen_emit_arith_op("ineg"); (yyval.ival) = 0;
      }
#line 1903 "parser.tab.c"
    break;

  case 58: /* expression: LPAREN expression RPAREN  */
#line 508 "parser.y"
                               { (yyval.ival) = (yyvsp[-1].ival); }
#line 1909 "parser.tab.c"
    break;

  case 59: /* expression: expression PLUS expression  */
#line 509 "parser.y"
                                 {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '+' requires int operands");
        codegen_emit_arith_op("iadd"); (yyval.ival) = 0;
      }
#line 1918 "parser.tab.c"
    break;

  case 60: /* expression: expression MINUS expression  */
#line 513 "parser.y"
                                  {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '-' requires int operands");
        codegen_emit_arith_op("isub"); (yyval.ival) = 0;
      }
#line 1927 "parser.tab.c"
    break;

  case 61: /* expression: expression STAR expression  */
#line 517 "parser.y"
                                 {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '*' requires int operands");
        codegen_emit_arith_op("imul"); (yyval.ival) = 0;
      }
#line 1936 "parser.tab.c"
    break;

  case 62: /* expression: expression SLASH expression  */
#line 521 "parser.y"
                                  {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '/' requires int operands");
        codegen_emit_arith_op("idiv"); (yyval.ival) = 0;
      }
#line 1945 "parser.tab.c"
    break;

  case 63: /* expression: expression MOD expression  */
#line 525 "parser.y"
                                {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '%' requires int operands");
        codegen_emit_arith_op("irem"); (yyval.ival) = 0;
      }
#line 1954 "parser.tab.c"
    break;

  case 64: /* expression: expression LT expression  */
#line 529 "parser.y"
                               {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '<' requires int operands");
        codegen_emit_relop("<"); (yyval.ival) = 1;
      }
#line 1963 "parser.tab.c"
    break;

  case 65: /* expression: expression LE expression  */
#line 533 "parser.y"
                               {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '<=' requires int operands");
        codegen_emit_relop("<="); (yyval.ival) = 1;
      }
#line 1972 "parser.tab.c"
    break;

  case 66: /* expression: expression EQ expression  */
#line 537 "parser.y"
                               {
        if ((yyvsp[-2].ival) != (yyvsp[0].ival)) yyerror("type error: '==' requires same operand types");
        codegen_emit_relop("=="); (yyval.ival) = 1;
      }
#line 1981 "parser.tab.c"
    break;

  case 67: /* expression: expression NE expression  */
#line 541 "parser.y"
                               {
        if ((yyvsp[-2].ival) != (yyvsp[0].ival)) yyerror("type error: '!=' requires same operand types");
        codegen_emit_relop("!="); (yyval.ival) = 1;
      }
#line 1990 "parser.tab.c"
    break;

  case 68: /* expression: expression GE expression  */
#line 545 "parser.y"
                               {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '>=' requires int operands");
        codegen_emit_relop(">="); (yyval.ival) = 1;
      }
#line 1999 "parser.tab.c"
    break;

  case 69: /* expression: expression GT expression  */
#line 549 "parser.y"
                               {
        if ((yyvsp[-2].ival) != 0 || (yyvsp[0].ival) != 0) yyerror("type error: '>' requires int operands");
        codegen_emit_relop(">"); (yyval.ival) = 1;
      }
#line 2008 "parser.tab.c"
    break;

  case 70: /* expression: expression AND expression  */
#line 553 "parser.y"
                                {
        if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) yyerror("type error: '&&' requires bool operands");
        codegen_emit_logic_op("&&"); (yyval.ival) = 1;
      }
#line 2017 "parser.tab.c"
    break;

  case 71: /* expression: expression OR expression  */
#line 557 "parser.y"
                               {
        if ((yyvsp[-2].ival) != 1 || (yyvsp[0].ival) != 1) yyerror("type error: '||' requires bool operands");
        codegen_emit_logic_op("||"); (yyval.ival) = 1;
      }
#line 2026 "parser.tab.c"
    break;

  case 72: /* expression: NOT expression  */
#line 561 "parser.y"
                     {
        if ((yyvsp[0].ival) != 1) yyerror("type error: '!' requires bool operand");
        codegen_emit_logic_op("!"); (yyval.ival) = 1;
      }
#line 2035 "parser.tab.c"
    break;


#line 2039 "parser.tab.c"

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

#line 566 "parser.y"




void load_source_lines(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("fopen");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), f)) {
        source_lines[source_line_count++] = strdup(buffer);
    }

    fclose(f);
}

static int last_error_line = -1;
static int emitted_recovery = 0;

void yyerror(const char *msg) {
    if (yylineno == last_error_line) return;
    last_error_line = yylineno;
    had_error = 1;

    fprintf(stderr, "Error at line %d: %s (token: '%s')\n\n", yylineno, msg, yytext);
    
    if (out) {
        fprintf(out, "/* Error recovery: forced class closure */\n");

        if (!emitted_main_epilogue) {
            emit_main_epilogue();         // 補 main 結尾
            emitted_main_epilogue = 1;
        }

        if (!emitted_class_closure) {
            finalize_codegen(classname);  // 補 class 結尾
            emitted_class_closure = 1;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.sd> [output.jasm]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror(argv[1]);
        return 1;
    }

    yyin = input_file;
    yyin_filename = argv[1];
    const char *output_filename = (argc >= 3) ? argv[2] : "out.jasm";

    init_codegen_file(output_filename);
    classname = get_class_name(argv[1]);
    load_source_lines(argv[1]);

    yyparse();

    printf("\n--- Full Source Code ---\n");
    for (int i = 0; i < source_line_count; ++i) {
        printf("%3d | %s", i + 1, source_lines[i]);
    }

    close_codegen_file();  
    fclose(input_file);

    FILE* bytecode = fopen(output_filename, "r");  
    if (bytecode) {
        char line[1024];
        while (fgets(line, sizeof(line), bytecode)) {
            fputs(line, stdout);
        }
        fclose(bytecode);
    }

    return 0;
}

