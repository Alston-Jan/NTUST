/* A Bison parser, made by GNU Bison 3.8.2.  */

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

#ifndef YY_YY_JAVAA_TAB_H_INCLUDED
# define YY_YY_JAVAA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LABEL = 258,                   /* LABEL  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    INTCONSTANT = 260,             /* INTCONSTANT  */
    LONGCONSTANT = 261,            /* LONGCONSTANT  */
    FLOATCONSTANT = 262,           /* FLOATCONSTANT  */
    DOUBLECONSTANT = 263,          /* DOUBLECONSTANT  */
    CHARCONSTANT = 264,            /* CHARCONSTANT  */
    STRING_LITERAL = 265,          /* STRING_LITERAL  */
    CLASS = 266,                   /* CLASS  */
    EXTENDS = 267,                 /* EXTENDS  */
    ACCESS = 268,                  /* ACCESS  */
    IMPLEMENTS = 269,              /* IMPLEMENTS  */
    FIELD = 270,                   /* FIELD  */
    METHOD = 271,                  /* METHOD  */
    MAX_STACK = 272,               /* MAX_STACK  */
    MAX_LOCALS = 273,              /* MAX_LOCALS  */
    CODE = 274,                    /* CODE  */
    PUBLIC = 275,                  /* PUBLIC  */
    PRIVATE = 276,                 /* PRIVATE  */
    PROTECTED = 277,               /* PROTECTED  */
    ABSTRACT = 278,                /* ABSTRACT  */
    FINAL = 279,                   /* FINAL  */
    INTERFACE = 280,               /* INTERFACE  */
    STATIC = 281,                  /* STATIC  */
    NATIVE = 282,                  /* NATIVE  */
    SYNCHRONIZED = 283,            /* SYNCHRONIZED  */
    TRANSIENT = 284,               /* TRANSIENT  */
    VOLATILE = 285,                /* VOLATILE  */
    BYTE = 286,                    /* BYTE  */
    CHAR = 287,                    /* CHAR  */
    DOUBLE = 288,                  /* DOUBLE  */
    FLOAT = 289,                   /* FLOAT  */
    INT = 290,                     /* INT  */
    LONG = 291,                    /* LONG  */
    SHORT = 292,                   /* SHORT  */
    BOOLEAN = 293,                 /* BOOLEAN  */
    VOID = 294,                    /* VOID  */
    DEFAULT = 295,                 /* DEFAULT  */
    TO = 296,                      /* TO  */
    EXCEPTIONS = 297,              /* EXCEPTIONS  */
    SOURCEFILE = 298,              /* SOURCEFILE  */
    THROWS = 299,                  /* THROWS  */
    LINENUMBERTABLE = 300,         /* LINENUMBERTABLE  */
    LOCALVARIABLETABLE = 301,      /* LOCALVARIABLETABLE  */
    ACC_PUBLIC = 302,              /* ACC_PUBLIC  */
    ACC_PRIVATE = 303,             /* ACC_PRIVATE  */
    ACC_PROTECTED = 304,           /* ACC_PROTECTED  */
    ACC_STATIC = 305,              /* ACC_STATIC  */
    ACC_FINAL = 306,               /* ACC_FINAL  */
    ACC_SYNCHRONIZED = 307,        /* ACC_SYNCHRONIZED  */
    ACC_VOLATILE = 308,            /* ACC_VOLATILE  */
    ACC_TRANSIENT = 309,           /* ACC_TRANSIENT  */
    ACC_NATIVE = 310,              /* ACC_NATIVE  */
    ACC_INTERFACE = 311,           /* ACC_INTERFACE  */
    ACC_ABSTRACT = 312,            /* ACC_ABSTRACT  */
    AALOAD = 313,                  /* AALOAD  */
    AASTORE = 314,                 /* AASTORE  */
    ACONST_NULL = 315,             /* ACONST_NULL  */
    ALOAD_0 = 316,                 /* ALOAD_0  */
    ALOAD_1 = 317,                 /* ALOAD_1  */
    ALOAD_2 = 318,                 /* ALOAD_2  */
    ALOAD_3 = 319,                 /* ALOAD_3  */
    ANEWARRAY = 320,               /* ANEWARRAY  */
    ARETURN = 321,                 /* ARETURN  */
    ARRAYLENGTH = 322,             /* ARRAYLENGTH  */
    ASTORE_0 = 323,                /* ASTORE_0  */
    ASTORE_1 = 324,                /* ASTORE_1  */
    ASTORE_2 = 325,                /* ASTORE_2  */
    ASTORE_3 = 326,                /* ASTORE_3  */
    ATHROW = 327,                  /* ATHROW  */
    BALOAD = 328,                  /* BALOAD  */
    BASTORE = 329,                 /* BASTORE  */
    BIPUSH = 330,                  /* BIPUSH  */
    CALOAD = 331,                  /* CALOAD  */
    CASTORE = 332,                 /* CASTORE  */
    CHECKCAST = 333,               /* CHECKCAST  */
    D2F = 334,                     /* D2F  */
    D2I = 335,                     /* D2I  */
    D2L = 336,                     /* D2L  */
    DADD = 337,                    /* DADD  */
    DALOAD = 338,                  /* DALOAD  */
    DASTORE = 339,                 /* DASTORE  */
    DCMPG = 340,                   /* DCMPG  */
    DCMPL = 341,                   /* DCMPL  */
    DCONST_0 = 342,                /* DCONST_0  */
    DCONST_1 = 343,                /* DCONST_1  */
    DDIV = 344,                    /* DDIV  */
    DLOAD_0 = 345,                 /* DLOAD_0  */
    DLOAD_1 = 346,                 /* DLOAD_1  */
    DLOAD_2 = 347,                 /* DLOAD_2  */
    DLOAD_3 = 348,                 /* DLOAD_3  */
    DMUL = 349,                    /* DMUL  */
    DNEG = 350,                    /* DNEG  */
    DREM = 351,                    /* DREM  */
    DRETURN = 352,                 /* DRETURN  */
    DSTORE_0 = 353,                /* DSTORE_0  */
    DSTORE_1 = 354,                /* DSTORE_1  */
    DSTORE_2 = 355,                /* DSTORE_2  */
    DSTORE_3 = 356,                /* DSTORE_3  */
    DSUB = 357,                    /* DSUB  */
    DUP = 358,                     /* DUP  */
    DUP_X1 = 359,                  /* DUP_X1  */
    DUP_X2 = 360,                  /* DUP_X2  */
    DUP2 = 361,                    /* DUP2  */
    DUP2_X1 = 362,                 /* DUP2_X1  */
    DUP2_X2 = 363,                 /* DUP2_X2  */
    F2D = 364,                     /* F2D  */
    F2I = 365,                     /* F2I  */
    F2L = 366,                     /* F2L  */
    FADD = 367,                    /* FADD  */
    FALOAD = 368,                  /* FALOAD  */
    FASTORE = 369,                 /* FASTORE  */
    FCMPG = 370,                   /* FCMPG  */
    FCMPL = 371,                   /* FCMPL  */
    FCONST_0 = 372,                /* FCONST_0  */
    FCONST_1 = 373,                /* FCONST_1  */
    FCONST_2 = 374,                /* FCONST_2  */
    FDIV = 375,                    /* FDIV  */
    FLOAD_0 = 376,                 /* FLOAD_0  */
    FLOAD_1 = 377,                 /* FLOAD_1  */
    FLOAD_2 = 378,                 /* FLOAD_2  */
    FLOAD_3 = 379,                 /* FLOAD_3  */
    FMUL = 380,                    /* FMUL  */
    FNEG = 381,                    /* FNEG  */
    FREM = 382,                    /* FREM  */
    FRETURN = 383,                 /* FRETURN  */
    FSTORE_0 = 384,                /* FSTORE_0  */
    FSTORE_1 = 385,                /* FSTORE_1  */
    FSTORE_2 = 386,                /* FSTORE_2  */
    FSTORE_3 = 387,                /* FSTORE_3  */
    FSUB = 388,                    /* FSUB  */
    GETFIELD = 389,                /* GETFIELD  */
    GETSTATIC = 390,               /* GETSTATIC  */
    GOTO = 391,                    /* GOTO  */
    GOTO_W = 392,                  /* GOTO_W  */
    I2B = 393,                     /* I2B  */
    I2C = 394,                     /* I2C  */
    I2D = 395,                     /* I2D  */
    I2F = 396,                     /* I2F  */
    I2L = 397,                     /* I2L  */
    I2S = 398,                     /* I2S  */
    IADD = 399,                    /* IADD  */
    IALOAD = 400,                  /* IALOAD  */
    IAND = 401,                    /* IAND  */
    IASTORE = 402,                 /* IASTORE  */
    ICONST_0 = 403,                /* ICONST_0  */
    ICONST_1 = 404,                /* ICONST_1  */
    ICONST_2 = 405,                /* ICONST_2  */
    ICONST_3 = 406,                /* ICONST_3  */
    ICONST_4 = 407,                /* ICONST_4  */
    ICONST_5 = 408,                /* ICONST_5  */
    ICONST_M1 = 409,               /* ICONST_M1  */
    IDIV = 410,                    /* IDIV  */
    IF_ACMPEQ = 411,               /* IF_ACMPEQ  */
    IF_ACMPNE = 412,               /* IF_ACMPNE  */
    IF_ICMPEQ = 413,               /* IF_ICMPEQ  */
    IF_ICMPNE = 414,               /* IF_ICMPNE  */
    IF_ICMPLT = 415,               /* IF_ICMPLT  */
    IF_ICMPGE = 416,               /* IF_ICMPGE  */
    IF_ICMPGT = 417,               /* IF_ICMPGT  */
    IF_ICMPLE = 418,               /* IF_ICMPLE  */
    IFEQ = 419,                    /* IFEQ  */
    IFNE = 420,                    /* IFNE  */
    IFLT = 421,                    /* IFLT  */
    IFGE = 422,                    /* IFGE  */
    IFGT = 423,                    /* IFGT  */
    IFLE = 424,                    /* IFLE  */
    IFNONNULL = 425,               /* IFNONNULL  */
    IFNULL = 426,                  /* IFNULL  */
    ILOAD_0 = 427,                 /* ILOAD_0  */
    ILOAD_1 = 428,                 /* ILOAD_1  */
    ILOAD_2 = 429,                 /* ILOAD_2  */
    ILOAD_3 = 430,                 /* ILOAD_3  */
    IMUL = 431,                    /* IMUL  */
    INEG = 432,                    /* INEG  */
    IOR = 433,                     /* IOR  */
    IREM = 434,                    /* IREM  */
    IRETURN = 435,                 /* IRETURN  */
    ISHL = 436,                    /* ISHL  */
    ISHR = 437,                    /* ISHR  */
    ISTORE_0 = 438,                /* ISTORE_0  */
    ISTORE_1 = 439,                /* ISTORE_1  */
    ISTORE_2 = 440,                /* ISTORE_2  */
    ISTORE_3 = 441,                /* ISTORE_3  */
    ISUB = 442,                    /* ISUB  */
    IUSHR = 443,                   /* IUSHR  */
    IXOR = 444,                    /* IXOR  */
    JSR = 445,                     /* JSR  */
    JSR_W = 446,                   /* JSR_W  */
    L2D = 447,                     /* L2D  */
    L2F = 448,                     /* L2F  */
    L2I = 449,                     /* L2I  */
    LADD = 450,                    /* LADD  */
    LALOAD = 451,                  /* LALOAD  */
    LAND = 452,                    /* LAND  */
    LASTORE = 453,                 /* LASTORE  */
    LCMP = 454,                    /* LCMP  */
    LCONST_0 = 455,                /* LCONST_0  */
    LCONST_1 = 456,                /* LCONST_1  */
    LDIV = 457,                    /* LDIV  */
    LLOAD_0 = 458,                 /* LLOAD_0  */
    LLOAD_1 = 459,                 /* LLOAD_1  */
    LLOAD_2 = 460,                 /* LLOAD_2  */
    LLOAD_3 = 461,                 /* LLOAD_3  */
    LMUL = 462,                    /* LMUL  */
    LNEG = 463,                    /* LNEG  */
    LOR = 464,                     /* LOR  */
    LREM = 465,                    /* LREM  */
    LRETURN = 466,                 /* LRETURN  */
    LSHL = 467,                    /* LSHL  */
    LSHR = 468,                    /* LSHR  */
    LSTORE_0 = 469,                /* LSTORE_0  */
    LSTORE_1 = 470,                /* LSTORE_1  */
    LSTORE_2 = 471,                /* LSTORE_2  */
    LSTORE_3 = 472,                /* LSTORE_3  */
    LSUB = 473,                    /* LSUB  */
    LUSHR = 474,                   /* LUSHR  */
    LXOR = 475,                    /* LXOR  */
    MONITORENTER = 476,            /* MONITORENTER  */
    MONITOREXIT = 477,             /* MONITOREXIT  */
    NOP = 478,                     /* NOP  */
    POP = 479,                     /* POP  */
    POP2 = 480,                    /* POP2  */
    RETURN = 481,                  /* RETURN  */
    SALOAD = 482,                  /* SALOAD  */
    SASTORE = 483,                 /* SASTORE  */
    SWAP = 484,                    /* SWAP  */
    IINC = 485,                    /* IINC  */
    INSTANCEOF = 486,              /* INSTANCEOF  */
    INVOKEINTERFACE = 487,         /* INVOKEINTERFACE  */
    INVOKENONVIRTUAL = 488,        /* INVOKENONVIRTUAL  */
    INVOKESTATIC = 489,            /* INVOKESTATIC  */
    INVOKEVIRTUAL = 490,           /* INVOKEVIRTUAL  */
    LDC = 491,                     /* LDC  */
    LDC_W = 492,                   /* LDC_W  */
    LDC2_W = 493,                  /* LDC2_W  */
    MULTIANEWARRAY = 494,          /* MULTIANEWARRAY  */
    NEW = 495,                     /* NEW  */
    NEWARRAY = 496,                /* NEWARRAY  */
    PUTFIELD = 497,                /* PUTFIELD  */
    PUTSTATIC = 498,               /* PUTSTATIC  */
    SIPUSH = 499,                  /* SIPUSH  */
    ILOAD = 500,                   /* ILOAD  */
    FLOAD = 501,                   /* FLOAD  */
    ALOAD = 502,                   /* ALOAD  */
    LLOAD = 503,                   /* LLOAD  */
    DLOAD = 504,                   /* DLOAD  */
    ISTORE = 505,                  /* ISTORE  */
    FSTORE = 506,                  /* FSTORE  */
    ASTORE = 507,                  /* ASTORE  */
    LSTORE = 508,                  /* LSTORE  */
    DSTORE = 509,                  /* DSTORE  */
    RET = 510,                     /* RET  */
    WIDE = 511,                    /* WIDE  */
    LOAD = 512,                    /* LOAD  */
    STORE = 513,                   /* STORE  */
    LOOKUPSWITCH = 514,            /* LOOKUPSWITCH  */
    TABLESWITCH = 515              /* TABLESWITCH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 289 "javaa.y"

   Terminal        rk;
   Terminal        NT;
   Terminal        RK;
   Terminal        Rk;

   float           floatval;
   double          doubleval;
   char            charval;
   int             intval;
   long            longval;
   char           *string;

   BaseType        basetype;
   StorageClass    storageclass;
   TypeQualifier   typequalifier;
   ArgType	   argtype;
  
   lookupentry *   lookuplistptr;
   tableentry *    tablelistptr;

   struct {
	char* classname;
	char* fieldmethodname;
   }		classfieldmethodstruct;

   struct _declinfo {
      int   function;
      int   ptrcount;
      int   dimsize[7];
      int   numdims;
      char *name;
   }               declinfo;
   
   struct {
      TreeNode *formals;
      struct _declinfo D;
   }               funcstuff;

   struct {
      Type          T;
      StorageClass  C;
      TypeQualifier Q;
   } declspecs;

   struct {
      Type          T;
      StorageClass  C;
      TypeQualifier Q;
      TreeNode     *node;
   } declspecsnode;

   struct {
      Type          T;
      StorageClass  C;
      TypeQualifier Q;
      Symbol       *headsym;
      Symbol       *prevsym;
   } structdeclspecs;

   struct {
      Symbol   *headsym;
      Symbol   *prevsym;
   } headprevsym;

   struct {
      int       spec;
      int       val;
      char     *id;
   } idspecval;

   struct {
      Symbol   *sym;
      int       val;
   } symval;

   Type            typetype;

   Symbol         *sym;

   struct {
      TreeNode *decl;
      TreeNode *func;
   } declfunc;

   struct {
      TreeNode *decl;
      TreeNode *func;
      TreeNode *exprs;
      TreeNode *last;
   } declfuncexprs;

   struct {
      TreeNode *exprs;
      TreeNode *last;
   } exprslast;

   TreeNode       *node;

#line 424 "javaa.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_JAVAA_TAB_H_INCLUDED  */
