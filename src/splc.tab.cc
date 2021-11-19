/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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

	#include "lex.yy.cc"
	#include "type.h"
	#include <map>
	#include <string>
	#include <list>
	#include <unordered_map>
	#include <algorithm>
	#include <cstring>

	using std::map;
	using std::string;
	using std::list;
	using std::pair;

	void yyerror(const char*);
	string insert_array_type(const char *type_name, int length);
	type_t* parse_instance_type_in_struct(struct_var_list, int);
	type_t *find_type_in_value_node(tree_node *leaf);
	type_t *find_type_in_value_node(tree_node *leaf, bool &is_left);
	map<pair<string, int>, string>::iterator find_var_in_table(string var_name);


	int has_error = 0;
	int scope = 0;
	bool scope_flag = false;
	map<pair<string, int>, string> var_table;
	map<string, func_t*> func_table;
	map<string, type_t*> type_table;

#line 101 "./src/splc.tab.cc"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_INC_SPLC_TAB_HH_INCLUDED
# define YY_YY_INC_SPLC_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    TYPE = 261,
    STRUCT = 262,
    IF = 263,
    WHILE = 264,
    RETURN = 265,
    SEMI = 266,
    COMMA = 267,
    LC = 268,
    RC = 269,
    INVALID = 270,
    ASSIGN = 271,
    OR = 272,
    AND = 273,
    LT = 274,
    LE = 275,
    GT = 276,
    GE = 277,
    EQ = 278,
    NE = 279,
    PLUS = 280,
    MINUS = 281,
    MUL = 282,
    DIV = 283,
    NOT = 284,
    LP = 285,
    RP = 286,
    LB = 287,
    RB = 288,
    ID = 289,
    DOT = 290,
    ELSE = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "src/splc.yy"

	struct tree_node *tree_node;

#line 194 "./src/splc.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_SPLC_TAB_HH_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,    56,    56,    65,    68,    75,   120,   193,   244,   247,
     250,   255,   259,   269,   273,   279,   295,   304,   308,   313,
     322,   371,   394,   397,   402,   408,   414,   423,   468,   471,
     478,   483,   494,   500,   508,   518,   526,   529,   532,   535,
     542,   547,   554,   602,   605,   610,   614,   622,   626,   636,
     683,   696,   709,   720,   731,   742,   753,   764,   775,   788,
     801,   814,   827,   833,   842,   851,   886,   904,   913,   935,
     944,   948,   952,   956,   963,   968,   971,   974,   979,   985
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "TYPE", "STRUCT",
  "IF", "WHILE", "RETURN", "SEMI", "COMMA", "LC", "RC", "INVALID",
  "ASSIGN", "OR", "AND", "LT", "LE", "GT", "GE", "EQ", "NE", "PLUS",
  "MINUS", "MUL", "DIV", "NOT", "LP", "RP", "LB", "RB", "ID", "DOT",
  "ELSE", "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList",
  "Specifier", "StructSpecifier", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

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
     116,    -3,   -29,   -21,    17,   -29,   116,    23,   -29,   -29,
      16,   -29,   -29,   -29,   -29,   -29,     7,     3,    -4,    45,
      48,   224,     4,   -29,   -29,   264,    60,   203,   -29,   -13,
     -13,   -13,    50,   203,   -29,   -29,   -13,     5,    53,   -29,
     -29,   -29,   -29,   264,   264,   264,    36,   326,    34,   251,
     -29,   -29,    57,    71,    14,   -29,   -29,    52,   -29,   -29,
      26,    92,    -5,    54,   219,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
      56,   -29,    58,    63,   264,   -29,    80,   251,    86,   -29,
     -13,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   284,    25,
     347,   367,   385,   402,   413,   413,   413,   413,   413,   413,
      92,    92,    -5,    -5,   305,   -29,   264,   264,   114,   -29,
     -29,   -29,   -29,   -29,   264,   -29,   -29,   -29,   142,   170,
     -29,   -29,   -29,   251,   251,   251,   251,   -29,    59,   -29,
     -29,   251,   -29
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,     0,     0,     2,     0,     0,    14,    10,
      16,     1,     4,     8,     6,    18,    17,     0,    47,     0,
      11,     0,     0,     9,     5,     0,     0,     0,     7,     0,
       0,     0,     0,     0,    23,    21,     0,     0,    25,    70,
      71,    72,    74,     0,     0,     0,    69,    48,     0,    28,
      17,    12,     0,    45,     0,    15,    41,    26,    22,    20,
       0,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,    31,     0,    28,     0,    44,
       0,    43,    42,    24,    75,    62,    77,    66,    79,     0,
      73,    49,    51,    50,    52,    53,    54,    55,    57,    56,
      58,    59,    60,    61,     0,    67,     0,     0,     0,    27,
      29,    36,    30,    46,     0,    76,    65,    68,     0,     0,
      37,    32,    78,     0,     0,     0,     0,    38,    33,    39,
      35,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    90,   -29,    69,     1,   -29,    64,   -29,    66,
     -29,   109,    61,   106,   -11,   -29,   -28,     2,   -25,    20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    17,    31,     8,    18,    19,    37,
      38,    85,    86,    87,    32,    33,    52,    53,    88,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,     7,    15,    54,    23,    34,    58,     7,     9,    20,
       2,     3,    25,    10,    24,    91,    49,    11,    61,    62,
      63,    50,    56,    36,    13,    92,   125,    79,    26,    21,
      80,    20,     2,     3,    14,    35,    59,    22,    15,    98,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    94,   126,    16,    27,   118,
      29,    36,   123,    48,    55,    60,    64,    81,    89,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    90,    26,    95,    79,   121,   116,    80,
     115,   128,   129,   117,   119,   141,    12,   122,    51,    98,
      57,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   130,    -3,     1,    79,    77,
      78,    80,     2,     3,    79,   131,    93,    80,    28,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,   133,   132,     0,    79,     0,   120,    80,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   135,     0,   134,    79,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
       0,   136,    79,     0,    30,    80,   -40,   -40,   -40,     2,
       3,   -40,   -40,   -40,     0,     0,   -40,   -40,   -40,     0,
      96,     0,    39,    40,    41,    30,     0,     0,     0,   -40,
       2,     3,   -40,   -40,    42,     0,     0,   -40,   -40,   137,
     138,   139,   140,     0,     0,    43,     0,   142,    44,    45,
      97,     0,     0,    46,    39,    40,    41,     0,     0,    82,
      83,    84,     0,     0,    27,     0,    42,    39,    40,    41,
       0,     0,     0,     0,     0,     0,     0,    43,     0,    42,
      44,    45,     0,     0,     0,    46,     0,     0,     0,     0,
      43,     0,     0,    44,    45,     0,   124,     0,    46,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    79,     0,     0,    80,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    79,   127,     0,
      80,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    79,     0,
       0,    80,   -41,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    79,
       0,     0,    80,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    79,
       0,     0,    80,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    79,     0,     0,
      80,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    79,     0,     0,    80,    75,    76,
      77,    78,     0,     0,     0,    79,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
      25,     0,    15,    31,     1,     1,     1,     6,    11,     7,
       6,     7,    16,    34,    11,     1,    27,     0,    43,    44,
      45,    34,    33,    22,     1,    11,     1,    32,    32,    13,
      35,    29,     6,     7,    11,    31,    31,    30,    15,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     1,    31,    34,    13,    84,
      12,    60,    90,     3,    14,    12,    30,    33,    11,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    12,    32,    31,    32,     1,    30,    35,
      34,   116,   117,    30,    14,    36,     6,    11,    29,   124,
      36,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     1,     0,     1,    32,    27,
      28,    35,     6,     7,    32,    11,    60,    35,    19,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,     1,   124,    -1,    32,    -1,    87,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    -1,     1,    35,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    13,    14,    15,    -1,
       1,    -1,     3,     4,     5,     1,    -1,    -1,    -1,    26,
       6,     7,    29,    30,    15,    -1,    -1,    34,    14,   133,
     134,   135,   136,    -1,    -1,    26,    -1,   141,    29,    30,
      31,    -1,    -1,    34,     3,     4,     5,    -1,    -1,     8,
       9,    10,    -1,    -1,    13,    -1,    15,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    15,
      29,    30,    -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    29,    30,    -1,    12,    -1,    34,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    32,    33,    -1,
      35,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    35,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      -1,    -1,    35,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      -1,    -1,    35,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,
      35,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    32,    -1,    -1,    35,    25,    26,
      27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,     7,    38,    39,    40,    42,    43,    11,
      34,     0,    39,     1,    11,    15,    34,    41,    44,    45,
      54,    13,    30,     1,    11,    16,    32,    13,    48,    12,
       1,    42,    51,    52,     1,    31,    42,    46,    47,     3,
       4,     5,    15,    26,    29,    30,    34,    55,     3,    51,
      34,    41,    53,    54,    53,    14,    51,    44,     1,    31,
      12,    55,    55,    55,    30,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    32,
      35,    33,     8,     9,    10,    48,    49,    50,    55,    11,
      12,     1,    11,    46,     1,    31,     1,    31,    55,    56,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    34,    30,    30,    55,    14,
      49,     1,    11,    53,    12,     1,    31,    33,    55,    55,
       1,    11,    56,     1,    31,     1,    31,    50,    50,    50,
      50,    36,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     2,     3,
       2,     1,     3,     1,     1,     5,     2,     1,     1,     4,
       4,     3,     4,     3,     3,     1,     2,     4,     0,     2,
       2,     1,     3,     5,     7,     5,     2,     3,     5,     5,
       0,     2,     3,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     3,     4,     1,
       1,     1,     1,     3,     1,     3,     4,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 56 "src/splc.yy"
                   {
		(yyval.tree_node) = make_tree_node("Program", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
#ifdef DEBUG
		if (!has_error)
			show_tree((yyval.tree_node), 0);
#endif
	}
#line 1529 "./src/splc.tab.cc"
    break;

  case 3:
#line 65 "src/splc.yy"
            {
		(yyval.tree_node) = NULL;
	}
#line 1537 "./src/splc.tab.cc"
    break;

  case 4:
#line 68 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("ExtDefList", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1547 "./src/splc.tab.cc"
    break;

  case 5:
#line 75 "src/splc.yy"
                                  {
		(yyval.tree_node) = make_tree_node("ExtDef", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		// printf("Find global type: %s\n", type_name.c_str());
		string type_name = parse_Specifier((yyvsp[-2].tree_node));
		var_info_list var_name_list = parse_ExtDecList((yyvsp[-1].tree_node));
#ifdef DEBUG
		std::for_each(var_name_list.begin(), var_name_list.end(), [](const var_info_entry entry) { 
			printf("[%s, %d, %d]", std::get<0>(entry).c_str(), std::get<1>(entry), std::get<2>(entry));
		});
#endif
		if (type_table.count(type_name)) {
			type_t *type = type_table[type_name];
			std::for_each(var_name_list.begin(), var_name_list.end(), [&](const var_info_entry entry) { 
				string var_name = std::get<0>(entry);
				bool is_array = std::get<1>(entry);
				int length = std::get<2>(entry);
				tree_node *exp_node = std::get<3>(entry);
				if (var_table.count({var_name, scope})) {
					printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", (yyvsp[-2].tree_node)->line_no, var_name.c_str());
				} else {
					if (is_array) {
						if (length < 0) {
							printf("Error type 21 at Line %d: the length of array is less than 0.\n", (yyvsp[-2].tree_node)->line_no);
						} else {
							var_table.insert({{var_name, scope}, insert_array_type(type_name.c_str(), length)});
						}
					} else {
						if (exp_node != nullptr && !type_is_equal(find_type_in_value_node(find_first_right_value_node(exp_node)), type)) {
							printf("Error type 5 at Line %d: unmatching types appear at both sides of the assignment operator\n", (yyvsp[-1].tree_node)->line_no);
						}
						var_table.insert({{var_name, scope}, type_name});
					}
					
				}
			});
		} else {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, type_name.c_str());
		}
		
		
	}
#line 1597 "./src/splc.tab.cc"
    break;

  case 6:
#line 120 "src/splc.yy"
                         {
		(yyval.tree_node) = make_tree_node("ExtDef", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));

		string struct_name = parse_Specifier((yyvsp[-1].tree_node));
		type_t *ptr = new type_t();
		strcpy(ptr->name, struct_name.c_str());
		ptr->category = type_t::STRUCTURE;

		field_list_t *head = 0;
		dec_list vars_table = parse_DefList(
			(yyvsp[-1].tree_node)->child_first_ptr->node
			->child_first_ptr->next_child->next_child
			->next_child->node
		);
		// printf("====vars_table.size() = %d\n", vars_table.size());
		std::for_each(vars_table.rbegin(), vars_table.rend(), [&](const dec_entry vars) { 
			string type_name = vars.first;
			var_info_list var_list = vars.second;
			if (!type_table.count(type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-1].tree_node)->line_no, type_name.c_str());
			} else {
				std::for_each(var_list.rbegin(), var_list.rend(), [&](const var_info_entry entry) {
					field_list_t *new_node = new field_list_t();

					string var_name = std::get<0>(entry);
					bool is_array = std::get<1>(entry);
					int length = std::get<2>(entry);

					strcpy(new_node->name, var_name.c_str());
					if (is_array) {
						string type_name_array;
						if (length < 0) {
							printf("Error type 21 at Line %d: the length of array is less than 0\n", (yyvsp[-1].tree_node)->line_no);
						} else {
							type_name_array = insert_array_type(type_name.c_str(), length);
							new_node->type = type_table[type_name_array];
						}
					} else {
						new_node->type = type_table[type_name];
					}
					new_node->next = head;
					head = new_node;
				});
			}
		});
		ptr->data.structure = head;
		if (type_table.count(struct_name)) {
			printf("Error type 15 at Line %d: redefine the structure type with same name\n", (yyvsp[-1].tree_node)->line_no);
		} else {
			bool is_valid = true;
			std::for_each(type_table.begin(), type_table.end(), [&](pair<string, type_t*> p) {
				type_t *type = p.second;
				if (is_valid && type_is_equal(type, ptr)) {
#ifdef DEBUG
					printf("Find the same structure: %s\n", type->name);
#endif
					is_valid = false;
				}
			});
			type_table.insert({struct_name, ptr});
		}
#ifdef DEBUG
		printf("INSERTED [%s, 0x%lx]", struct_name.c_str(), (long)ptr);
		printf("Find user-defined struct: %s:\n", struct_name.c_str());
		field_list_t *cur = head;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif
	}
#line 1675 "./src/splc.tab.cc"
    break;

  case 7:
#line 193 "src/splc.yy"
                                  {
		(yyval.tree_node) = make_tree_node("ExtDef", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		func_t *func = func_table[(yyvsp[-1].tree_node)->child_first_ptr->node->name+4];

		bool is_valid = 1;
		// check return type
		string ret_type_name = parse_Specifier((yyvsp[-2].tree_node));
		if (!type_table.count(ret_type_name)) {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, ret_type_name.c_str());
			is_valid = 0;
		} else {
			func->ret_type = type_table[ret_type_name];
		}

		return_list ret_list = find_return_list((yyvsp[0].tree_node));
#ifdef DEBUG
		printf("DETECTED return list: \n");
		std::for_each(ret_list.begin(), ret_list.end(), [&](const return_entry entry) {
			printf("[%s, %d], ", entry.first->name, entry.second);
		});
		puts("");
#endif
		std::for_each(ret_list.begin(), ret_list.end(), [&](const return_entry entry) {
			tree_node *node = entry.first;
			int line_no = entry.second;

			tree_node *leaf = find_first_right_value_node(node);
			type_t *leaf_type = find_type_in_value_node(leaf);
#ifdef DEBUG
			printf("Find return type: [%s]\n", leaf_type->name);
#endif

			if (leaf_type != func->ret_type) {
				printf("Error Type 8 at Line %d: function’s return value type mismatches the declared type\n", line_no);
			}

		});

		for (auto it = var_table.begin(); it != var_table.end(); ) {
			auto const& [var_name, var_scope] = (*it).first;
			if (scope == var_scope) it = var_table.erase(it);
			else ++it;
		}
		scope_flag = false;
		scope--;

	}
#line 1731 "./src/splc.tab.cc"
    break;

  case 8:
#line 244 "src/splc.yy"
                         {
		printf("Error type B at Line %d: Missing semicolon 1';'\n",(yyvsp[-1].tree_node)->line_no);
	}
#line 1739 "./src/splc.tab.cc"
    break;

  case 9:
#line 247 "src/splc.yy"
                                     {
		printf("Error type B at Line %d: Missing semicolon 2';'\n",(yyvsp[-2].tree_node)->line_no);
	}
#line 1747 "./src/splc.tab.cc"
    break;

  case 10:
#line 250 "src/splc.yy"
                    {
		printf("Error type 2B at Line %d: Missing specifier\n", (yyvsp[0].tree_node)->line_no-1);
	}
#line 1755 "./src/splc.tab.cc"
    break;

  case 11:
#line 255 "src/splc.yy"
            {
		(yyval.tree_node) = make_tree_node("ExtDecList", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1764 "./src/splc.tab.cc"
    break;

  case 12:
#line 259 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("ExtDecList", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1775 "./src/splc.tab.cc"
    break;

  case 13:
#line 269 "src/splc.yy"
             {
		(yyval.tree_node) = make_tree_node("Specifier", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1784 "./src/splc.tab.cc"
    break;

  case 14:
#line 273 "src/splc.yy"
                          {
		(yyval.tree_node) = make_tree_node("Specifier", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1793 "./src/splc.tab.cc"
    break;

  case 15:
#line 279 "src/splc.yy"
                                {
		for (auto it = var_table.begin(); it != var_table.end(); ) {
			auto const& [var_name, var_scope] = (*it).first;
			if (scope == var_scope) it = var_table.erase(it);
			else ++it;
		}
		scope_flag = false;
		scope--;

		(yyval.tree_node) = make_tree_node("StructSpecifier", (yyvsp[-4].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
		add_child((yyval.tree_node), (yyvsp[-4].tree_node));
	}
#line 1814 "./src/splc.tab.cc"
    break;

  case 16:
#line 295 "src/splc.yy"
                    {
		(yyval.tree_node) = make_tree_node("StructSpecifier", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1824 "./src/splc.tab.cc"
    break;

  case 17:
#line 304 "src/splc.yy"
           {
		(yyval.tree_node) = make_tree_node("VarDec", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1833 "./src/splc.tab.cc"
    break;

  case 18:
#line 308 "src/splc.yy"
                  {
		(yyval.tree_node) = make_tree_node("VarDec", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		has_error=1;
	}
#line 1843 "./src/splc.tab.cc"
    break;

  case 19:
#line 313 "src/splc.yy"
                           {
		(yyval.tree_node) = make_tree_node("VarDec", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 1855 "./src/splc.tab.cc"
    break;

  case 20:
#line 322 "src/splc.yy"
                         {
		++scope;
		scope_flag = true;

		func_t *func = new func_t();
		string func_name = (yyvsp[-3].tree_node)->name+4;
		if (func_table.count(func_name)) {
			printf("Error Type 4 at Line %d: function \"%s\" is redefined.\n", (yyvsp[-2].tree_node)->line_no, func_name.c_str());
		}
		// check para's type & name
		field_list_t *head = 0, *tail = head;

		list<pair<string, string>> var_list = parse_VarList((yyvsp[-1].tree_node));
		std::for_each(var_list.begin(), var_list.end(), [&](const pair<string, string> var) { 
			string para_type_name = var.first;
			string para_name = var.second;
			if (!type_table.count(para_type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, para_type_name.c_str());
			} if (var_table.count({para_name, scope})) {
				printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", (yyvsp[-2].tree_node)->line_no, para_name.c_str());
			} else {
				field_list_t *new_node = new field_list_t();
				strcpy(new_node->name, para_name.c_str());
				new_node->type = type_table[para_type_name];
				new_node->next = 0;
				if (!head) head = tail = new_node;
				else tail->next = new_node, tail = new_node;

				var_table.insert({{para_name, scope}, para_type_name});
			}
		});
		
		func->args_num = var_list.size();
		func->args_list = head;
		func_table.insert({func_name, func});
#ifdef DEBUG
		printf("Find user-defined function %s:\n", func_name.c_str());
		field_list_t *cur = func->args_list;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif
		(yyval.tree_node) = make_tree_node("FunDec", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 1909 "./src/splc.tab.cc"
    break;

  case 21:
#line 371 "src/splc.yy"
                   {
		func_t *func = new func_t();
		string func_name = (yyvsp[-2].tree_node)->name+4;
		if (func_table.count(func_name)) {
			printf("Error Type 4 at Line %d: function \"%s\" is redefined.\n", (yyvsp[-1].tree_node)->line_no, func_name.c_str());
		}
		func->args_num = 0;
		func_table.insert({func_name, func});

#ifdef DEBUG
		printf("Find user-defined function %s:\n", func_name.c_str());
		field_list_t *cur = func->args_list;
		while (cur) {
			printf("\t%s: %s\n", cur->type->name, cur->name);
			cur = cur->next;
		}
#endif

		(yyval.tree_node) = make_tree_node("FunDec", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1937 "./src/splc.tab.cc"
    break;

  case 22:
#line 394 "src/splc.yy"
                                 {
        	printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-3].tree_node)->line_no);
    	}
#line 1945 "./src/splc.tab.cc"
    break;

  case 23:
#line 397 "src/splc.yy"
                         {
        	printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-2].tree_node)->line_no);
    	}
#line 1953 "./src/splc.tab.cc"
    break;

  case 24:
#line 402 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("VarList", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 1964 "./src/splc.tab.cc"
    break;

  case 25:
#line 408 "src/splc.yy"
                   {
		(yyval.tree_node) = make_tree_node("VarList", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 1973 "./src/splc.tab.cc"
    break;

  case 26:
#line 414 "src/splc.yy"
                         {
		(yyval.tree_node) = make_tree_node("ParamDec", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 1983 "./src/splc.tab.cc"
    break;

  case 27:
#line 423 "src/splc.yy"
                               {
		// std::remove_if(var_table.begin(), var_table.end(), [&](const auto &entry) -> bool {
		// 	int var_scope = entry.first.second;
		// 	if (scope == var_scope) return true;
		// 	return false;
		// });

		(yyval.tree_node) = make_tree_node("CompSt", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
/*
		dec_list vars_table = parse_DefList($2);
		std::for_each(vars_table.rbegin(), vars_table.rend(), [&](const dec_entry vars) { 
			string type_name = vars.first;
			var_info_list var_list = vars.second;
			if (!type_table.count(type_name)) {
				printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", $1->line_no, type_name.c_str());
			} else {
				std::for_each(var_list.rbegin(), var_list.rend(), [&](const var_info_entry entry) {
					string var_name = std::get<0>(entry);
					bool is_array = std::get<1>(entry);
					int length = std::get<2>(entry);

					if (var_table.count(var_name)) {
						printf("Error type 2 at Line %d: variable \"%s\" is redefined.\n", $1->line_no, var_name.c_str());
					} else {
						if (is_array) {
							if (length < 0) {
								printf("Error type 21 at Line %d: the length of array is less than 0\n", $1->line_no);
							} else {
								var_table.insert({var_name, insert_array_type(type_name.c_str(), length)});
							}
						} else {
							var_table.insert({var_name, type_name});
						}	
					}
				});
				
			}
		});
*/
	}
#line 2032 "./src/splc.tab.cc"
    break;

  case 28:
#line 468 "src/splc.yy"
          {
		(yyval.tree_node) = NULL;
	}
#line 2040 "./src/splc.tab.cc"
    break;

  case 29:
#line 471 "src/splc.yy"
                        {
		(yyval.tree_node) = make_tree_node("StmtList", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 2050 "./src/splc.tab.cc"
    break;

  case 30:
#line 478 "src/splc.yy"
                 {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 2060 "./src/splc.tab.cc"
    break;

  case 31:
#line 483 "src/splc.yy"
                 {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		for (auto it = var_table.begin(); it != var_table.end(); ) {
			auto const& [var_name, var_scope] = (*it).first;
			if (scope == var_scope) it = var_table.erase(it);
			else ++it;
		}
		scope_flag = false;
		scope--;
	}
#line 2076 "./src/splc.tab.cc"
    break;

  case 32:
#line 494 "src/splc.yy"
                          {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2087 "./src/splc.tab.cc"
    break;

  case 33:
#line 500 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-4].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
		add_child((yyval.tree_node), (yyvsp[-4].tree_node));
	}
#line 2100 "./src/splc.tab.cc"
    break;

  case 34:
#line 508 "src/splc.yy"
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
#line 2115 "./src/splc.tab.cc"
    break;

  case 35:
#line 518 "src/splc.yy"
                               {
		(yyval.tree_node) = make_tree_node("Stmt", (yyvsp[-4].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
		add_child((yyval.tree_node), (yyvsp[-4].tree_node));
	}
#line 2128 "./src/splc.tab.cc"
    break;

  case 36:
#line 526 "src/splc.yy"
                    {
		printf("Error type B at Line %d: Missing semicolon 3';'\n",(yyvsp[-1].tree_node)->line_no);
	}
#line 2136 "./src/splc.tab.cc"
    break;

  case 37:
#line 529 "src/splc.yy"
                           {
		printf("Error type B at Line %d: Missing semicolon ';'\n",(yyvsp[-2].tree_node)->line_no);
	}
#line 2144 "./src/splc.tab.cc"
    break;

  case 38:
#line 532 "src/splc.yy"
                                  { 
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-4].tree_node)->line_no);
	}
#line 2152 "./src/splc.tab.cc"
    break;

  case 39:
#line 535 "src/splc.yy"
                                     {
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-4].tree_node)->line_no);
	}
#line 2160 "./src/splc.tab.cc"
    break;

  case 40:
#line 542 "src/splc.yy"
         {
		(yyval.tree_node) = NULL; 
		if (!scope_flag) ++scope;
		scope_flag = false;
	}
#line 2170 "./src/splc.tab.cc"
    break;

  case 41:
#line 547 "src/splc.yy"
                      {
		(yyval.tree_node) = make_tree_node("DefList", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 2180 "./src/splc.tab.cc"
    break;

  case 42:
#line 554 "src/splc.yy"
                               {
		if (!scope_flag) ++scope;
		scope_flag = true;
		(yyval.tree_node) = make_tree_node("Def", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		bool is_valid = 1;
		// check type
		string type_name = parse_Specifier((yyvsp[-2].tree_node));
		if (!type_table.count(type_name)) {
			printf("Error type 16 at Line %d: type \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, type_name.c_str());
			is_valid = 0;
		}
		// check names
		var_info_list var_name_list = parse_DecList((yyvsp[-1].tree_node));
		type_t *type = type_table[type_name];
		std::for_each(var_name_list.begin(), var_name_list.end(), [&](const var_info_entry entry) { 
			string var_name = std::get<0>(entry);
			bool is_array = std::get<1>(entry);
			int length = std::get<2>(entry);
			tree_node *exp_node = std::get<3>(entry);
			if (var_table.count({var_name, scope})) {
				printf("Error type 3 at Line %d: variable \"%s\" is redefined.\n", (yyvsp[-2].tree_node)->line_no, var_name.c_str());
			} else if (is_valid) {
				if (is_array) {
					if (length < 0) {
						printf("Error type 21 at Line %d: the length of array is less than 0\n", (yyvsp[-2].tree_node)->line_no);
					} else {
						var_table.insert({{var_name, scope}, insert_array_type(type_name.c_str(), length)});
					}
				} else {
					if (exp_node != nullptr && !type_is_equal(find_type_in_value_node(find_first_right_value_node(exp_node)), type)) {
						printf("Error type 5 at Line %d: unmatching types appear at both sides of the assignment operator\n", (yyvsp[-1].tree_node)->line_no);
					}
					var_table.insert({{var_name, scope}, type_name});
				}
			}
		});
#ifdef DEBUG
		printf("Find local variables of type \"%s\": ", type_name.c_str());
		std::for_each(var_name_list.begin(), var_name_list.end(), [](const var_info_entry entry) { 
			printf("[%s, %d, %d]", std::get<0>(entry).c_str(), std::get<1>(entry), std::get<2>(entry));
		});
		puts("");
#endif
	}
#line 2233 "./src/splc.tab.cc"
    break;

  case 43:
#line 602 "src/splc.yy"
                                  {
		printf("Error type B at Line %d: Missing semicolon 4';'\n",(yyvsp[-2].tree_node)->line_no);	
	}
#line 2241 "./src/splc.tab.cc"
    break;

  case 44:
#line 605 "src/splc.yy"
                             {
		printf("Error type 2B at Line %d: Missing specifier\n",(yyvsp[-1].tree_node)->line_no-1);
	}
#line 2249 "./src/splc.tab.cc"
    break;

  case 45:
#line 610 "src/splc.yy"
            {
		(yyval.tree_node) = make_tree_node("DecList", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2258 "./src/splc.tab.cc"
    break;

  case 46:
#line 614 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("DecList", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2269 "./src/splc.tab.cc"
    break;

  case 47:
#line 622 "src/splc.yy"
               {
		(yyval.tree_node) = make_tree_node("Dec", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2278 "./src/splc.tab.cc"
    break;

  case 48:
#line 626 "src/splc.yy"
                            {
		(yyval.tree_node) = make_tree_node("Dec", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2289 "./src/splc.tab.cc"
    break;

  case 49:
#line 636 "src/splc.yy"
                       {

		// single varible on the left
		int left_value_cnt = find_all_left_value_node((yyvsp[-2].tree_node)).size();
		int right_value_cnt = find_all_right_value_node((yyvsp[-2].tree_node)).size();
		if (left_value_cnt == 1 && right_value_cnt == 1) {
			type_t *var_type = find_type_in_value_node(find_first_left_value_node((yyvsp[-2].tree_node)));
			tree_node *leaf = find_first_right_value_node((yyvsp[0].tree_node));
			type_t *leaf_type = find_type_in_value_node(leaf);
			
#ifdef DEBUG
			printf("Detect ASSIGN, left[%s], right[%s]\n", var_type->name, leaf_type->name);
#endif
			if (!type_is_equal(var_type, leaf_type)) {
				printf("Error type 5 at Line %d: unmatching types appear at both sides of the assignment operator\n", (yyvsp[-1].tree_node)->line_no);
				(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
			} else {
				(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
			}
/*		} else if ($1->children_number == 3 && !memcmp($1->child_first_ptr->next_child->node->name, "DOT", 3)) {
			
			struct_var_list struct_list = parse_Struct_Exp($1);
			printf("==OK==\n");

			type_t *var_type = parse_instance_type_in_struct(struct_list, $1->line_no);
			
			tree_node *leaf = find_first_right_value_node($3);
			type_t *leaf_type = find_type_in_value_node(leaf);
#ifdef DEBUG
			printf("Detect ASSIGN: \n, left[%s], right[%s]\n", var_type->name, leaf_type->name);
#endif
			if (var_type != leaf_type) {
				printf("Error type 6 at Line %d: unmatching types appear at both sides of the assignment operator\n", $2->line_no);
				$$ = make_tree_node("Exp", $1->line_no, 0);
			} else {
				$$ = make_tree_node("Exp", $1->line_no, 0);
			}
*/
		} else {
			printf("Error type 6 at Line %d: rvalue appears on the left-hand side of the assignment operator\n", (yyvsp[-1].tree_node)->line_no);
			(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		}
		// $$ = make_tree_node("Exp", $1->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2341 "./src/splc.tab.cc"
    break;

  case 50:
#line 683 "src/splc.yy"
                      {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		} else if (type1 != type_table["int"]) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2359 "./src/splc.tab.cc"
    break;

  case 51:
#line 696 "src/splc.yy"
                     {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		} else if (type1 != type_table["int"]) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2377 "./src/splc.tab.cc"
    break;

  case 52:
#line 709 "src/splc.yy"
                     {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2393 "./src/splc.tab.cc"
    break;

  case 53:
#line 720 "src/splc.yy"
                     {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2409 "./src/splc.tab.cc"
    break;

  case 54:
#line 731 "src/splc.yy"
                     {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2425 "./src/splc.tab.cc"
    break;

  case 55:
#line 742 "src/splc.yy"
                     {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2441 "./src/splc.tab.cc"
    break;

  case 56:
#line 753 "src/splc.yy"
                     {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2457 "./src/splc.tab.cc"
    break;

  case 57:
#line 764 "src/splc.yy"
                     {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2473 "./src/splc.tab.cc"
    break;

  case 58:
#line 775 "src/splc.yy"
                       {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2491 "./src/splc.tab.cc"
    break;

  case 59:
#line 788 "src/splc.yy"
                        {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2509 "./src/splc.tab.cc"
    break;

  case 60:
#line 801 "src/splc.yy"
                      {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2527 "./src/splc.tab.cc"
    break;

  case 61:
#line 814 "src/splc.yy"
                      {
		type_t *type1 = find_type_in_value_node(find_first_right_value_node((yyvsp[-2].tree_node)));
		type_t *type2 = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type1 != type2) {
			printf("Error type 7 at Line %d: unmatching operands\n", (yyvsp[-1].tree_node)->line_no);
		} else if (type1 != type_table["int"] && type1 != type_table["float"]) {
			printf("Error type 20 at Line %d: do arithmatic operation on invalid type\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2545 "./src/splc.tab.cc"
    break;

  case 62:
#line 827 "src/splc.yy"
                    {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2556 "./src/splc.tab.cc"
    break;

  case 63:
#line 833 "src/splc.yy"
                    {
		type_t *type = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type != type_table["int"] && type != type_table["float"]) {
			printf("Error type 18 at Line %d: MINUS operation is done on an invalid expression\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
	}
#line 2570 "./src/splc.tab.cc"
    break;

  case 64:
#line 842 "src/splc.yy"
                  {
		type_t *type = find_type_in_value_node(find_first_right_value_node((yyvsp[0].tree_node)));
		if (type != type_table["int"]) {
			printf("Error type 17 at Line %d: not operation is done on a non-integer expression\n", (yyvsp[-1].tree_node)->line_no);	
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-1].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));		
	}
#line 2584 "./src/splc.tab.cc"
    break;

  case 65:
#line 851 "src/splc.yy"
                        {
		
		if (!func_table.count((yyvsp[-3].tree_node)->name+4)) {
			if (type_table.count((yyvsp[-3].tree_node)->name+4) || find_var_in_table((yyvsp[-3].tree_node)->name+4) != var_table.end()) {
				printf("Error type 11 at Line %d: applying function invocation operator on non-function variables\n", (yyvsp[-3].tree_node)->line_no);
			} else {
				printf("Error type 2 at Line %d: function \"%s\" is not defined.\n", (yyvsp[-3].tree_node)->line_no, (yyvsp[-3].tree_node)->name+4);
			}
			
		} else {
			string func_name = string((yyvsp[-3].tree_node)->name+4);
			args_list args = parse_Args_list((yyvsp[-1].tree_node));
			field_list_t *func_args = func_table[func_name]->args_list;

			if (args.size() != func_table[func_name]->args_num) {
				printf("Error type 9 at Line %d: the arguments' number does not match, expect: %d, actual: %lu\n", (yyvsp[-3].tree_node)->line_no, func_table[func_name]->args_num, args.size());
			} else {
				std::for_each(args.begin(), args.end(), [&](tree_node* node) {
					tree_node *leaf = find_first_right_value_node(node);
					type_t *type = find_type_in_value_node(leaf);
					
					if (type != func_args->type) {
						printf("Error type 9 at Line %d: the arguments' type does not match, expect: %s, actual: %s\n", (yyvsp[-3].tree_node)->line_no, func_args->type->name, type->name);
					}
					func_args = func_args->next;
				});
			}
			
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 2624 "./src/splc.tab.cc"
    break;

  case 66:
#line 886 "src/splc.yy"
                   {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));

		const char *func_name = (yyvsp[-2].tree_node)->name+4;
		if (!func_table.count((yyvsp[-2].tree_node)->name+4)) {
			if (type_table.count((yyvsp[-2].tree_node)->name+4) || find_var_in_table((yyvsp[-2].tree_node)->name+4) != var_table.end()) {
				printf("Error type 11 at Line %d: applying function invocation operator on non-function variables\n", (yyvsp[-2].tree_node)->line_no);
			} else {
				printf("Error type 2 at Line %d: function \"%s\" is not defined.\n", (yyvsp[-2].tree_node)->line_no, func_name);
			}
		}
		if (func_table[func_name]->args_num != 0) {
			printf("Error type 9 at Line %d: the arguments' number does not match, expect: %d, actual: %d\n", (yyvsp[-2].tree_node)->line_no, func_table[func_name]->args_num, 0);
		}
	}
#line 2647 "./src/splc.tab.cc"
    break;

  case 67:
#line 904 "src/splc.yy"
                               {
#ifdef DEBUG
		printf("Reduce DOT\n");
#endif
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2661 "./src/splc.tab.cc"
    break;

  case 68:
#line 913 "src/splc.yy"
                        {
#ifdef DEBUG
		printf("Reduce []\n");
#endif
		if (find_all_left_value_node((yyvsp[-3].tree_node)).size() != 1 || find_all_right_value_node((yyvsp[-3].tree_node)).size() != 1) {
			printf("Error type 10 at Line %d: apply index operator on non-array type\n", (yyvsp[-3].tree_node)->line_no);
		} else {
			type_t *type = find_type_in_value_node(find_first_left_value_node((yyvsp[-3].tree_node)));
			if (type->category != type_t::ARRAY) {
				printf("Error type 10 at Line %d: apply index operator on non-array type\n", (yyvsp[-3].tree_node)->line_no);
			}
		}
		type_t *type_in = find_type_in_value_node(find_first_right_value_node((yyvsp[-1].tree_node)));
		if (type_in->category != type_t::PRIMITIVE || type_in->data.primitive != type_t::data_t::ENUM_INT) {
			printf("Error type 12 at Line %d: array indexing with a non-integer type expression\n", (yyvsp[-1].tree_node)->line_no);
		}
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-3].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
		add_child((yyval.tree_node), (yyvsp[-3].tree_node));
	}
#line 2688 "./src/splc.tab.cc"
    break;

  case 69:
#line 935 "src/splc.yy"
             {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));

		const char *var_name = (yyvsp[0].tree_node)->name+4;
		if (find_var_in_table(var_name) == var_table.end()) {
			printf("Error type 1 at Line %d: variable \"%s\" is used without definition.\n", (yyvsp[0].tree_node)->line_no, var_name);
		}
	}
#line 2702 "./src/splc.tab.cc"
    break;

  case 70:
#line 944 "src/splc.yy"
              {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2711 "./src/splc.tab.cc"
    break;

  case 71:
#line 948 "src/splc.yy"
                {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2720 "./src/splc.tab.cc"
    break;

  case 72:
#line 952 "src/splc.yy"
               {
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2729 "./src/splc.tab.cc"
    break;

  case 73:
#line 956 "src/splc.yy"
                          {
		has_error = 1;
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2741 "./src/splc.tab.cc"
    break;

  case 74:
#line 963 "src/splc.yy"
                  {
		has_error = 1;
		(yyval.tree_node) = make_tree_node("Exp", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2751 "./src/splc.tab.cc"
    break;

  case 75:
#line 968 "src/splc.yy"
                      {
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-2].tree_node)->line_no);
	}
#line 2759 "./src/splc.tab.cc"
    break;

  case 76:
#line 971 "src/splc.yy"
                          {
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-3].tree_node)->line_no);
	}
#line 2767 "./src/splc.tab.cc"
    break;

  case 77:
#line 974 "src/splc.yy"
                     {
		printf("Error type B at Line %d: Missing closing parenthesis ')'\n",(yyvsp[-2].tree_node)->line_no);
	}
#line 2775 "./src/splc.tab.cc"
    break;

  case 78:
#line 979 "src/splc.yy"
                       {
		(yyval.tree_node) = make_tree_node("Args", (yyvsp[-2].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
		add_child((yyval.tree_node), (yyvsp[-1].tree_node));
		add_child((yyval.tree_node), (yyvsp[-2].tree_node));
	}
#line 2786 "./src/splc.tab.cc"
    break;

  case 79:
#line 985 "src/splc.yy"
              {
		(yyval.tree_node) = make_tree_node("Args", (yyvsp[0].tree_node)->line_no, 0);
		add_child((yyval.tree_node), (yyvsp[0].tree_node));
	}
#line 2795 "./src/splc.tab.cc"
    break;


#line 2799 "./src/splc.tab.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 991 "src/splc.yy"


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

type_t* parse_instance_type_in_struct(struct_var_list list, int line_no) {
	if (list.size() == 1) {
		return type_table[(*find_var_in_table(*(list.begin()))).second];
	}
	type_t *cur_type = type_table[(*find_var_in_table(*(list.begin()))).second];
	list.pop_front();
	bool has_error = false;
	std::for_each(list.begin(), list.end(), [&](const string var_name) {
		if (var_name == "&INDEX") {
			if (cur_type->category != type_t::ARRAY) {
				printf("Error type 10 at Line %d: apply index operator on non-array type\n", line_no);
				has_error = true;
			} else {
				cur_type = cur_type->data.array->base;
			}
		} else {
			if (cur_type->category != type_t::STRUCTURE) {
				printf("Error type 13 at Line %d: accessing members of a non-structure variable.\n", line_no);
				has_error = true;
			}
			cur_type = find_instance_type_in_struct(cur_type, var_name);
			if (cur_type == 0) {
				printf("Error type 14 at Line %d: accessing an undefined structure member \"%s\".\n", line_no, var_name.c_str());
				has_error = true;
			}
		}
	});
	if (has_error) return 0;
	else return cur_type;
}

type_t *find_type_in_value_node(tree_node *leaf, bool &is_left) {
	type_t *leaf_type = 0;
	if (!leaf) return 0;
	if (!memcmp(leaf->name, "INT", 3)) {
		leaf_type = type_table["int"];
		is_left = false;
	} else if (!memcmp(leaf->name, "CHAR", 4)) {
		leaf_type = type_table["char"];
		is_left = false;
	} else if (!memcmp(leaf->name, "FLOAT", 5)) {
		leaf_type = type_table["float"];
		is_left = false;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "DOT")) {
		leaf_type = parse_instance_type_in_struct(parse_Struct_Exp(leaf), leaf->line_no);
		is_left = true;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LP")) {
		leaf_type = func_table[leaf->child_first_ptr->node->name+4]->ret_type;
		is_left = false;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LB")) {
		struct_var_list list = parse_Struct_Exp(leaf->child_first_ptr->node);
		type_t *array_type = parse_instance_type_in_struct(list, leaf->line_no);
		if (array_type->category == type_t::ARRAY) {
			leaf_type = parse_instance_type_in_struct(list, leaf->line_no)->data.array->base;
		}
		is_left = true;
	} else {
		leaf_type = type_table[(*find_var_in_table(leaf->name+4)).second];
		is_left = true;
	}
	return leaf_type;
}

type_t *find_type_in_value_node(tree_node *leaf) {
	type_t *leaf_type = 0;
	if (!leaf) return 0;
	if (!memcmp(leaf->name, "INT", 3)) {
		leaf_type = type_table["int"];
	} else if (!memcmp(leaf->name, "CHAR", 4)) {
		leaf_type = type_table["char"];
	} else if (!memcmp(leaf->name, "FLOAT", 5)) {
		leaf_type = type_table["float"];
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "DOT")) {
		leaf_type = parse_instance_type_in_struct(parse_Struct_Exp(leaf), leaf->line_no);
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LP")) { 
		func_t *func_entry = func_table[leaf->child_first_ptr->node->name+4];
		if (!func_entry) {
			leaf_type = 0;
		} else leaf_type = func_entry->ret_type;
	} else if (!memcmp(leaf->name, "Exp", 3) && !strcmp(leaf->child_first_ptr->next_child->node->name, "LB")) {
		struct_var_list list = parse_Struct_Exp(leaf->child_first_ptr->node);
		type_t *array_type = parse_instance_type_in_struct(list, leaf->line_no);
		if (array_type->category == type_t::ARRAY) {
			leaf_type = parse_instance_type_in_struct(list, leaf->line_no)->data.array->base;
		}
	} else {
		leaf_type = type_table[(*find_var_in_table(leaf->name+4)).second];
	}
	return leaf_type;
}

string insert_array_type(const char *type_name, int length) {
	char type_name_array[32];
	sprintf(type_name_array, "%s_%d", type_name, length);
	if (type_table.count(type_name_array)) return string(type_name_array);
	type_t *ptr = new type_t();
	strcpy(ptr->name, type_name_array);
	ptr->category = type_t::ARRAY;
	ptr->data.array = new array_t();
	ptr->data.array->base = type_table[type_name];
	ptr->data.array->size = length;
	type_table.insert({type_name_array, ptr});
	return string(type_name_array);
}

map<pair<string, int>, string>::iterator find_var_in_table(string var_name) {
	map<pair<string, int>, string>::iterator ret;
	int max_scope = -1;
	for (map<pair<string, int>, string>::iterator it = var_table.begin(); it != var_table.end(); ++it) {
		auto entry = *it;
		if (entry.first.first == var_name && entry.first.second > max_scope) {
			ret = it;
			max_scope = entry.first.second;
		}
	}
	if (max_scope == -1) return var_table.end();
	return ret;
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
