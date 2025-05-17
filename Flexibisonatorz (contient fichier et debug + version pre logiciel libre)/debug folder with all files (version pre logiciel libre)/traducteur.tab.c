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
#line 1 "../src/traducteur.y"

#include <stdio.h>      // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>     // Inclusion de la bibliothèque standard pour malloc, free, exit...
#include <string.h>     // Inclusion de la bibliothèque pour les fonctions de manipulation de chaînes

#define YYSTYPE char*   // Définition du type des valeurs retournées par le parser : chaîne de caractères
FILE *out;              // Fichier de sortie dans lequel sera généré le code C final
int yylex(void);        // Prototype de la fonction lexicale générée par Flex
int yyerror(char *s);   // Prototype de la fonction d’erreur appelée en cas d’erreur syntaxique

// Structure pour la table des symboles (variables déclarées)
typedef struct Symbole {
	char *nom;             // Nom de la variable
	char *type;            // Type de la variable ("int" ou "chaine")
	struct Symbole *suivant; // Pointeur vers le symbole suivant (liste chaînée)
} Symbole;

Symbole *table_symbole = NULL;  // Pointeur vers le début de la table des symboles

// Fonction pour ajouter une variable dans la table des symboles
void ajouter_symbole(const char *nom, const char *type) {
	// Vérifier si la variable existe déjà (pour éviter doublon)
	for (Symbole *s = table_symbole; s != NULL; s = s->suivant) {
		if (strcmp(s->nom, nom) == 0) return; // Variable déjà présente, on ne fait rien
	}
	// Allocation mémoire d’un nouveau symbole
	Symbole *s = malloc(sizeof(Symbole));
	s->nom = strdup(nom);       // Copier le nom
	s->type = strdup(type);     // Copier le type
	s->suivant = table_symbole; // Insérer en tête de liste chaînée
	table_symbole = s;
}

// Fonction pour récupérer le type d’une variable donnée
const char *type_de_variable(const char *nom) {
	for (Symbole *s = table_symbole; s != NULL; s = s->suivant) {
		if (strcmp(s->nom, nom) == 0) return s->type;  // Retourner le type si trouvée
	}
	return NULL;  // Retourner NULL si variable non trouvée
}

// Fonction utilitaire pour concaténer deux instructions en les séparant par ce qu'on veut (ici un saut de ligne)
char *concat_instruction(const char *i1, const char *i2) {
    char *res = malloc(strlen(i1) + strlen(i2) + 5); // Allocation mémoire
    sprintf(res, "%s\n%s", i1, i2);                 // Formater la chaîne résultat
    return res;
}

// Fonction pour ajouter une tabulation à chaque ligne d'une chaîne (indentation)
char* indent(const char *code) {
    const char *tab = "\t";
    int len = strlen(code);
    char *res = malloc(len * 2 + 1); // allocation large (doublée)
    res[0] = '\0';
    
    const char *ptr = code;
    while (*ptr) {
        strcat(res, tab);  // Ajouter une tabulation
        while (*ptr && *ptr != '\n') {
            strncat(res, ptr, 1);  // Copier caractère par caractère
            ptr++;
        }
        if (*ptr == '\n') {
            strncat(res, ptr, 1);  // Ajouter le \n
            ptr++;
        }
    }
    return res;
}



#line 144 "traducteur.tab.c"

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

#include "traducteur.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AFFICHER = 3,                   /* AFFICHER  */
  YYSYMBOL_SI = 4,                         /* SI  */
  YYSYMBOL_ALORS = 5,                      /* ALORS  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_SINON = 7,                      /* SINON  */
  YYSYMBOL_DECLARER = 8,                   /* DECLARER  */
  YYSYMBOL_COMME = 9,                      /* COMME  */
  YYSYMBOL_OP = 10,                        /* OP  */
  YYSYMBOL_DEMANDER = 11,                  /* DEMANDER  */
  YYSYMBOL_POUR = 12,                      /* POUR  */
  YYSYMBOL_JUSQUA = 13,                    /* JUSQUA  */
  YYSYMBOL_FAIRE = 14,                     /* FAIRE  */
  YYSYMBOL_TANTQUE = 15,                   /* TANTQUE  */
  YYSYMBOL_ET = 16,                        /* ET  */
  YYSYMBOL_IDENTIFIANT = 17,               /* IDENTIFIANT  */
  YYSYMBOL_ENTIER = 18,                    /* ENTIER  */
  YYSYMBOL_CHAINE = 19,                    /* CHAINE  */
  YYSYMBOL_COMMENTAIRE = 20,               /* COMMENTAIRE  */
  YYSYMBOL_FINLIGNE = 21,                  /* FINLIGNE  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_23_ = 23,                       /* '+'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '*'  */
  YYSYMBOL_26_ = 26,                       /* '/'  */
  YYSYMBOL_27_ = 27,                       /* '%'  */
  YYSYMBOL_28_ = 28,                       /* '{'  */
  YYSYMBOL_29_ = 29,                       /* '}'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_programme = 33,                 /* programme  */
  YYSYMBOL_ligne = 34,                     /* ligne  */
  YYSYMBOL_liste_instructions = 35,        /* liste_instructions  */
  YYSYMBOL_liste_et_instructions = 36,     /* liste_et_instructions  */
  YYSYMBOL_instruction = 37,               /* instruction  */
  YYSYMBOL_bloc_instructions = 38,         /* bloc_instructions  */
  YYSYMBOL_affichage = 39,                 /* affichage  */
  YYSYMBOL_expression = 40,                /* expression  */
  YYSYMBOL_commentaire = 41                /* commentaire  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  33
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  81

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,     2,     2,     2,     2,    27,     2,     2,
      30,    31,    25,    23,     2,    24,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    92,    97,    98,   103,   104,   109,   110,
     118,   119,   125,   131,   137,   143,   154,   174,   183,   193,
     202,   214,   215,   222,   227,   250,   254,   257,   267,   274,
     281,   288,   296,   308
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
  "\"end of file\"", "error", "\"invalid token\"", "AFFICHER", "SI",
  "ALORS", "INT", "SINON", "DECLARER", "COMME", "OP", "DEMANDER", "POUR",
  "JUSQUA", "FAIRE", "TANTQUE", "ET", "IDENTIFIANT", "ENTIER", "CHAINE",
  "COMMENTAIRE", "FINLIGNE", "'='", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'{'", "'}'", "'('", "')'", "$accept", "programme", "ligne",
  "liste_instructions", "liste_et_instructions", "instruction",
  "bloc_instructions", "affichage", "expression", "commentaire", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-55)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -55,    42,   -55,   -11,    -8,    -5,     7,     4,    15,    16,
      13,   -55,   -55,    17,   -55,    18,   -55,   -55,   -55,    11,
      77,    27,    22,    32,    34,    33,    48,    45,    11,   -55,
     -55,    68,    11,    11,    11,    11,    11,    38,    11,    55,
     -55,   -55,    11,    60,    77,   -55,   -22,   -22,   -55,   -55,
     -55,    70,    77,    56,    58,    62,    76,    74,    11,    57,
      73,    11,    63,    81,   -55,    76,    77,    19,    57,   -55,
      84,   -55,   -55,   -55,    57,    85,    86,    69,    57,   -55,
     -55
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     3,     0,    10,     0,    26,    25,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    16,     0,     0,    15,    32,    27,    28,    29,    30,
      31,     0,    14,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,    20,     8,     0,    11,     0,     0,    18,
       0,    21,    19,     9,     0,     0,     0,     0,     7,    22,
       6
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   -55,    30,   -55,    -1,   -55,   -54,   -18,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    12,    75,    63,    76,    72,    14,    20,    15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      13,    31,    60,    34,    35,    36,    16,    17,    18,    21,
      44,    69,    22,    23,    46,    47,    48,    49,    50,    19,
      52,    25,     3,     4,    54,     5,    24,     6,    16,    17,
       7,     8,    26,    27,     9,    28,    10,    37,    29,    30,
      62,    19,     2,    66,    38,     3,     4,    70,     5,    39,
       6,    40,    41,     7,     8,    43,    51,     9,    64,    10,
       3,     4,    11,     5,    53,     6,    71,    73,     7,     8,
      42,    58,     9,    57,    10,    56,    59,    67,    55,     3,
      65,    32,    33,    34,    35,    36,    32,    33,    34,    35,
      36,    32,    33,    34,    35,    36,    61,    68,    79,    45,
      32,    33,    34,    35,    36,    74,    77,    78,    80
};

static const yytype_int8 yycheck[] =
{
       1,    19,    56,    25,    26,    27,    17,    18,    19,    17,
      28,    65,    17,     6,    32,    33,    34,    35,    36,    30,
      38,    17,     3,     4,    42,     6,    19,     8,    17,    18,
      11,    12,    17,    17,    15,    22,    17,    10,    21,    21,
      58,    30,     0,    61,    22,     3,     4,    28,     6,    17,
       8,    17,    19,    11,    12,    10,    18,    15,    59,    17,
       3,     4,    20,     6,     9,     8,    67,    68,    11,    12,
      22,    13,    15,    17,    17,     5,    14,    14,    18,     3,
       7,    23,    24,    25,    26,    27,    23,    24,    25,    26,
      27,    23,    24,    25,    26,    27,    22,    16,    29,    31,
      23,    24,    25,    26,    27,    21,    21,    21,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,     0,     3,     4,     6,     8,    11,    12,    15,
      17,    20,    34,    37,    39,    41,    17,    18,    19,    30,
      40,    17,    17,     6,    19,    17,    17,    17,    22,    21,
      21,    40,    23,    24,    25,    26,    27,    10,    22,    17,
      17,    19,    22,    10,    40,    31,    40,    40,    40,    40,
      40,    18,    40,     9,    40,    18,     5,    17,    13,    14,
      39,    22,    40,    36,    37,     7,    40,    14,    16,    39,
      28,    37,    38,    37,    21,    35,    37,    21,    21,    29,
      35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    35,    35,    36,    36,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    38,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    40,    40,    41
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     2,     1,     3,
       1,     7,     3,     3,     4,     3,     3,     6,     8,     8,
       6,     1,     5,     2,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     1
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
  case 4: /* ligne: instruction FINLIGNE  */
#line 97 "../src/traducteur.y"
                                    { fprintf(out, "%s\n", yyvsp[-1]); free(yyvsp[-1]); }
#line 1218 "traducteur.tab.c"
    break;

  case 5: /* ligne: commentaire FINLIGNE  */
#line 98 "../src/traducteur.y"
                                    { fprintf(out, "// %s\n", yyvsp[-1]); free(yyvsp[-1]); }
#line 1224 "traducteur.tab.c"
    break;

  case 8: /* liste_et_instructions: instruction  */
#line 109 "../src/traducteur.y"
                                         { yyval = yyvsp[0]; }
#line 1230 "traducteur.tab.c"
    break;

  case 9: /* liste_et_instructions: liste_et_instructions ET instruction  */
#line 110 "../src/traducteur.y"
                                         {
        yyval = concat_instruction(yyvsp[-2], yyvsp[0]);  // Concatène les instructions avec un point-virgule et saut de ligne
        free(yyvsp[-2]); free(yyvsp[0]);               // Libère la mémoire temporaire
    }
#line 1239 "traducteur.tab.c"
    break;

  case 11: /* instruction: DECLARER INT IDENTIFIANT COMME IDENTIFIANT '=' expression  */
#line 119 "../src/traducteur.y"
                                                                    {
		ajouter_symbole(yyvsp[-4], "int");  // Ajouter la variable à la table des symboles
		yyval = malloc(strlen(yyvsp[-4]) + strlen(yyvsp[0]) + 40);
		sprintf(yyval, "int %s = %s;", yyvsp[-4], yyvsp[0]);  // Générer le code C correspondant à la déclaration avec initialisation
		free(yyvsp[-4]); free(yyvsp[0]);
	}
#line 1250 "traducteur.tab.c"
    break;

  case 12: /* instruction: DECLARER INT IDENTIFIANT  */
#line 125 "../src/traducteur.y"
                                   {
		ajouter_symbole(yyvsp[0], "int");
		yyval = malloc(strlen(yyvsp[0]) + 20);
		sprintf(yyval, "int %s;", yyvsp[0]);  // Déclaration simple int sans initialisation
		free(yyvsp[0]);
	}
#line 1261 "traducteur.tab.c"
    break;

  case 13: /* instruction: DECLARER CHAINE IDENTIFIANT  */
#line 131 "../src/traducteur.y"
                                      {
		ajouter_symbole(yyvsp[0], "chaine");
		yyval = malloc(strlen(yyvsp[0]) + 40);
		sprintf(yyval, "char %s[256];", yyvsp[0]);  // Déclaration tableau de char (chaîne) de taille 256
		free(yyvsp[0]);
	}
#line 1272 "traducteur.tab.c"
    break;

  case 14: /* instruction: INT IDENTIFIANT '=' expression  */
#line 137 "../src/traducteur.y"
                                         {
		ajouter_symbole(yyvsp[-2], "int");
		yyval = malloc(strlen(yyvsp[-2]) + strlen(yyvsp[0]) + 20);
		sprintf(yyval, "int %s = %s;", yyvsp[-2], yyvsp[0]);  // Déclaration et initialisation int
		free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1283 "traducteur.tab.c"
    break;

  case 15: /* instruction: IDENTIFIANT '=' expression  */
#line 143 "../src/traducteur.y"
                                     {
		// Affectation à une variable déjà déclarée
		if (type_de_variable(yyvsp[-2]) == NULL) {
			fprintf(stderr, "Erreur: variable '%s' non déclarée\n", yyvsp[-2]);
			yyval = strdup("// erreur variable non declaree");
		} else {
			yyval = malloc(strlen(yyvsp[-2]) + strlen(yyvsp[0]) + 10);
			sprintf(yyval, "%s = %s;", yyvsp[-2], yyvsp[0]);  // Génère une affectation C classique
		}
		free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1299 "traducteur.tab.c"
    break;

  case 16: /* instruction: DEMANDER IDENTIFIANT CHAINE  */
#line 154 "../src/traducteur.y"
                                      {
		// Lecture utilisateur, dépend du type de la variable
		const char *type = type_de_variable(yyvsp[-1]);
		if (type == NULL) {
			fprintf(stderr, "Erreur: variable '%s' non déclarée\n", yyvsp[-1]);
			yyval = strdup("// erreur variable non declaree");
		}
		else if (strcmp(type, "int") == 0) {
			yyval = malloc(strlen(yyvsp[-1]) + strlen(yyvsp[0]) + 80);
			sprintf(yyval, "printf(\"%s\\n\"); scanf(\"%%d\", &%s);", yyvsp[0], yyvsp[-1]);
		}
		else if (strcmp(type, "chaine") == 0) {
			yyval = malloc(strlen(yyvsp[-1]) + strlen(yyvsp[0]) + 80);
			sprintf(yyval, "printf(\"%s\\n\"); scanf(\"%%255s\", %s);", yyvsp[0], yyvsp[-1]);
		}
		else {
			yyval = strdup("// type inconnu pour demander");
		}
		free(yyvsp[-1]); free(yyvsp[0]);
	}
#line 1324 "traducteur.tab.c"
    break;

  case 17: /* instruction: SI IDENTIFIANT OP ENTIER ALORS affichage  */
#line 174 "../src/traducteur.y"
                                                   {
		// Condition if simple (ex : si x > 5 alors afficher ...)
		char *corps_si = indent(yyvsp[0]);
		int taille = snprintf(NULL, 0, "if (%s %s %s) {\n%s}", yyvsp[-4], yyvsp[-3], yyvsp[-2], corps_si);
		yyval = malloc(taille + 1);
		sprintf(yyval, "if (%s %s %s) {\n%s}", yyvsp[-4], yyvsp[-3], yyvsp[-2], corps_si);
		free(corps_si);
		free(yyvsp[-4]); free(yyvsp[-3]); free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1338 "traducteur.tab.c"
    break;

  case 18: /* instruction: SI IDENTIFIANT OP ENTIER ALORS affichage SINON affichage  */
#line 183 "../src/traducteur.y"
                                                                   {
		// Condition if-else (ex : si x > 5 alors ... sinon ...)
		char *corps_si = indent(yyvsp[-2]);
		char *corps_sinon = indent(yyvsp[0]);
		int taille = snprintf(NULL, 0, "if (%s %s %s) {\n%s} else {\n%s}", yyvsp[-6], yyvsp[-5], yyvsp[-4], corps_si, corps_sinon);
		yyval = malloc(taille + 1);
		sprintf(yyval, "if (%s %s %s) {\n%s} else {\n%s}", yyvsp[-6], yyvsp[-5], yyvsp[-4], corps_si, corps_sinon);
		free(corps_si); free(corps_sinon);
		free(yyvsp[-6]); free(yyvsp[-5]); free(yyvsp[-4]); free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1353 "traducteur.tab.c"
    break;

  case 19: /* instruction: POUR IDENTIFIANT '=' expression JUSQUA expression FAIRE bloc_instructions  */
#line 193 "../src/traducteur.y"
                                                                                    {
		// Boucle for (ex : pour i = 0 jusqu'à 10 faire { ... })
		char *corps_indente = indent(yyvsp[0]);
		int taille = snprintf(NULL, 0, "for (int %s = %s; %s <= %s; %s++) {\n%s}", yyvsp[-6], yyvsp[-4], yyvsp[-6], yyvsp[-2], yyvsp[-6], corps_indente);
		yyval = malloc(taille + 1);
		sprintf(yyval, "for (int %s = %s; %s <= %s; %s++) {\n%s}", yyvsp[-6], yyvsp[-4], yyvsp[-6], yyvsp[-2], yyvsp[-6], corps_indente);
		free(corps_indente);
		free(yyvsp[-6]); free(yyvsp[-4]); free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1367 "traducteur.tab.c"
    break;

  case 20: /* instruction: TANTQUE IDENTIFIANT OP ENTIER FAIRE liste_et_instructions  */
#line 202 "../src/traducteur.y"
                                                                    {
	    // Boucle while (tant que x faire ...)
	    char* corps = indent(yyvsp[0]);
		sprintf(yyval, "while (%s %s %s) {\n%s}", yyvsp[-4], yyvsp[-3], yyvsp[-2], corps);
		free(corps);

	}
#line 1379 "traducteur.tab.c"
    break;

  case 22: /* bloc_instructions: '{' FINLIGNE liste_instructions FINLIGNE '}'  */
#line 215 "../src/traducteur.y"
                                                       {
		yyval = yyvsp[-2];  // On prend la liste d’instructions à l’intérieur du bloc
	}
#line 1387 "traducteur.tab.c"
    break;

  case 23: /* affichage: AFFICHER CHAINE  */
#line 222 "../src/traducteur.y"
                        {
		yyval = malloc(strlen(yyvsp[0]) + 20);
		sprintf(yyval, "printf(\"%s\\n\");", yyvsp[0]); // Affiche une chaîne littérale
		free(yyvsp[0]);
	}
#line 1397 "traducteur.tab.c"
    break;

  case 24: /* affichage: AFFICHER expression  */
#line 227 "../src/traducteur.y"
                              {
		// Affichage d’une expression, selon son type (int ou chaine)
		const char *type = type_de_variable(yyvsp[0]);
		if (type != NULL) {
			if (strcmp(type, "int") == 0) {
				yyval = malloc(strlen(yyvsp[0]) + 40);
				sprintf(yyval, "printf(\"%%d\\n\", %s);", yyvsp[0]);
			} else if (strcmp(type, "chaine") == 0) {
				yyval = malloc(strlen(yyvsp[0]) + 40);
				sprintf(yyval, "printf(\"%%s\\n\", %s);", yyvsp[0]);
			} else {
				yyval = strdup("// type inconnu pour afficher");
			}
		} else {
			// Si type inconnu, on suppose un int par défaut
			yyval = malloc(strlen(yyvsp[0]) + 40);
			sprintf(yyval, "printf(\"%%d\\n\", %s);", yyvsp[0]);
		}
		free(yyvsp[0]);
	}
#line 1422 "traducteur.tab.c"
    break;

  case 25: /* expression: ENTIER  */
#line 250 "../src/traducteur.y"
                             { yyval = strdup(yyvsp[0]); free(yyvsp[0]); }
#line 1428 "traducteur.tab.c"
    break;

  case 26: /* expression: IDENTIFIANT  */
#line 254 "../src/traducteur.y"
                             { yyval = strdup(yyvsp[0]); free(yyvsp[0]); }
#line 1434 "traducteur.tab.c"
    break;

  case 27: /* expression: expression '+' expression  */
#line 257 "../src/traducteur.y"
                                    {
		yyval = malloc(strlen(yyvsp[-2]) + strlen(yyvsp[0]) + 6);
		// On alloue une chaîne assez grande pour contenir la concaténation : 
		// 2 parenthèses + opérateur + espaces + chaîne 1 + chaîne 3 + le '\0'.
		sprintf(yyval, "(%s + %s)", yyvsp[-2], yyvsp[0]);
		// On génère une chaîne correspondant à une addition en C, avec parenthèses pour la priorité.
		free(yyvsp[-2]); free(yyvsp[0]);
		// On libère la mémoire des sous-expressions temporaires.
	}
#line 1448 "traducteur.tab.c"
    break;

  case 28: /* expression: expression '-' expression  */
#line 267 "../src/traducteur.y"
                                    {
		yyval = malloc(strlen(yyvsp[-2]) + strlen(yyvsp[0]) + 6);
		sprintf(yyval, "(%s - %s)", yyvsp[-2], yyvsp[0]);
		free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1458 "traducteur.tab.c"
    break;

  case 29: /* expression: expression '*' expression  */
#line 274 "../src/traducteur.y"
                                    {
		yyval = malloc(strlen(yyvsp[-2]) + strlen(yyvsp[0]) + 6);
		sprintf(yyval, "(%s * %s)", yyvsp[-2], yyvsp[0]);
		free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1468 "traducteur.tab.c"
    break;

  case 30: /* expression: expression '/' expression  */
#line 281 "../src/traducteur.y"
                                    {
		yyval = malloc(strlen(yyvsp[-2]) + strlen(yyvsp[0]) + 6);
		sprintf(yyval, "(%s / %s)", yyvsp[-2], yyvsp[0]);
		free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1478 "traducteur.tab.c"
    break;

  case 31: /* expression: expression '%' expression  */
#line 288 "../src/traducteur.y"
                                    {
		yyval = malloc(strlen(yyvsp[-2]) + strlen(yyvsp[0]) + 7); 
		// Ici 7 au lieu de 6 car il y a un caractère supplémentaire pour '%%' (le % en sprintf s'écrit '%%')
		sprintf(yyval, "(%s %% %s)", yyvsp[-2], yyvsp[0]);
		// Modulo en C, on doit échapper le % par %% dans sprintf.
		free(yyvsp[-2]); free(yyvsp[0]);
	}
#line 1490 "traducteur.tab.c"
    break;

  case 32: /* expression: '(' expression ')'  */
#line 296 "../src/traducteur.y"
                             {
		yyval = malloc(strlen(yyvsp[-1]) + 3);
		// On alloue une chaîne pour les parenthèses + l'expression + '\0'
		sprintf(yyval, "(%s)", yyvsp[-1]);
		// On entoure simplement l'expression par des parenthèses.
		free(yyvsp[-1]);
	}
#line 1502 "traducteur.tab.c"
    break;

  case 33: /* commentaire: COMMENTAIRE  */
#line 308 "../src/traducteur.y"
                    { yyval = yyvsp[0]; }
#line 1508 "traducteur.tab.c"
    break;


#line 1512 "traducteur.tab.c"

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

#line 313 "../src/traducteur.y"


// Fonction principale (main) du programme
int main(void) {
	yydebug = 1;  // Active le mode debug de Bison, utile pour voir le déroulement du parseur
	out = fopen("output.c", "w");  // Ouvre le fichier "output.c" en écriture (création ou écrasement)
	if (!out) {
		perror("Erreur ouverture output.c");  // Affiche une erreur si le fichier ne peut être ouvert
		exit(1);  // Quitte le programme avec code erreur
	}
	fprintf(out, "#include <stdio.h>\nint main() {\n");
	// Écrit le début d'un programme C standard dans le fichier de sortie

	yyparse();  // Lance le parseur Bison (analyse syntaxique)

	fprintf(out, "return 0;\n}\n");  // Écrit la fin de la fonction main() dans le fichier

	fclose(out);  // Ferme le fichier de sortie
	return 0;     // Fin normale du programme
}

// Fonction d'erreur appelée par Bison en cas d'erreur de syntaxe
int yyerror(char *s) {
	fprintf(stderr, "Erreur: %s\n", s);  // Affiche le message d'erreur sur la sortie d'erreur standard
	return 0;
}


