/* A Bison parser, made by GNU Bison 3.8.1.  */

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
#define YYBISON 30801

/* Bison version string.  */
#define YYBISON_VERSION "3.8.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/splc.yy"

	#include "lex.yy.c"
	#include "type.h"
	#include <map>
	#include <string>
	#include <list>
	#include <unordered_map>
	#include <algorithm>
	#include <cstring>

	using std::map;
	using std::string;
	using std::pair;
	using std::list;
	void yyerror(const char*);
	int has_error = 0;

	map<string, string> var_table;
	map<string, func_t*> func_table;
	map<string, type_t*> type_table;

#line 93 "./src/splc.tab.cc"

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

#include "splc.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_TYPE = 7,                       /* TYPE  */
  YYSYMBOL_STRUCT = 8,                     /* STRUCT  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_SEMI = 12,                      /* SEMI  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_LC = 14,                        /* LC  */
  YYSYMBOL_RC = 15,                        /* RC  */
  YYSYMBOL_INVALID = 16,                   /* INVALID  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_LE = 21,                        /* LE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NE = 25,                        /* NE  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_LP = 31,                        /* LP  */
  YYSYMBOL_RP = 32,                        /* RP  */
  YYSYMBOL_LB = 33,                        /* LB  */
  YYSYMBOL_RB = 34,                        /* RB  */
  YYSYMBOL_DOT = 35,                       /* DOT  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_Program = 38,                   /* Program  */
  YYSYMBOL_ExtDefList = 39,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 40,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 41,                /* ExtDecList  */
  YYSYMBOL_Specifier = 42,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 43,           /* StructSpecifier  */
  YYSYMBOL_VarDec = 44,                    /* VarDec  */
  YYSYMBOL_FunDec = 45,                    /* FunDec  */
  YYSYMBOL_VarList = 46,                   /* VarList  */
  YYSYMBOL_ParamDec = 47,                  /* ParamDec  */
  YYSYMBOL_CompSt = 48,                    /* CompSt  */
  YYSYMBOL_StmtList = 49,                  /* StmtList  */
  YYSYMBOL_Stmt = 50,                      /* Stmt  */
  YYSYMBOL_DefList = 51,                   /* DefList  */
  YYSYMBOL_Def = 52,                       /* Def  */
  YYSYMBOL_DecList = 53,                   /* DecList  */
  YYSYMBOL_Dec = 54,                       /* Dec  */
  YYSYMBOL_Exp = 55,                       /* Exp  */
  YYSYMBOL_Args = 56                       /* Args  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   428

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    52,    55,    62,    86,   130,   199,   202,
     205,   210,   214,   224,   228,   234,   242,   251,   255,   260,
     269,   276,   282,   285,   290,   296,   302,   311,   319,   322,
     329,   334,   338,   344,   352,   362,   370,   373,   376,   379,
     386,   389,   396,   426,   429,   434,   438,   446,   450,   460,
     466,   472,   478,   484,   490,   496,   502,   508,   514,   520,
     526,   532,   538,   544,   549,   554,   561,   572,   579,   585,
     594,   598,   602,   606,   613,   618,   621,   624,   629,   635
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "ID", "TYPE", "STRUCT", "IF", "WHILE", "RETURN", "SEMI", "COMMA", "LC",
  "RC", "INVALID", "ASSIGN", "OR", "AND", "LT", "LE", "GT", "GE", "EQ",
  "NE", "PLUS", "MINUS", "MUL", "DIV", "NOT", "LP", "RP", "LB", "RB",
  "DOT", "ELSE", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "VarDec", "FunDec",
  "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def",
  "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      57,    18,   -29,    25,    33,   -29,    57,    16,   -29,   -29,
      20,   -29,   -29,   -29,    29,   -29,   -29,     4,    -8,    24,
      55,   210,     3,   -29,   -29,   256,    60,   236,   -29,    50,
      50,    50,    52,   236,   -29,   -29,    50,     5,    56,   -29,
     -29,   -29,    53,   -29,   256,   256,   256,   321,    59,   265,
     -29,   -29,    76,    77,    14,   -29,   -29,    61,   -29,   -29,
       6,   204,   116,    -6,    54,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
      89,   -29,    66,    67,   256,   -29,   100,   265,    84,   -29,
      50,   -29,   -29,   -29,   -29,   -29,   281,     7,   -29,   -29,
     341,   360,   377,   393,   186,   186,   186,   186,   186,   186,
     116,   116,    -6,    -6,   301,   -29,   256,   256,   113,   -29,
     -29,   -29,   -29,   -29,   256,   -29,   -29,   -29,   142,   171,
     -29,   -29,   -29,   265,   265,   265,   265,   -29,    80,   -29,
     -29,   265,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,     0,     0,     2,     0,     0,    14,    10,
      16,     1,     4,     8,    17,     6,    18,     0,    47,     0,
      11,     0,     0,     9,     5,     0,     0,     0,     7,     0,
       0,     0,     0,     0,    23,    21,     0,     0,    25,    70,
      71,    72,    69,    74,     0,     0,     0,    48,     0,    28,
      17,    12,     0,    45,     0,    15,    41,    26,    22,    20,
       0,     0,    63,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,    31,     0,    28,     0,    44,
       0,    43,    42,    24,    77,    66,    79,     0,    75,    62,
      73,    49,    51,    50,    52,    53,    54,    55,    57,    56,
      58,    59,    60,    61,     0,    68,     0,     0,     0,    27,
      29,    36,    30,    46,     0,    76,    65,    67,     0,     0,
      37,    32,    78,     0,     0,     0,     0,    38,    33,    39,
      35,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   112,   -29,    95,     1,   -29,    90,   -29,    87,
     -29,   108,    63,   -13,   -15,   -29,   -28,    -5,   -25,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    17,    31,     8,    18,    19,    37,
      38,    85,    86,    87,    32,    33,    52,    53,    88,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,     7,    20,    54,    34,    23,    58,     7,   125,    25,
       2,     3,    49,     2,     3,    91,    24,    13,    56,    62,
      63,    64,    14,    36,    20,    26,    92,    79,    15,    80,
       9,    10,    16,    11,    21,    35,    96,    59,    27,   126,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    98,    50,    -3,     1,   118,
      22,    36,   123,    48,     2,     3,    16,    55,    29,    60,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    61,   121,    99,    79,    89,    80,
      90,   128,   129,    81,    26,   115,   122,   116,   117,    96,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   130,   119,   141,    79,    12,    80,
     137,   138,   139,   140,    51,   131,    57,    28,   142,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   133,    77,    78,    79,    93,    80,    79,
     120,    80,   132,     0,     0,     0,     0,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,   135,     0,   134,    79,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,   136,    79,    94,    80,    39,    40,    41,
      42,    30,    75,    76,    77,    78,     0,     2,     3,    79,
      43,    80,     0,     0,     0,   -40,     0,     0,     0,     0,
       0,    44,     0,     0,    45,    46,    95,    30,     0,   -40,
     -40,   -40,   -40,     2,     3,   -40,   -40,   -40,     0,     0,
     -40,   -40,   -40,     0,     0,     0,     0,     0,     0,    39,
      40,    41,    42,   -40,     0,     0,   -40,   -40,    39,    40,
      41,    42,    43,     0,    82,    83,    84,     0,     0,    27,
       0,    43,     0,    44,     0,     0,    45,    46,     0,     0,
       0,     0,    44,     0,   124,    45,    46,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    79,     0,    80,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    79,   127,    80,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    79,     0,    80,   -41,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    79,     0,    80,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    79,     0,    80,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      79,     0,    80,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    79,     0,    80
};

static const yytype_int16 yycheck[] =
{
      25,     0,     7,    31,     1,     1,     1,     6,     1,    17,
       7,     8,    27,     7,     8,     1,    12,     1,    33,    44,
      45,    46,     6,    22,    29,    33,    12,    33,    12,    35,
      12,     6,    16,     0,    14,    32,    61,    32,    14,    32,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     1,     6,     0,     1,    84,
      31,    60,    90,     3,     7,     8,    16,    15,    13,    13,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    31,     1,    32,    33,    12,    35,
      13,   116,   117,    34,    33,     6,    12,    31,    31,   124,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     1,    15,    36,    33,     6,    35,
     133,   134,   135,   136,    29,    12,    36,    19,   141,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     1,    28,    29,    33,    60,    35,    33,
      87,    35,   124,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     1,    -1,    32,    33,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,     1,    35,     3,     4,     5,
       6,     1,    26,    27,    28,    29,    -1,     7,     8,    33,
      16,    35,    -1,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    31,    32,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    27,    -1,    -1,    30,    31,     3,     4,
       5,     6,    16,    -1,     9,    10,    11,    -1,    -1,    14,
      -1,    16,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    27,    -1,    13,    30,    31,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    -1,    35,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    34,    35,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    -1,    35,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    33,    -1,    35,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    33,    -1,    35,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      33,    -1,    35,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    33,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,     8,    38,    39,    40,    42,    43,    12,
       6,     0,    39,     1,     6,    12,    16,    41,    44,    45,
      54,    14,    31,     1,    12,    17,    33,    14,    48,    13,
       1,    42,    51,    52,     1,    32,    42,    46,    47,     3,
       4,     5,     6,    16,    27,    30,    31,    55,     3,    51,
       6,    41,    53,    54,    53,    15,    51,    44,     1,    32,
      13,    31,    55,    55,    55,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    33,
      35,    34,     9,    10,    11,    48,    49,    50,    55,    12,
      13,     1,    12,    46,     1,    32,    55,    56,     1,    32,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,     6,    31,    31,    55,    15,
      49,     1,    12,    53,    13,     1,    32,    34,    55,    55,
       1,    12,    56,     1,    32,     1,    32,    50,    50,    50,
      50,    36,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      45,    45,    45,    45,    46,    46,    47,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     2,     3,
       2,     1,     3,     1,     1,     5,     2,     1,     1,     4,
       4,     3,     4,     3,     3,     1,     2,     4,     0,     2,
       2,     1,     3,     5,     7,     5,     2,     3,     5,     5,
       0,     2,     3,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     1,     3,     1,     3,     4,     3,     3,     1
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
  case 2: /* Program: ExtDefList  */
#line 45 "src/splc.yy"
                   {
		(yyval.tree_node) = make_tree_node("Program", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		if (!has_error)
			show_tree((yyval.tree_node), 0);
	}
#line 1286 "./src/splc.tab.cc"
    break;

  case 3: /* ExtDefList: %empty  */
#line 52 "src/splc.yy"
            {
		(yyval.tree_node) = NULL;
	}
#line 1294 "./src/splc.tab.cc"
    break;

  case 4: /* ExtDefList: ExtDef ExtDefList  */
#line 55 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("ExtDefList", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1304 "./src/splc.tab.cc"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 62 "src/splc.yy"
                                  {
		(yyval.tree_node) = make_tree_node("ExtDef", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		// printf("Find global type: %s\n", type_name.c_str());
		string type_name = parse_Specifier((yyvsp[-2].tree_node));
		std::list<string> var_name_list = parse_ExtDecList((yyvsp[-1].tree_node));
		// std::for_each(var_name_list.begin(), var_name_list.end(), [](const string str) { printf("%s ", str.c_str()); });
		if (type_table.count(type_name)) {
			std::for_each(var_name_list.begin(), var_name_list.end(), [&](const string var_name) { 
				if (var_table.count(var_name)) {
					printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", (yyvsp[-2].tree_node)->line_no, var_name.c_str());
				} else {
					var_table.insert({var_name, type_name});
				}
			});
		} else {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, type_name.c_str());
		}
		
		
	}
#line 1333 "./src/splc.tab.cc"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 86 "src/splc.yy"
                         {
		(yyval.tree_node) = make_tree_node("ExtDef", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));

		string struct_name = parse_Specifier((yyvsp[-1].tree_node));
		type_t *ptr = new type_t();
		strcpy(ptr->name, struct_name.c_str());
		ptr->category = type_t::STRUCTURE;

		field_list_t *head = 0;
		list<pair<string, list<string>>> vars_table = parse_DefList(
			(yyvsp[-1].tree_node)	->child_first_ptr->node
				->child_first_ptr->next_child->next_child
				->next_child->node
		);
		// printf("====vars_table.size() = %d\n", vars_table.size());
		std::for_each(vars_table.rbegin(), vars_table.rend(), [&](const pair<string, list<string>> vars) { 
			string type_name = vars.first;
			list<string> var_list = vars.second;
			if (!type_table.count(type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-1].tree_node)->line_no, type_name.c_str());
			} else {
				type_t *type = type_table[type_name];
				for (list<string>::reverse_iterator it = var_list.rbegin(); it != var_list.rend(); ++it) {
					field_list_t *new_node = new field_list_t();
					strcpy(new_node->name, (*it).c_str());
					new_node->type = type;
					new_node->next = head;
					head = new_node;
				}
			}
		});
		ptr->data.structure = head;
		type_table.insert({struct_name, ptr});
#ifdef DEBUG
		printf("Find user-defined struct: %s:\n", struct_name.c_str());
		field_list_t *cur = head;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif
	}
#line 1382 "./src/splc.tab.cc"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 130 "src/splc.yy"
                                  {
		(yyval.tree_node) = make_tree_node("ExtDef", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		bool is_valid = 1;
		func_t *func = new func_t();
		// check return type
		string ret_type_name = parse_Specifier((yyvsp[-2].tree_node));
		if (!type_table.count(ret_type_name)) {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, ret_type_name.c_str());
			is_valid = 0;
		} else {
			func->ret_type = type_table[ret_type_name];
		}
		// check name
		string func_name = (yyvsp[-1].tree_node)->child_first_ptr->node->name+4;
		if (func_table.count(func_name)) {
			printf("Error Type 4 at Line %d: function \"%s\" is redefined.\n", (yyvsp[-1].tree_node)->line_no, func_name.c_str());
			is_valid = 0;
		}
		// check para's type & name
		field_list_t *head = 0, *tail = head;

		if ((yyvsp[-1].tree_node)->children_number == 4) {
			list<pair<string, string>> var_list = parse_VarList(
				(yyvsp[-1].tree_node)->child_first_ptr
				->next_child
				->next_child
				->node
			);
			std::for_each(var_list.begin(), var_list.end(), [&](const pair<string, string> var) { 
				string para_type_name = var.first;
				string para_name = var.second;
				if (!type_table.count(para_type_name)) {
					printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-1].tree_node)->line_no, para_type_name.c_str());
					is_valid = 0;
				} if (var_table.count(para_name)) {
					printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", (yyvsp[-1].tree_node)->line_no, para_name.c_str());
					is_valid = 0;
				} else {
					field_list_t *new_node = new field_list_t();
					strcpy(new_node->name, para_name.c_str());
					new_node->type = type_table[para_type_name];
					new_node->next = 0;
					if (!head) head = tail = new_node;
					else tail->next = new_node, tail = new_node;
				}
			});
			func->args_num = var_list.size();
		} else if ((yyvsp[-1].tree_node)->children_number == 3) {
			func->args_num = 0;
		}

		func->args_list = head;
		if (is_valid) func_table.insert({func_name, func});

#ifdef DEBUG
		printf("Find user-defined function %s:\n", func_name.c_str());
		printf("Return type: %s\n", func->ret_type->name);
		field_list_t *cur = func->args_list;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif

	}
#line 1456 "./src/splc.tab.cc"
    break;

  case 8: /* ExtDef: Specifier error  */
#line 199 "src/splc.yy"
                         {
		printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-1].tree_node)->line_no);
	}
#line 1464 "./src/splc.tab.cc"
    break;

  case 9: /* ExtDef: Specifier ExtDecList error  */
#line 202 "src/splc.yy"
                                     {
		printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-2].tree_node)->line_no);
	}
#line 1472 "./src/splc.tab.cc"
    break;

  case 10: /* ExtDef: error SEMI  */
#line 205 "src/splc.yy"
                    {
		printf("Error type 2B at Line %d: Missing specifier\n", (yyvsp[0].tree_node)->line_no-1);
	}
#line 1480 "./src/splc.tab.cc"
    break;

  case 11: /* ExtDecList: Dec  */
#line 210 "src/splc.yy"
            {
		(yyval.tree_node) = make_tree_node("ExtDecList", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1489 "./src/splc.tab.cc"
    break;

  case 12: /* ExtDecList: Dec COMMA ExtDecList  */
#line 214 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("ExtDecList", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1500 "./src/splc.tab.cc"
    break;

  case 13: /* Specifier: TYPE  */
#line 224 "src/splc.yy"
             {
		(yyval.tree_node) = make_tree_node("Specifier", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1509 "./src/splc.tab.cc"
    break;

  case 14: /* Specifier: StructSpecifier  */
#line 228 "src/splc.yy"
                          {
		(yyval.tree_node) = make_tree_node("Specifier", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1518 "./src/splc.tab.cc"
    break;

  case 15: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 234 "src/splc.yy"
                                {
		(yyval.tree_node) = make_tree_node("StructSpecifier", (yyvsp[-4].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
		add_child((yyval.tree_node), (yyvsp[-4].tree_node));
	}
#line 1531 "./src/splc.tab.cc"
    break;

  case 16: /* StructSpecifier: STRUCT ID  */
#line 242 "src/splc.yy"
                    {
		(yyval.tree_node) = make_tree_node("StructSpecifier", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1541 "./src/splc.tab.cc"
    break;

  case 17: /* VarDec: ID  */
#line 251 "src/splc.yy"
           {
		(yyval.tree_node) = make_tree_node("VarDec", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1550 "./src/splc.tab.cc"
    break;

  case 18: /* VarDec: INVALID  */
#line 255 "src/splc.yy"
                  {
		(yyval.tree_node) = make_tree_node("VarDec", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		has_error=1;
	}
#line 1560 "./src/splc.tab.cc"
    break;

  case 19: /* VarDec: VarDec LB INT RB  */
#line 260 "src/splc.yy"
                           {
		(yyval.tree_node) = make_tree_node("VarDec", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 1572 "./src/splc.tab.cc"
    break;

  case 20: /* FunDec: ID LP VarList RP  */
#line 269 "src/splc.yy"
                         {
		(yyval.tree_node) = make_tree_node("FunDec", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 1584 "./src/splc.tab.cc"
    break;

  case 21: /* FunDec: ID LP RP  */
#line 276 "src/splc.yy"
                   {
		(yyval.tree_node) = make_tree_node("FunDec", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1595 "./src/splc.tab.cc"
    break;

  case 22: /* FunDec: ID LP VarList error  */
#line 282 "src/splc.yy"
                                 {
        	printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-3].tree_node)->line_no);
    	}
#line 1603 "./src/splc.tab.cc"
    break;

  case 23: /* FunDec: ID LP error  */
#line 285 "src/splc.yy"
                         {
        	printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-2].tree_node)->line_no);
    	}
#line 1611 "./src/splc.tab.cc"
    break;

  case 24: /* VarList: ParamDec COMMA VarList  */
#line 290 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("VarList", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1622 "./src/splc.tab.cc"
    break;

  case 25: /* VarList: ParamDec  */
#line 296 "src/splc.yy"
                   {
		(yyval.tree_node) = make_tree_node("VarList", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1631 "./src/splc.tab.cc"
    break;

  case 26: /* ParamDec: Specifier VarDec  */
#line 302 "src/splc.yy"
                         {
		(yyval.tree_node) = make_tree_node("ParamDec", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1641 "./src/splc.tab.cc"
    break;

  case 27: /* CompSt: LC DefList StmtList RC  */
#line 311 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("CompSt", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 1653 "./src/splc.tab.cc"
    break;

  case 28: /* StmtList: %empty  */
#line 319 "src/splc.yy"
          {
		(yyval.tree_node) = NULL;
	}
#line 1661 "./src/splc.tab.cc"
    break;

  case 29: /* StmtList: Stmt StmtList  */
#line 322 "src/splc.yy"
                        {
		(yyval.tree_node) = make_tree_node("StmtList", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1671 "./src/splc.tab.cc"
    break;

  case 30: /* Stmt: Exp SEMI  */
#line 329 "src/splc.yy"
                 {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1681 "./src/splc.tab.cc"
    break;

  case 31: /* Stmt: CompSt  */
#line 334 "src/splc.yy"
                 {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1690 "./src/splc.tab.cc"
    break;

  case 32: /* Stmt: RETURN Exp SEMI  */
#line 338 "src/splc.yy"
                          {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1701 "./src/splc.tab.cc"
    break;

  case 33: /* Stmt: IF LP Exp RP Stmt  */
#line 344 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-4].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
		add_child((yyval.tree_node), (yyvsp[-4].tree_node));
	}
#line 1714 "./src/splc.tab.cc"
    break;

  case 34: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 352 "src/splc.yy"
                                      {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-6].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
		add_child((yyval.tree_node), (yyvsp[-4].tree_node));
		add_child((yyval.tree_node), (yyvsp[-5].tree_node));
		add_child((yyval.tree_node), (yyvsp[-6].tree_node));
	}
#line 1729 "./src/splc.tab.cc"
    break;

  case 35: /* Stmt: WHILE LP Exp RP Stmt  */
#line 362 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-4].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
		add_child((yyval.tree_node), (yyvsp[-4].tree_node));
	}
#line 1742 "./src/splc.tab.cc"
    break;

  case 36: /* Stmt: Exp error  */
#line 370 "src/splc.yy"
                    {
		printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-1].tree_node)->line_no);
	}
#line 1750 "./src/splc.tab.cc"
    break;

  case 37: /* Stmt: RETURN Exp error  */
#line 373 "src/splc.yy"
                           {
			printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-2].tree_node)->line_no);
		}
#line 1758 "./src/splc.tab.cc"
    break;

  case 38: /* Stmt: IF LP Exp error Stmt  */
#line 376 "src/splc.yy"
                                          { 
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-4].tree_node)->line_no);
	}
#line 1766 "./src/splc.tab.cc"
    break;

  case 39: /* Stmt: WHILE LP Exp error Stmt  */
#line 379 "src/splc.yy"
                                     {
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-4].tree_node)->line_no);
	}
#line 1774 "./src/splc.tab.cc"
    break;

  case 40: /* DefList: %empty  */
#line 386 "src/splc.yy"
         {
		(yyval.tree_node) = NULL; 
	}
#line 1782 "./src/splc.tab.cc"
    break;

  case 41: /* DefList: Def DefList  */
#line 389 "src/splc.yy"
                      {
		(yyval.tree_node) = make_tree_node("DefList", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1792 "./src/splc.tab.cc"
    break;

  case 42: /* Def: Specifier DecList SEMI  */
#line 396 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("Def", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		bool is_valid = 1;
		// check type
		string type_name = parse_Specifier((yyvsp[-2].tree_node));
		if (!type_table.count(type_name)) {
			is_valid = 0;
		}
		// check names
		list<string> var_name_list = parse_DecList((yyvsp[-1].tree_node));
		std::for_each(var_name_list.begin(), var_name_list.end(), [&](const string var_name) { 
			if (var_table.count(var_name)) {
				printf("Error type 3 at Line %d: variable \"%s\" is redefined.\n", (yyvsp[-2].tree_node)->line_no, var_name.c_str());
			} else if (is_valid) {
				var_table.insert({var_name, type_name});
			}
		});
#ifdef DEBUG
		printf("Find local variables of type \"%s\": ", type_name.c_str());
		std::for_each(var_name_list.begin(), var_name_list.end(), [&](const string var_name) { 
			printf("%s ", var_name.c_str());
		});
		puts("");
#endif
		
	}
#line 1827 "./src/splc.tab.cc"
    break;

  case 43: /* Def: Specifier DecList error  */
#line 426 "src/splc.yy"
                                  {
		printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-2].tree_node)->line_no);	
	}
#line 1835 "./src/splc.tab.cc"
    break;

  case 44: /* Def: error DecList SEMI  */
#line 429 "src/splc.yy"
                             {
		printf("Error type 2B at Line %d: Missing specifier\n",(yyvsp[-1].tree_node)->line_no-1);
	}
#line 1843 "./src/splc.tab.cc"
    break;

  case 45: /* DecList: Dec  */
#line 434 "src/splc.yy"
            {
		(yyval.tree_node) = make_tree_node("DecList", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1852 "./src/splc.tab.cc"
    break;

  case 46: /* DecList: Dec COMMA DecList  */
#line 438 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("DecList", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1863 "./src/splc.tab.cc"
    break;

  case 47: /* Dec: VarDec  */
#line 446 "src/splc.yy"
               {
		(yyval.tree_node) = make_tree_node("Dec", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1872 "./src/splc.tab.cc"
    break;

  case 48: /* Dec: VarDec ASSIGN Exp  */
#line 450 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("Dec", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1883 "./src/splc.tab.cc"
    break;

  case 49: /* Exp: Exp ASSIGN Exp  */
#line 460 "src/splc.yy"
                       {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1894 "./src/splc.tab.cc"
    break;

  case 50: /* Exp: Exp AND Exp  */
#line 466 "src/splc.yy"
                      {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1905 "./src/splc.tab.cc"
    break;

  case 51: /* Exp: Exp OR Exp  */
#line 472 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1916 "./src/splc.tab.cc"
    break;

  case 52: /* Exp: Exp LT Exp  */
#line 478 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1927 "./src/splc.tab.cc"
    break;

  case 53: /* Exp: Exp LE Exp  */
#line 484 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1938 "./src/splc.tab.cc"
    break;

  case 54: /* Exp: Exp GT Exp  */
#line 490 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1949 "./src/splc.tab.cc"
    break;

  case 55: /* Exp: Exp GE Exp  */
#line 496 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1960 "./src/splc.tab.cc"
    break;

  case 56: /* Exp: Exp NE Exp  */
#line 502 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1971 "./src/splc.tab.cc"
    break;

  case 57: /* Exp: Exp EQ Exp  */
#line 508 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1982 "./src/splc.tab.cc"
    break;

  case 58: /* Exp: Exp PLUS Exp  */
#line 514 "src/splc.yy"
                       {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1993 "./src/splc.tab.cc"
    break;

  case 59: /* Exp: Exp MINUS Exp  */
#line 520 "src/splc.yy"
                        {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2004 "./src/splc.tab.cc"
    break;

  case 60: /* Exp: Exp MUL Exp  */
#line 526 "src/splc.yy"
                      {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2015 "./src/splc.tab.cc"
    break;

  case 61: /* Exp: Exp DIV Exp  */
#line 532 "src/splc.yy"
                      {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2026 "./src/splc.tab.cc"
    break;

  case 62: /* Exp: LP Exp RP  */
#line 538 "src/splc.yy"
                    {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2037 "./src/splc.tab.cc"
    break;

  case 63: /* Exp: MINUS Exp  */
#line 544 "src/splc.yy"
                    {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 2047 "./src/splc.tab.cc"
    break;

  case 64: /* Exp: NOT Exp  */
#line 549 "src/splc.yy"
                  {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 2057 "./src/splc.tab.cc"
    break;

  case 65: /* Exp: ID LP Args RP  */
#line 554 "src/splc.yy"
                        {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 2069 "./src/splc.tab.cc"
    break;

  case 66: /* Exp: ID LP RP  */
#line 561 "src/splc.yy"
                   {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		const char *func_name = (yyvsp[-2].tree_node)->name+4;
		if (!func_table.count(func_name)) {
			printf("Error type 2 at Line %d: function \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, func_name);
		}
	}
#line 2085 "./src/splc.tab.cc"
    break;

  case 67: /* Exp: Exp LB Exp RB  */
#line 572 "src/splc.yy"
                        {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 2097 "./src/splc.tab.cc"
    break;

  case 68: /* Exp: Exp DOT ID  */
#line 579 "src/splc.yy"
                     {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2108 "./src/splc.tab.cc"
    break;

  case 69: /* Exp: ID  */
#line 585 "src/splc.yy"
             {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));

		const char *var_name = (yyvsp[0].tree_node)->name+4;
		if (!var_table.count(var_name)) {
			printf("Error type 1 at Line %d: variable \"%s\" is used without definition.\n", (yyvsp[0].tree_node)->line_no, var_name);
		}
	}
#line 2122 "./src/splc.tab.cc"
    break;

  case 70: /* Exp: INT  */
#line 594 "src/splc.yy"
              {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2131 "./src/splc.tab.cc"
    break;

  case 71: /* Exp: FLOAT  */
#line 598 "src/splc.yy"
                {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2140 "./src/splc.tab.cc"
    break;

  case 72: /* Exp: CHAR  */
#line 602 "src/splc.yy"
               {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2149 "./src/splc.tab.cc"
    break;

  case 73: /* Exp: Exp INVALID Exp  */
#line 606 "src/splc.yy"
                          {
		has_error = 1;
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2161 "./src/splc.tab.cc"
    break;

  case 74: /* Exp: INVALID  */
#line 613 "src/splc.yy"
                  {
		has_error = 1;
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2171 "./src/splc.tab.cc"
    break;

  case 75: /* Exp: LP Exp error  */
#line 618 "src/splc.yy"
                      {
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-2].tree_node)->line_no);
	}
#line 2179 "./src/splc.tab.cc"
    break;

  case 76: /* Exp: ID LP Args error  */
#line 621 "src/splc.yy"
                          {
			printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-3].tree_node)->line_no);
	}
#line 2187 "./src/splc.tab.cc"
    break;

  case 77: /* Exp: ID LP error  */
#line 624 "src/splc.yy"
                     {
			printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-2].tree_node)->line_no);
	}
#line 2195 "./src/splc.tab.cc"
    break;

  case 78: /* Args: Exp COMMA Args  */
#line 629 "src/splc.yy"
                       {
		(yyval.tree_node) = make_tree_node("Args", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2206 "./src/splc.tab.cc"
    break;

  case 79: /* Args: Exp  */
#line 635 "src/splc.yy"
              {
		(yyval.tree_node) = make_tree_node("Args", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2215 "./src/splc.tab.cc"
    break;


#line 2219 "./src/splc.tab.cc"

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

#line 641 "src/splc.yy"


void yyerror(const char* msg) {
	has_error=1;
}

void show_tree(tree_node *node, int level) {
	if (!node) return ;
	for (int i = 0; i < (level<<1); ++i) printf(" ");
	if (node->is_terminate) printf("%s\n", node->name);
	else printf("%s (%d)\n", node->name, node->line_no);
	for (child_list_node *cur = node->child_first_ptr; cur; cur = cur->next_child) {
		show_tree(cur->node, level+1);
	}
	return ;
}

void init() {
	type_t *ptr = new type_t();
	strcpy(ptr->name, "INT");
	ptr->category = type_t::PRIMITIVE;
	ptr->data.primitive = type_t::data_t::ENUM_INT;
	type_table.insert({string("int"), ptr});

	ptr = new type_t();
	strcpy(ptr->name, "FLOAT");
	ptr->category = type_t::PRIMITIVE;
	ptr->data.primitive = type_t::data_t::ENUM_FLOAT;
	type_table.insert({string("float"), ptr});

	ptr = new type_t();
	strcpy(ptr->name, "CHAR");
	ptr->category = type_t::PRIMITIVE;
	ptr->data.primitive = type_t::data_t::ENUM_CHAR;
	type_table.insert({string("char"), ptr});
}

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
		return 1;
	} else if (argc == 2) {
		if (!(yyin = fopen(argv[1], "r"))) {
			perror(argv[1]);
			return 1;
		}
		init();
		yyparse();
		return 0;
	} else {
		fputs("Too many arguments! Expected: 2\n", stderr);
		return 1;
	}

}
