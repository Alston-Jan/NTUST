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
#line 260 "javaa.y"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "utils.h"
#include "build.h"
#include "protos.h"
#include "listing.h"

#line 82 "javaa.tab.c"

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

#include "javaa.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LABEL = 3,                      /* LABEL  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_INTCONSTANT = 5,                /* INTCONSTANT  */
  YYSYMBOL_LONGCONSTANT = 6,               /* LONGCONSTANT  */
  YYSYMBOL_FLOATCONSTANT = 7,              /* FLOATCONSTANT  */
  YYSYMBOL_DOUBLECONSTANT = 8,             /* DOUBLECONSTANT  */
  YYSYMBOL_CHARCONSTANT = 9,               /* CHARCONSTANT  */
  YYSYMBOL_STRING_LITERAL = 10,            /* STRING_LITERAL  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_EXTENDS = 12,                   /* EXTENDS  */
  YYSYMBOL_ACCESS = 13,                    /* ACCESS  */
  YYSYMBOL_IMPLEMENTS = 14,                /* IMPLEMENTS  */
  YYSYMBOL_FIELD = 15,                     /* FIELD  */
  YYSYMBOL_METHOD = 16,                    /* METHOD  */
  YYSYMBOL_MAX_STACK = 17,                 /* MAX_STACK  */
  YYSYMBOL_MAX_LOCALS = 18,                /* MAX_LOCALS  */
  YYSYMBOL_CODE = 19,                      /* CODE  */
  YYSYMBOL_PUBLIC = 20,                    /* PUBLIC  */
  YYSYMBOL_PRIVATE = 21,                   /* PRIVATE  */
  YYSYMBOL_PROTECTED = 22,                 /* PROTECTED  */
  YYSYMBOL_ABSTRACT = 23,                  /* ABSTRACT  */
  YYSYMBOL_FINAL = 24,                     /* FINAL  */
  YYSYMBOL_INTERFACE = 25,                 /* INTERFACE  */
  YYSYMBOL_STATIC = 26,                    /* STATIC  */
  YYSYMBOL_NATIVE = 27,                    /* NATIVE  */
  YYSYMBOL_SYNCHRONIZED = 28,              /* SYNCHRONIZED  */
  YYSYMBOL_TRANSIENT = 29,                 /* TRANSIENT  */
  YYSYMBOL_VOLATILE = 30,                  /* VOLATILE  */
  YYSYMBOL_BYTE = 31,                      /* BYTE  */
  YYSYMBOL_CHAR = 32,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 33,                    /* DOUBLE  */
  YYSYMBOL_FLOAT = 34,                     /* FLOAT  */
  YYSYMBOL_INT = 35,                       /* INT  */
  YYSYMBOL_LONG = 36,                      /* LONG  */
  YYSYMBOL_SHORT = 37,                     /* SHORT  */
  YYSYMBOL_BOOLEAN = 38,                   /* BOOLEAN  */
  YYSYMBOL_VOID = 39,                      /* VOID  */
  YYSYMBOL_DEFAULT = 40,                   /* DEFAULT  */
  YYSYMBOL_TO = 41,                        /* TO  */
  YYSYMBOL_EXCEPTIONS = 42,                /* EXCEPTIONS  */
  YYSYMBOL_SOURCEFILE = 43,                /* SOURCEFILE  */
  YYSYMBOL_THROWS = 44,                    /* THROWS  */
  YYSYMBOL_LINENUMBERTABLE = 45,           /* LINENUMBERTABLE  */
  YYSYMBOL_LOCALVARIABLETABLE = 46,        /* LOCALVARIABLETABLE  */
  YYSYMBOL_ACC_PUBLIC = 47,                /* ACC_PUBLIC  */
  YYSYMBOL_ACC_PRIVATE = 48,               /* ACC_PRIVATE  */
  YYSYMBOL_ACC_PROTECTED = 49,             /* ACC_PROTECTED  */
  YYSYMBOL_ACC_STATIC = 50,                /* ACC_STATIC  */
  YYSYMBOL_ACC_FINAL = 51,                 /* ACC_FINAL  */
  YYSYMBOL_ACC_SYNCHRONIZED = 52,          /* ACC_SYNCHRONIZED  */
  YYSYMBOL_ACC_VOLATILE = 53,              /* ACC_VOLATILE  */
  YYSYMBOL_ACC_TRANSIENT = 54,             /* ACC_TRANSIENT  */
  YYSYMBOL_ACC_NATIVE = 55,                /* ACC_NATIVE  */
  YYSYMBOL_ACC_INTERFACE = 56,             /* ACC_INTERFACE  */
  YYSYMBOL_ACC_ABSTRACT = 57,              /* ACC_ABSTRACT  */
  YYSYMBOL_AALOAD = 58,                    /* AALOAD  */
  YYSYMBOL_AASTORE = 59,                   /* AASTORE  */
  YYSYMBOL_ACONST_NULL = 60,               /* ACONST_NULL  */
  YYSYMBOL_ALOAD_0 = 61,                   /* ALOAD_0  */
  YYSYMBOL_ALOAD_1 = 62,                   /* ALOAD_1  */
  YYSYMBOL_ALOAD_2 = 63,                   /* ALOAD_2  */
  YYSYMBOL_ALOAD_3 = 64,                   /* ALOAD_3  */
  YYSYMBOL_ANEWARRAY = 65,                 /* ANEWARRAY  */
  YYSYMBOL_ARETURN = 66,                   /* ARETURN  */
  YYSYMBOL_ARRAYLENGTH = 67,               /* ARRAYLENGTH  */
  YYSYMBOL_ASTORE_0 = 68,                  /* ASTORE_0  */
  YYSYMBOL_ASTORE_1 = 69,                  /* ASTORE_1  */
  YYSYMBOL_ASTORE_2 = 70,                  /* ASTORE_2  */
  YYSYMBOL_ASTORE_3 = 71,                  /* ASTORE_3  */
  YYSYMBOL_ATHROW = 72,                    /* ATHROW  */
  YYSYMBOL_BALOAD = 73,                    /* BALOAD  */
  YYSYMBOL_BASTORE = 74,                   /* BASTORE  */
  YYSYMBOL_BIPUSH = 75,                    /* BIPUSH  */
  YYSYMBOL_CALOAD = 76,                    /* CALOAD  */
  YYSYMBOL_CASTORE = 77,                   /* CASTORE  */
  YYSYMBOL_CHECKCAST = 78,                 /* CHECKCAST  */
  YYSYMBOL_D2F = 79,                       /* D2F  */
  YYSYMBOL_D2I = 80,                       /* D2I  */
  YYSYMBOL_D2L = 81,                       /* D2L  */
  YYSYMBOL_DADD = 82,                      /* DADD  */
  YYSYMBOL_DALOAD = 83,                    /* DALOAD  */
  YYSYMBOL_DASTORE = 84,                   /* DASTORE  */
  YYSYMBOL_DCMPG = 85,                     /* DCMPG  */
  YYSYMBOL_DCMPL = 86,                     /* DCMPL  */
  YYSYMBOL_DCONST_0 = 87,                  /* DCONST_0  */
  YYSYMBOL_DCONST_1 = 88,                  /* DCONST_1  */
  YYSYMBOL_DDIV = 89,                      /* DDIV  */
  YYSYMBOL_DLOAD_0 = 90,                   /* DLOAD_0  */
  YYSYMBOL_DLOAD_1 = 91,                   /* DLOAD_1  */
  YYSYMBOL_DLOAD_2 = 92,                   /* DLOAD_2  */
  YYSYMBOL_DLOAD_3 = 93,                   /* DLOAD_3  */
  YYSYMBOL_DMUL = 94,                      /* DMUL  */
  YYSYMBOL_DNEG = 95,                      /* DNEG  */
  YYSYMBOL_DREM = 96,                      /* DREM  */
  YYSYMBOL_DRETURN = 97,                   /* DRETURN  */
  YYSYMBOL_DSTORE_0 = 98,                  /* DSTORE_0  */
  YYSYMBOL_DSTORE_1 = 99,                  /* DSTORE_1  */
  YYSYMBOL_DSTORE_2 = 100,                 /* DSTORE_2  */
  YYSYMBOL_DSTORE_3 = 101,                 /* DSTORE_3  */
  YYSYMBOL_DSUB = 102,                     /* DSUB  */
  YYSYMBOL_DUP = 103,                      /* DUP  */
  YYSYMBOL_DUP_X1 = 104,                   /* DUP_X1  */
  YYSYMBOL_DUP_X2 = 105,                   /* DUP_X2  */
  YYSYMBOL_DUP2 = 106,                     /* DUP2  */
  YYSYMBOL_DUP2_X1 = 107,                  /* DUP2_X1  */
  YYSYMBOL_DUP2_X2 = 108,                  /* DUP2_X2  */
  YYSYMBOL_F2D = 109,                      /* F2D  */
  YYSYMBOL_F2I = 110,                      /* F2I  */
  YYSYMBOL_F2L = 111,                      /* F2L  */
  YYSYMBOL_FADD = 112,                     /* FADD  */
  YYSYMBOL_FALOAD = 113,                   /* FALOAD  */
  YYSYMBOL_FASTORE = 114,                  /* FASTORE  */
  YYSYMBOL_FCMPG = 115,                    /* FCMPG  */
  YYSYMBOL_FCMPL = 116,                    /* FCMPL  */
  YYSYMBOL_FCONST_0 = 117,                 /* FCONST_0  */
  YYSYMBOL_FCONST_1 = 118,                 /* FCONST_1  */
  YYSYMBOL_FCONST_2 = 119,                 /* FCONST_2  */
  YYSYMBOL_FDIV = 120,                     /* FDIV  */
  YYSYMBOL_FLOAD_0 = 121,                  /* FLOAD_0  */
  YYSYMBOL_FLOAD_1 = 122,                  /* FLOAD_1  */
  YYSYMBOL_FLOAD_2 = 123,                  /* FLOAD_2  */
  YYSYMBOL_FLOAD_3 = 124,                  /* FLOAD_3  */
  YYSYMBOL_FMUL = 125,                     /* FMUL  */
  YYSYMBOL_FNEG = 126,                     /* FNEG  */
  YYSYMBOL_FREM = 127,                     /* FREM  */
  YYSYMBOL_FRETURN = 128,                  /* FRETURN  */
  YYSYMBOL_FSTORE_0 = 129,                 /* FSTORE_0  */
  YYSYMBOL_FSTORE_1 = 130,                 /* FSTORE_1  */
  YYSYMBOL_FSTORE_2 = 131,                 /* FSTORE_2  */
  YYSYMBOL_FSTORE_3 = 132,                 /* FSTORE_3  */
  YYSYMBOL_FSUB = 133,                     /* FSUB  */
  YYSYMBOL_GETFIELD = 134,                 /* GETFIELD  */
  YYSYMBOL_GETSTATIC = 135,                /* GETSTATIC  */
  YYSYMBOL_GOTO = 136,                     /* GOTO  */
  YYSYMBOL_GOTO_W = 137,                   /* GOTO_W  */
  YYSYMBOL_I2B = 138,                      /* I2B  */
  YYSYMBOL_I2C = 139,                      /* I2C  */
  YYSYMBOL_I2D = 140,                      /* I2D  */
  YYSYMBOL_I2F = 141,                      /* I2F  */
  YYSYMBOL_I2L = 142,                      /* I2L  */
  YYSYMBOL_I2S = 143,                      /* I2S  */
  YYSYMBOL_IADD = 144,                     /* IADD  */
  YYSYMBOL_IALOAD = 145,                   /* IALOAD  */
  YYSYMBOL_IAND = 146,                     /* IAND  */
  YYSYMBOL_IASTORE = 147,                  /* IASTORE  */
  YYSYMBOL_ICONST_0 = 148,                 /* ICONST_0  */
  YYSYMBOL_ICONST_1 = 149,                 /* ICONST_1  */
  YYSYMBOL_ICONST_2 = 150,                 /* ICONST_2  */
  YYSYMBOL_ICONST_3 = 151,                 /* ICONST_3  */
  YYSYMBOL_ICONST_4 = 152,                 /* ICONST_4  */
  YYSYMBOL_ICONST_5 = 153,                 /* ICONST_5  */
  YYSYMBOL_ICONST_M1 = 154,                /* ICONST_M1  */
  YYSYMBOL_IDIV = 155,                     /* IDIV  */
  YYSYMBOL_IF_ACMPEQ = 156,                /* IF_ACMPEQ  */
  YYSYMBOL_IF_ACMPNE = 157,                /* IF_ACMPNE  */
  YYSYMBOL_IF_ICMPEQ = 158,                /* IF_ICMPEQ  */
  YYSYMBOL_IF_ICMPNE = 159,                /* IF_ICMPNE  */
  YYSYMBOL_IF_ICMPLT = 160,                /* IF_ICMPLT  */
  YYSYMBOL_IF_ICMPGE = 161,                /* IF_ICMPGE  */
  YYSYMBOL_IF_ICMPGT = 162,                /* IF_ICMPGT  */
  YYSYMBOL_IF_ICMPLE = 163,                /* IF_ICMPLE  */
  YYSYMBOL_IFEQ = 164,                     /* IFEQ  */
  YYSYMBOL_IFNE = 165,                     /* IFNE  */
  YYSYMBOL_IFLT = 166,                     /* IFLT  */
  YYSYMBOL_IFGE = 167,                     /* IFGE  */
  YYSYMBOL_IFGT = 168,                     /* IFGT  */
  YYSYMBOL_IFLE = 169,                     /* IFLE  */
  YYSYMBOL_IFNONNULL = 170,                /* IFNONNULL  */
  YYSYMBOL_IFNULL = 171,                   /* IFNULL  */
  YYSYMBOL_ILOAD_0 = 172,                  /* ILOAD_0  */
  YYSYMBOL_ILOAD_1 = 173,                  /* ILOAD_1  */
  YYSYMBOL_ILOAD_2 = 174,                  /* ILOAD_2  */
  YYSYMBOL_ILOAD_3 = 175,                  /* ILOAD_3  */
  YYSYMBOL_IMUL = 176,                     /* IMUL  */
  YYSYMBOL_INEG = 177,                     /* INEG  */
  YYSYMBOL_IOR = 178,                      /* IOR  */
  YYSYMBOL_IREM = 179,                     /* IREM  */
  YYSYMBOL_IRETURN = 180,                  /* IRETURN  */
  YYSYMBOL_ISHL = 181,                     /* ISHL  */
  YYSYMBOL_ISHR = 182,                     /* ISHR  */
  YYSYMBOL_ISTORE_0 = 183,                 /* ISTORE_0  */
  YYSYMBOL_ISTORE_1 = 184,                 /* ISTORE_1  */
  YYSYMBOL_ISTORE_2 = 185,                 /* ISTORE_2  */
  YYSYMBOL_ISTORE_3 = 186,                 /* ISTORE_3  */
  YYSYMBOL_ISUB = 187,                     /* ISUB  */
  YYSYMBOL_IUSHR = 188,                    /* IUSHR  */
  YYSYMBOL_IXOR = 189,                     /* IXOR  */
  YYSYMBOL_JSR = 190,                      /* JSR  */
  YYSYMBOL_JSR_W = 191,                    /* JSR_W  */
  YYSYMBOL_L2D = 192,                      /* L2D  */
  YYSYMBOL_L2F = 193,                      /* L2F  */
  YYSYMBOL_L2I = 194,                      /* L2I  */
  YYSYMBOL_LADD = 195,                     /* LADD  */
  YYSYMBOL_LALOAD = 196,                   /* LALOAD  */
  YYSYMBOL_LAND = 197,                     /* LAND  */
  YYSYMBOL_LASTORE = 198,                  /* LASTORE  */
  YYSYMBOL_LCMP = 199,                     /* LCMP  */
  YYSYMBOL_LCONST_0 = 200,                 /* LCONST_0  */
  YYSYMBOL_LCONST_1 = 201,                 /* LCONST_1  */
  YYSYMBOL_LDIV = 202,                     /* LDIV  */
  YYSYMBOL_LLOAD_0 = 203,                  /* LLOAD_0  */
  YYSYMBOL_LLOAD_1 = 204,                  /* LLOAD_1  */
  YYSYMBOL_LLOAD_2 = 205,                  /* LLOAD_2  */
  YYSYMBOL_LLOAD_3 = 206,                  /* LLOAD_3  */
  YYSYMBOL_LMUL = 207,                     /* LMUL  */
  YYSYMBOL_LNEG = 208,                     /* LNEG  */
  YYSYMBOL_LOR = 209,                      /* LOR  */
  YYSYMBOL_LREM = 210,                     /* LREM  */
  YYSYMBOL_LRETURN = 211,                  /* LRETURN  */
  YYSYMBOL_LSHL = 212,                     /* LSHL  */
  YYSYMBOL_LSHR = 213,                     /* LSHR  */
  YYSYMBOL_LSTORE_0 = 214,                 /* LSTORE_0  */
  YYSYMBOL_LSTORE_1 = 215,                 /* LSTORE_1  */
  YYSYMBOL_LSTORE_2 = 216,                 /* LSTORE_2  */
  YYSYMBOL_LSTORE_3 = 217,                 /* LSTORE_3  */
  YYSYMBOL_LSUB = 218,                     /* LSUB  */
  YYSYMBOL_LUSHR = 219,                    /* LUSHR  */
  YYSYMBOL_LXOR = 220,                     /* LXOR  */
  YYSYMBOL_MONITORENTER = 221,             /* MONITORENTER  */
  YYSYMBOL_MONITOREXIT = 222,              /* MONITOREXIT  */
  YYSYMBOL_NOP = 223,                      /* NOP  */
  YYSYMBOL_POP = 224,                      /* POP  */
  YYSYMBOL_POP2 = 225,                     /* POP2  */
  YYSYMBOL_RETURN = 226,                   /* RETURN  */
  YYSYMBOL_SALOAD = 227,                   /* SALOAD  */
  YYSYMBOL_SASTORE = 228,                  /* SASTORE  */
  YYSYMBOL_SWAP = 229,                     /* SWAP  */
  YYSYMBOL_IINC = 230,                     /* IINC  */
  YYSYMBOL_INSTANCEOF = 231,               /* INSTANCEOF  */
  YYSYMBOL_INVOKEINTERFACE = 232,          /* INVOKEINTERFACE  */
  YYSYMBOL_INVOKENONVIRTUAL = 233,         /* INVOKENONVIRTUAL  */
  YYSYMBOL_INVOKESTATIC = 234,             /* INVOKESTATIC  */
  YYSYMBOL_INVOKEVIRTUAL = 235,            /* INVOKEVIRTUAL  */
  YYSYMBOL_LDC = 236,                      /* LDC  */
  YYSYMBOL_LDC_W = 237,                    /* LDC_W  */
  YYSYMBOL_LDC2_W = 238,                   /* LDC2_W  */
  YYSYMBOL_MULTIANEWARRAY = 239,           /* MULTIANEWARRAY  */
  YYSYMBOL_NEW = 240,                      /* NEW  */
  YYSYMBOL_NEWARRAY = 241,                 /* NEWARRAY  */
  YYSYMBOL_PUTFIELD = 242,                 /* PUTFIELD  */
  YYSYMBOL_PUTSTATIC = 243,                /* PUTSTATIC  */
  YYSYMBOL_SIPUSH = 244,                   /* SIPUSH  */
  YYSYMBOL_ILOAD = 245,                    /* ILOAD  */
  YYSYMBOL_FLOAD = 246,                    /* FLOAD  */
  YYSYMBOL_ALOAD = 247,                    /* ALOAD  */
  YYSYMBOL_LLOAD = 248,                    /* LLOAD  */
  YYSYMBOL_DLOAD = 249,                    /* DLOAD  */
  YYSYMBOL_ISTORE = 250,                   /* ISTORE  */
  YYSYMBOL_FSTORE = 251,                   /* FSTORE  */
  YYSYMBOL_ASTORE = 252,                   /* ASTORE  */
  YYSYMBOL_LSTORE = 253,                   /* LSTORE  */
  YYSYMBOL_DSTORE = 254,                   /* DSTORE  */
  YYSYMBOL_RET = 255,                      /* RET  */
  YYSYMBOL_WIDE = 256,                     /* WIDE  */
  YYSYMBOL_LOAD = 257,                     /* LOAD  */
  YYSYMBOL_STORE = 258,                    /* STORE  */
  YYSYMBOL_LOOKUPSWITCH = 259,             /* LOOKUPSWITCH  */
  YYSYMBOL_TABLESWITCH = 260,              /* TABLESWITCH  */
  YYSYMBOL_261_ = 261,                     /* '{'  */
  YYSYMBOL_262_ = 262,                     /* '}'  */
  YYSYMBOL_263_ = 263,                     /* '.'  */
  YYSYMBOL_264_ = 264,                     /* '='  */
  YYSYMBOL_265_ = 265,                     /* '('  */
  YYSYMBOL_266_ = 266,                     /* ')'  */
  YYSYMBOL_267_ = 267,                     /* ','  */
  YYSYMBOL_268_ = 268,                     /* '['  */
  YYSYMBOL_269_ = 269,                     /* ']'  */
  YYSYMBOL_270_ = 270,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 271,                 /* $accept  */
  YYSYMBOL_compilation_unit = 272,         /* compilation_unit  */
  YYSYMBOL_273_1 = 273,                    /* $@1  */
  YYSYMBOL_classlist = 274,                /* classlist  */
  YYSYMBOL_class = 275,                    /* class  */
  YYSYMBOL_276_2 = 276,                    /* $@2  */
  YYSYMBOL_class_modifiers = 277,          /* class_modifiers  */
  YYSYMBOL_classword = 278,                /* classword  */
  YYSYMBOL_superclass = 279,               /* superclass  */
  YYSYMBOL_classname = 280,                /* classname  */
  YYSYMBOL_classfieldmethodname = 281,     /* classfieldmethodname  */
  YYSYMBOL_endname = 282,                  /* endname  */
  YYSYMBOL_abstract_entry = 283,           /* abstract_entry  */
  YYSYMBOL_final_entry = 284,              /* final_entry  */
  YYSYMBOL_public_entry = 285,             /* public_entry  */
  YYSYMBOL_interface_entry = 286,          /* interface_entry  */
  YYSYMBOL_static_entry = 287,             /* static_entry  */
  YYSYMBOL_native_entry = 288,             /* native_entry  */
  YYSYMBOL_synchronized_entry = 289,       /* synchronized_entry  */
  YYSYMBOL_transient_entry = 290,          /* transient_entry  */
  YYSYMBOL_volatile_entry = 291,           /* volatile_entry  */
  YYSYMBOL_access_specifier = 292,         /* access_specifier  */
  YYSYMBOL_interfaces = 293,               /* interfaces  */
  YYSYMBOL_interfacelist = 294,            /* interfacelist  */
  YYSYMBOL_fieldlist = 295,                /* fieldlist  */
  YYSYMBOL_field = 296,                    /* field  */
  YYSYMBOL_fieldconstant = 297,            /* fieldconstant  */
  YYSYMBOL_field_modifiers = 298,          /* field_modifiers  */
  YYSYMBOL_methodlist = 299,               /* methodlist  */
  YYSYMBOL_method = 300,                   /* method  */
  YYSYMBOL_301_3 = 301,                    /* $@3  */
  YYSYMBOL_302_4 = 302,                    /* $@4  */
  YYSYMBOL_throwslist = 303,               /* throwslist  */
  YYSYMBOL_throwsentries = 304,            /* throwsentries  */
  YYSYMBOL_max_locals_decl = 305,          /* max_locals_decl  */
  YYSYMBOL_returntype = 306,               /* returntype  */
  YYSYMBOL_arguments = 307,                /* arguments  */
  YYSYMBOL_argumentlist = 308,             /* argumentlist  */
  YYSYMBOL_methodarguments = 309,          /* methodarguments  */
  YYSYMBOL_methodargumentlist = 310,       /* methodargumentlist  */
  YYSYMBOL_methodargument = 311,           /* methodargument  */
  YYSYMBOL_type = 312,                     /* type  */
  YYSYMBOL_basetype = 313,                 /* basetype  */
  YYSYMBOL_arrayadder = 314,               /* arrayadder  */
  YYSYMBOL_method_modifiers = 315,         /* method_modifiers  */
  YYSYMBOL_localvar = 316,                 /* localvar  */
  YYSYMBOL_arrayorclassname = 317,         /* arrayorclassname  */
  YYSYMBOL_code = 318,                     /* code  */
  YYSYMBOL_op_list = 319,                  /* op_list  */
  YYSYMBOL_op_line = 320,                  /* op_line  */
  YYSYMBOL_label = 321,                    /* label  */
  YYSYMBOL_op = 322,                       /* op  */
  YYSYMBOL_no_arg_op = 323,                /* no_arg_op  */
  YYSYMBOL_one_arg_op = 324,               /* one_arg_op  */
  YYSYMBOL_methodref_arg_op = 325,         /* methodref_arg_op  */
  YYSYMBOL_fieldref_arg_op = 326,          /* fieldref_arg_op  */
  YYSYMBOL_class_arg_op = 327,             /* class_arg_op  */
  YYSYMBOL_label_arg_op = 328,             /* label_arg_op  */
  YYSYMBOL_localvar_arg_op = 329,          /* localvar_arg_op  */
  YYSYMBOL_localvar_arg = 330,             /* localvar_arg  */
  YYSYMBOL_lookuplist = 331,               /* lookuplist  */
  YYSYMBOL_tablelist = 332,                /* tablelist  */
  YYSYMBOL_newarraytype = 333,             /* newarraytype  */
  YYSYMBOL_argument = 334,                 /* argument  */
  YYSYMBOL_exceptiontable = 335,           /* exceptiontable  */
  YYSYMBOL_exceptionslist = 336,           /* exceptionslist  */
  YYSYMBOL_linenumbertable = 337,          /* linenumbertable  */
  YYSYMBOL_linenumberlist = 338,           /* linenumberlist  */
  YYSYMBOL_localvariabletable = 339,       /* localvariabletable  */
  YYSYMBOL_localvariablelist = 340,        /* localvariablelist  */
  YYSYMBOL_sourcefilename = 341            /* sourcefilename  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 389 "javaa.y"

   static void     CheckStructDcl(Type,int);
   static MimeType GenBlankMimeType();
   static Type     GenBlankType();
   static TreeNode *MakeBinOpSubTree(int, TreeNode *, TreeNode *);
   static TreeNode *MakeUnOpSubTree(int, TreeNode *);
   static TreeNode *MakeFuncSibs(TreeNode *, TreeNode *, TreeNode *,
              TreeNode *, TreeNode *);
   static TreeNode *GenEntryArgs(TreeNode *);

#line 468 "javaa.tab.c"


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
#define YYLAST   850

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  271
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  346
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  434

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   515


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     265,   266,     2,     2,   267,     2,   263,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   270,     2,
       2,   264,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   268,     2,   269,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   261,     2,   262,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   403,   403,   403,   408,   409,   414,   412,   421,   425,
     427,   432,   434,   442,   446,   453,   459,   467,   473,   481,
     483,   487,   489,   493,   495,   499,   501,   505,   507,   511,
     513,   517,   519,   523,   525,   529,   531,   535,   537,   539,
     541,   543,   547,   549,   553,   555,   560,   561,   564,   569,
     573,   577,   581,   586,   591,   596,   597,   601,   606,   601,
     622,   624,   628,   630,   635,   637,   641,   643,   652,   654,
     657,   662,   668,   670,   673,   678,   681,   685,   690,   697,
     699,   701,   703,   705,   707,   709,   711,   713,   721,   723,
     727,   732,   737,   739,   744,   748,   751,   754,   756,   758,
     760,   764,   768,   771,   774,   777,   783,   786,   789,   796,
     799,   802,   805,   808,   812,   815,   820,   822,   824,   826,
     828,   830,   832,   834,   836,   838,   840,   842,   844,   846,
     848,   850,   852,   854,   856,   858,   860,   862,   864,   866,
     868,   870,   872,   874,   876,   878,   880,   882,   884,   886,
     888,   890,   892,   894,   896,   898,   900,   902,   904,   906,
     908,   910,   912,   914,   916,   918,   920,   922,   924,   926,
     928,   930,   932,   934,   936,   938,   940,   942,   944,   946,
     948,   950,   952,   954,   956,   958,   960,   962,   964,   966,
     968,   970,   972,   974,   976,   978,   980,   982,   984,   986,
     988,   990,   992,   994,   996,   998,  1000,  1002,  1004,  1006,
    1008,  1010,  1012,  1014,  1016,  1018,  1020,  1022,  1024,  1026,
    1028,  1030,  1032,  1034,  1036,  1038,  1040,  1042,  1044,  1046,
    1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,  1066,
    1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,  1084,  1086,
    1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1118,  1120,  1122,  1124,  1126,  1132,
    1134,  1136,  1141,  1143,  1145,  1147,  1152,  1154,  1156,  1160,
    1162,  1164,  1166,  1168,  1170,  1172,  1174,  1176,  1178,  1180,
    1182,  1184,  1186,  1188,  1190,  1192,  1194,  1196,  1198,  1203,
    1205,  1207,  1209,  1211,  1213,  1215,  1217,  1219,  1221,  1223,
    1225,  1227,  1231,  1233,  1237,  1239,  1242,  1244,  1248,  1250,
    1252,  1254,  1256,  1258,  1260,  1262,  1266,  1270,  1274,  1278,
    1282,  1287,  1295,  1297,  1300,  1302,  1307,  1311,  1313,  1316,
    1318,  1322,  1324,  1327,  1330,  1334,  1336
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
  "\"end of file\"", "error", "\"invalid token\"", "LABEL", "IDENTIFIER",
  "INTCONSTANT", "LONGCONSTANT", "FLOATCONSTANT", "DOUBLECONSTANT",
  "CHARCONSTANT", "STRING_LITERAL", "CLASS", "EXTENDS", "ACCESS",
  "IMPLEMENTS", "FIELD", "METHOD", "MAX_STACK", "MAX_LOCALS", "CODE",
  "PUBLIC", "PRIVATE", "PROTECTED", "ABSTRACT", "FINAL", "INTERFACE",
  "STATIC", "NATIVE", "SYNCHRONIZED", "TRANSIENT", "VOLATILE", "BYTE",
  "CHAR", "DOUBLE", "FLOAT", "INT", "LONG", "SHORT", "BOOLEAN", "VOID",
  "DEFAULT", "TO", "EXCEPTIONS", "SOURCEFILE", "THROWS", "LINENUMBERTABLE",
  "LOCALVARIABLETABLE", "ACC_PUBLIC", "ACC_PRIVATE", "ACC_PROTECTED",
  "ACC_STATIC", "ACC_FINAL", "ACC_SYNCHRONIZED", "ACC_VOLATILE",
  "ACC_TRANSIENT", "ACC_NATIVE", "ACC_INTERFACE", "ACC_ABSTRACT", "AALOAD",
  "AASTORE", "ACONST_NULL", "ALOAD_0", "ALOAD_1", "ALOAD_2", "ALOAD_3",
  "ANEWARRAY", "ARETURN", "ARRAYLENGTH", "ASTORE_0", "ASTORE_1",
  "ASTORE_2", "ASTORE_3", "ATHROW", "BALOAD", "BASTORE", "BIPUSH",
  "CALOAD", "CASTORE", "CHECKCAST", "D2F", "D2I", "D2L", "DADD", "DALOAD",
  "DASTORE", "DCMPG", "DCMPL", "DCONST_0", "DCONST_1", "DDIV", "DLOAD_0",
  "DLOAD_1", "DLOAD_2", "DLOAD_3", "DMUL", "DNEG", "DREM", "DRETURN",
  "DSTORE_0", "DSTORE_1", "DSTORE_2", "DSTORE_3", "DSUB", "DUP", "DUP_X1",
  "DUP_X2", "DUP2", "DUP2_X1", "DUP2_X2", "F2D", "F2I", "F2L", "FADD",
  "FALOAD", "FASTORE", "FCMPG", "FCMPL", "FCONST_0", "FCONST_1",
  "FCONST_2", "FDIV", "FLOAD_0", "FLOAD_1", "FLOAD_2", "FLOAD_3", "FMUL",
  "FNEG", "FREM", "FRETURN", "FSTORE_0", "FSTORE_1", "FSTORE_2",
  "FSTORE_3", "FSUB", "GETFIELD", "GETSTATIC", "GOTO", "GOTO_W", "I2B",
  "I2C", "I2D", "I2F", "I2L", "I2S", "IADD", "IALOAD", "IAND", "IASTORE",
  "ICONST_0", "ICONST_1", "ICONST_2", "ICONST_3", "ICONST_4", "ICONST_5",
  "ICONST_M1", "IDIV", "IF_ACMPEQ", "IF_ACMPNE", "IF_ICMPEQ", "IF_ICMPNE",
  "IF_ICMPLT", "IF_ICMPGE", "IF_ICMPGT", "IF_ICMPLE", "IFEQ", "IFNE",
  "IFLT", "IFGE", "IFGT", "IFLE", "IFNONNULL", "IFNULL", "ILOAD_0",
  "ILOAD_1", "ILOAD_2", "ILOAD_3", "IMUL", "INEG", "IOR", "IREM",
  "IRETURN", "ISHL", "ISHR", "ISTORE_0", "ISTORE_1", "ISTORE_2",
  "ISTORE_3", "ISUB", "IUSHR", "IXOR", "JSR", "JSR_W", "L2D", "L2F", "L2I",
  "LADD", "LALOAD", "LAND", "LASTORE", "LCMP", "LCONST_0", "LCONST_1",
  "LDIV", "LLOAD_0", "LLOAD_1", "LLOAD_2", "LLOAD_3", "LMUL", "LNEG",
  "LOR", "LREM", "LRETURN", "LSHL", "LSHR", "LSTORE_0", "LSTORE_1",
  "LSTORE_2", "LSTORE_3", "LSUB", "LUSHR", "LXOR", "MONITORENTER",
  "MONITOREXIT", "NOP", "POP", "POP2", "RETURN", "SALOAD", "SASTORE",
  "SWAP", "IINC", "INSTANCEOF", "INVOKEINTERFACE", "INVOKENONVIRTUAL",
  "INVOKESTATIC", "INVOKEVIRTUAL", "LDC", "LDC_W", "LDC2_W",
  "MULTIANEWARRAY", "NEW", "NEWARRAY", "PUTFIELD", "PUTSTATIC", "SIPUSH",
  "ILOAD", "FLOAD", "ALOAD", "LLOAD", "DLOAD", "ISTORE", "FSTORE",
  "ASTORE", "LSTORE", "DSTORE", "RET", "WIDE", "LOAD", "STORE",
  "LOOKUPSWITCH", "TABLESWITCH", "'{'", "'}'", "'.'", "'='", "'('", "')'",
  "','", "'['", "']'", "':'", "$accept", "compilation_unit", "$@1",
  "classlist", "class", "$@2", "class_modifiers", "classword",
  "superclass", "classname", "classfieldmethodname", "endname",
  "abstract_entry", "final_entry", "public_entry", "interface_entry",
  "static_entry", "native_entry", "synchronized_entry", "transient_entry",
  "volatile_entry", "access_specifier", "interfaces", "interfacelist",
  "fieldlist", "field", "fieldconstant", "field_modifiers", "methodlist",
  "method", "$@3", "$@4", "throwslist", "throwsentries", "max_locals_decl",
  "returntype", "arguments", "argumentlist", "methodarguments",
  "methodargumentlist", "methodargument", "type", "basetype", "arrayadder",
  "method_modifiers", "localvar", "arrayorclassname", "code", "op_list",
  "op_line", "label", "op", "no_arg_op", "one_arg_op", "methodref_arg_op",
  "fieldref_arg_op", "class_arg_op", "label_arg_op", "localvar_arg_op",
  "localvar_arg", "lookuplist", "tablelist", "newarraytype", "argument",
  "exceptiontable", "exceptionslist", "linenumbertable", "linenumberlist",
  "localvariabletable", "localvariablelist", "sourcefilename", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-314)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-88)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -314,    14,     5,  -314,  -314,  -314,    13,    32,     7,  -314,
    -314,    45,  -314,    34,    41,  -314,    30,    62,    53,  -314,
    -314,  -195,  -314,    62,  -192,    62,  -314,    62,  -314,  -314,
    -314,    55,    20,  -314,  -314,  -314,    49,  -314,    57,    -4,
    -314,  -314,     7,    42,    20,    71,  -314,  -178,    56,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    83,  -180,
      57,  -314,  -314,  -314,    59,  -174,  -177,  -314,     5,  -314,
    -314,  -314,    27,  -314,  -180,     7,    26,  -314,  -314,  -314,
    -314,  -314,    64,  -314,    89,  -314,  -314,    66,  -170,  -314,
    -314,    42,  -169,  -314,  -171,    94,    58,    42,  -314,    62,
      82,  -314,  -314,    62,    95,  -314,    85,    96,  -314,  -314,
    -157,  -314,    63,   333,  -155,    65,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,    42,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    33,
    -314,    26,  -314,  -314,  -314,  -314,  -314,  -314,    42,  -314,
     -16,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    68,   104,
     107,  -314,  -314,   590,  -314,  -314,    19,    26,    42,    62,
     108,    33,  -314,  -148,    69,  -154,  -152,  -314,  -314,  -314,
     112,   114,   115,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,   117,    78,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,   114,   114,  -314,  -314,  -314,    -1,
    -314,  -139,  -138,  -146,  -314,  -137,  -140,  -314,  -134,   123,
    -136,  -314,   126,  -314,     0,  -314,  -314,  -180,   127,    42,
     128,    92,    42,   130,   131,  -314,     1,  -314,  -128,  -314,
    -129,  -314,  -127,  -132,  -123,   137,  -124,    43,  -314,   139,
    -314,   127,   140,    42,   142,  -314,  -114,  -314,  -314,  -314,
      42,  -314,  -314,  -314,   128,   144,   145,  -314,   144,  -118,
     146,  -314,  -314,  -314
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,    20,     1,    19,     3,    20,    10,    22,     4,
       9,     0,    21,    24,    12,    23,    26,     0,    43,    25,
       8,    14,    11,     0,     0,     0,    45,    42,    47,    13,
      44,     6,    41,    56,    46,    40,    37,    39,    28,   346,
      38,    27,    22,     0,    41,     0,    55,     0,    34,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,    89,
      28,   345,     7,    33,    36,    53,     0,    78,    20,    57,
      35,    54,     0,    48,    89,    22,     0,    49,    51,    50,
      52,    88,    30,    67,     0,    66,    29,    32,     0,    31,
      90,    73,     0,    72,    75,    76,    61,     0,    77,     0,
       0,    74,    63,    60,     0,    62,    65,     0,    58,    64,
       0,    96,   333,    94,     0,   338,   101,   116,   117,   118,
     119,   120,   121,   122,     0,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   264,   132,   133,   276,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   272,   273,   279,   280,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   297,
     298,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,     0,
     277,     0,   270,   269,   271,   265,   266,   267,     0,   278,
       0,   274,   275,   268,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   263,   310,   311,     0,     0,
       0,    99,    95,     0,    98,   102,     0,     0,     0,     0,
       0,     0,   336,     0,   342,    92,     0,   107,   313,   312,
       0,     0,     0,   322,   319,   321,   320,   324,   325,   323,
     318,   115,     0,     0,    91,   100,    97,   326,   327,   328,
     330,   331,   329,   103,     0,     0,   106,   109,   110,     0,
     340,     0,     0,     0,   111,    16,     0,   114,     0,     0,
       0,   104,     0,   332,     0,   344,    59,    89,     0,    69,
     315,     0,    69,     0,     0,   337,     0,    93,    18,    15,
       0,    68,    71,     0,     0,     0,     0,     0,   339,     0,
     341,     0,     0,     0,     0,   112,     0,   105,   335,   334,
       0,    17,   108,    70,   315,   317,     0,   314,   317,     0,
       0,   316,   113,   343
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -314,  -314,  -314,   147,  -314,  -314,  -314,  -314,  -314,   -17,
    -313,  -261,    84,   -31,  -314,  -314,    97,  -314,  -314,  -314,
    -314,   110,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -282,  -237,  -257,  -314,    61,
    -314,   -41,  -117,   -73,  -314,  -164,  -135,  -314,  -314,  -314,
    -314,  -163,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -167,
    -263,  -266,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     6,    33,     7,    11,    18,    57,
     376,   399,     8,    13,    16,    20,    42,    87,    90,    64,
      71,    38,    24,    27,    31,    34,    73,    43,    39,    46,
      76,   110,   100,   103,   108,    84,   400,   401,    92,    93,
      94,    85,    59,    67,    69,   321,   337,   112,   113,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   340,
     404,   429,   351,   363,   115,   369,   334,   384,   372,   396,
      47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    81,    58,   382,   394,   409,    26,   336,    29,   341,
      30,    48,    44,    -5,     3,   343,   344,   345,   346,   347,
     348,   349,   350,   357,   358,   359,   360,   361,     4,   362,
      21,    12,    77,    78,    79,    80,     4,   338,   339,    45,
      35,    36,    37,    10,    82,   364,    21,    21,   418,    14,
      95,   380,   381,    17,    15,    19,    95,    49,    50,    51,
      52,    53,    54,    55,    56,    83,    21,    23,    25,    28,
      32,    40,   320,    49,    50,    51,    52,    53,    54,    55,
      56,    61,   102,    41,    62,    63,   105,    65,    66,    70,
      72,    86,    74,    88,    89,    91,    97,    96,    98,   104,
     106,   109,    99,   107,   111,   114,   332,   335,   352,   353,
     333,   354,   367,   370,   -87,   371,   373,   374,   375,   379,
     377,   378,   385,   387,   386,   389,   388,   390,   391,   392,
     393,   398,   405,   403,   407,   411,   408,   412,   414,   415,
     413,   416,   417,   420,   432,   422,   424,   425,   428,   430,
     421,   433,    75,     9,    60,   406,   423,    68,   101,   355,
     356,   427,   431,   342,   368,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   383,   395,   410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   335,   320,     0,     0,     0,     0,   365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   366,     0,   397,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   402,     0,
       0,   402,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,   402,     0,     0,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     419,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319
};

static const yytype_int16 yycheck[] =
{
      17,    74,    43,     4,     4,     4,    23,   124,    25,   291,
      27,    42,    16,     0,     0,    31,    32,    33,    34,    35,
      36,    37,    38,     4,     5,     6,     7,     8,    23,    10,
       4,    24,     5,     6,     7,     8,    23,     4,     5,    43,
      20,    21,    22,    11,    75,   327,     4,     4,     5,     4,
      91,   364,   365,    12,    20,    25,    97,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     4,    14,   263,   261,
      15,    22,   113,    31,    32,    33,    34,    35,    36,    37,
      38,    10,    99,    26,   262,    29,   103,     4,   268,    30,
     264,    27,   269,     4,    28,   265,   267,   266,     4,    17,
       5,     5,    44,    18,   261,    42,   261,   124,    40,     5,
      45,     4,     4,   261,   268,    46,   268,     5,     4,    41,
       5,     4,   261,   269,   262,   265,   263,   261,     5,   265,
       4,     4,    40,     5,     4,   263,     5,   266,   270,   262,
     267,     4,   266,     4,   262,     5,     4,   261,     4,     4,
     411,     5,    68,     6,    44,   392,   413,    60,    97,   323,
     323,   424,   428,   298,   331,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,   262,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   298,   323,    -1,    -1,    -1,    -1,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   329,    -1,   387,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,    -1,
      -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,   413,    -1,    -1,    -1,    -1,    -1,    -1,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     407,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   272,   273,     0,    23,   274,   275,   277,   283,   274,
      11,   278,    24,   284,     4,    20,   285,    12,   279,    25,
     286,     4,   280,    14,   293,   263,   280,   294,   261,   280,
     280,   295,    15,   276,   296,    20,    21,    22,   292,   299,
      22,    26,   287,   298,    16,    43,   300,   341,   284,    31,
      32,    33,    34,    35,    36,    37,    38,   280,   312,   313,
     292,    10,   262,    29,   290,     4,   268,   314,   287,   315,
      30,   291,   264,   297,   269,   283,   301,     5,     6,     7,
       8,   314,   284,    39,   306,   312,    27,   288,     4,    28,
     289,   265,   309,   310,   311,   312,   266,   267,     4,    44,
     303,   310,   280,   304,    17,   280,     5,    18,   305,     5,
     302,   261,   318,   319,    42,   335,     3,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     312,   316,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   261,    45,   337,   280,   313,   317,     4,     5,
     330,   306,   317,    31,    32,    33,    34,    35,    36,    37,
      38,   333,    40,     5,     4,   316,   322,     4,     5,     6,
       7,     8,    10,   334,   306,   312,   280,     4,   330,   336,
     261,    46,   339,   268,     5,     4,   281,     5,     4,    41,
     281,   281,     4,   262,   338,   261,   262,   269,   263,   265,
     261,     5,   265,     4,     4,   262,   340,   314,     4,   282,
     307,   308,   312,     5,   331,    40,   307,     4,     5,     4,
     262,   263,   266,   267,   270,   262,     4,   266,     5,   280,
       4,   282,     5,   308,     4,   261,   312,   331,     4,   332,
       4,   332,   262,     5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   271,   273,   272,   274,   274,   276,   275,   277,   278,
     278,   279,   279,   280,   280,   281,   281,   282,   282,   283,
     283,   284,   284,   285,   285,   286,   286,   287,   287,   288,
     288,   289,   289,   290,   290,   291,   291,   292,   292,   292,
     292,   292,   293,   293,   294,   294,   295,   295,   296,   297,
     297,   297,   297,   297,   298,   299,   299,   301,   302,   300,
     303,   303,   304,   304,   305,   305,   306,   306,   307,   307,
     308,   308,   309,   309,   310,   310,   311,   311,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     315,   316,   317,   317,   318,   319,   319,   320,   320,   320,
     320,   321,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   324,   324,   324,   324,   324,   325,
     325,   325,   326,   326,   326,   326,   327,   327,   327,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   330,   330,   331,   331,   332,   332,   333,   333,
     333,   333,   333,   333,   333,   333,   334,   334,   334,   334,
     334,   334,   335,   335,   336,   336,   336,   337,   337,   338,
     338,   339,   339,   340,   340,   341,   341
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     0,    11,     4,     1,
       0,     2,     0,     3,     1,     3,     1,     3,     1,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     2,     1,
       1,     0,     2,     0,     2,     1,     2,     0,     6,     2,
       2,     2,     2,     0,     4,     2,     0,     0,     0,    20,
       2,     0,     2,     1,     2,     0,     1,     1,     1,     0,
       3,     1,     1,     0,     3,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       5,     2,     1,     4,     1,     2,     0,     2,     1,     1,
       2,     1,     1,     2,     3,     6,     2,     2,     7,     2,
       2,     3,     6,     9,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     2,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     5,     5,     0,     4,     0,     3,
       0,     4,     0,     6,     0,     2,     0
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
#line 403 "javaa.y"
          { InitAssembler();}
#line 1906 "javaa.tab.c"
    break;

  case 3: /* compilation_unit: $@1 classlist  */
#line 404 "javaa.y"
                { EndAssembler();}
#line 1912 "javaa.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 414 "javaa.y"
                {
		SetThisClass((yyvsp[-6].intval), (yyvsp[-4].string), (yyvsp[-3].string));
		}
#line 1920 "javaa.tab.c"
    break;

  case 8: /* class_modifiers: abstract_entry final_entry public_entry interface_entry  */
#line 422 "javaa.y"
                {(yyval.intval) = (yyvsp[-3].intval) | (yyvsp[-2].intval) | (yyvsp[-1].intval) | (yyvsp[0].intval);}
#line 1926 "javaa.tab.c"
    break;

  case 9: /* classword: CLASS  */
#line 426 "javaa.y"
                {break;}
#line 1932 "javaa.tab.c"
    break;

  case 10: /* classword: %empty  */
#line 427 "javaa.y"
                {break;}
#line 1938 "javaa.tab.c"
    break;

  case 11: /* superclass: EXTENDS classname  */
#line 433 "javaa.y"
                { (yyval.string) = (yyvsp[0].string);}
#line 1944 "javaa.tab.c"
    break;

  case 12: /* superclass: %empty  */
#line 434 "javaa.y"
          {
	    char* tempstring;
	    tempstring = (char *) malloc(strlen("java/lang/Object"));
	    strcpy(tempstring,"java/lang/Object");
	    (yyval.string) = tempstring;
	  }
#line 1955 "javaa.tab.c"
    break;

  case 13: /* classname: IDENTIFIER '.' classname  */
#line 443 "javaa.y"
                {
		  (yyval.string) = ConsStrings((yyvsp[-2].string),ConsStrings("/",(yyvsp[0].string)));
		}
#line 1963 "javaa.tab.c"
    break;

  case 14: /* classname: IDENTIFIER  */
#line 447 "javaa.y"
                {
		  (yyval.string) = (yyvsp[0].string);
		}
#line 1971 "javaa.tab.c"
    break;

  case 15: /* classfieldmethodname: IDENTIFIER '.' endname  */
#line 454 "javaa.y"
                {
		  if ((yyvsp[0].classfieldmethodstruct).classname == NULL) (yyval.classfieldmethodstruct).classname = (yyvsp[-2].string);
		  else (yyval.classfieldmethodstruct).classname = ConsStrings((yyvsp[-2].string),ConsStrings("/",(yyvsp[0].classfieldmethodstruct).classname));
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[0].classfieldmethodstruct).fieldmethodname;
		}
#line 1981 "javaa.tab.c"
    break;

  case 16: /* classfieldmethodname: IDENTIFIER  */
#line 460 "javaa.y"
                {
		  (yyval.classfieldmethodstruct).classname = GetThisClass();
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[0].string);
		}
#line 1990 "javaa.tab.c"
    break;

  case 17: /* endname: IDENTIFIER '.' endname  */
#line 468 "javaa.y"
                {
		  if ((yyvsp[0].classfieldmethodstruct).classname == NULL) (yyval.classfieldmethodstruct).classname = (yyvsp[-2].string);
		  else (yyval.classfieldmethodstruct).classname = ConsStrings((yyvsp[-2].string),ConsStrings("/",(yyvsp[0].classfieldmethodstruct).classname));
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[0].classfieldmethodstruct).fieldmethodname;
		}
#line 2000 "javaa.tab.c"
    break;

  case 18: /* endname: IDENTIFIER  */
#line 474 "javaa.y"
                {
		  (yyval.classfieldmethodstruct).classname = NULL;
		  (yyval.classfieldmethodstruct).fieldmethodname = (yyvsp[0].string);
		}
#line 2009 "javaa.tab.c"
    break;

  case 19: /* abstract_entry: ABSTRACT  */
#line 482 "javaa.y"
                {(yyval.intval) = 0x0400;}
#line 2015 "javaa.tab.c"
    break;

  case 20: /* abstract_entry: %empty  */
#line 483 "javaa.y"
          {(yyval.intval)=0;}
#line 2021 "javaa.tab.c"
    break;

  case 21: /* final_entry: FINAL  */
#line 488 "javaa.y"
                {(yyval.intval) = 0x0010;}
#line 2027 "javaa.tab.c"
    break;

  case 22: /* final_entry: %empty  */
#line 489 "javaa.y"
          {(yyval.intval)=0;}
#line 2033 "javaa.tab.c"
    break;

  case 23: /* public_entry: PUBLIC  */
#line 494 "javaa.y"
                {(yyval.intval) = 0x0001;}
#line 2039 "javaa.tab.c"
    break;

  case 24: /* public_entry: %empty  */
#line 495 "javaa.y"
          {(yyval.intval)=0;}
#line 2045 "javaa.tab.c"
    break;

  case 25: /* interface_entry: INTERFACE  */
#line 500 "javaa.y"
                {(yyval.intval) = 0x0200;}
#line 2051 "javaa.tab.c"
    break;

  case 26: /* interface_entry: %empty  */
#line 501 "javaa.y"
          {(yyval.intval)=0;}
#line 2057 "javaa.tab.c"
    break;

  case 27: /* static_entry: STATIC  */
#line 506 "javaa.y"
                {(yyval.intval) = 0x0008;}
#line 2063 "javaa.tab.c"
    break;

  case 28: /* static_entry: %empty  */
#line 507 "javaa.y"
          {(yyval.intval)=0;}
#line 2069 "javaa.tab.c"
    break;

  case 29: /* native_entry: NATIVE  */
#line 512 "javaa.y"
                {(yyval.intval) = 0x0100;}
#line 2075 "javaa.tab.c"
    break;

  case 30: /* native_entry: %empty  */
#line 513 "javaa.y"
          {(yyval.intval)=0;}
#line 2081 "javaa.tab.c"
    break;

  case 31: /* synchronized_entry: SYNCHRONIZED  */
#line 518 "javaa.y"
                {(yyval.intval) = 0x0020;}
#line 2087 "javaa.tab.c"
    break;

  case 32: /* synchronized_entry: %empty  */
#line 519 "javaa.y"
          {(yyval.intval)=0;}
#line 2093 "javaa.tab.c"
    break;

  case 33: /* transient_entry: TRANSIENT  */
#line 524 "javaa.y"
                {(yyval.intval) = 0x0080;}
#line 2099 "javaa.tab.c"
    break;

  case 34: /* transient_entry: %empty  */
#line 525 "javaa.y"
          {(yyval.intval)=0;}
#line 2105 "javaa.tab.c"
    break;

  case 35: /* volatile_entry: VOLATILE  */
#line 530 "javaa.y"
                {(yyval.intval) = 0x0040;}
#line 2111 "javaa.tab.c"
    break;

  case 36: /* volatile_entry: %empty  */
#line 531 "javaa.y"
          {(yyval.intval)=0;}
#line 2117 "javaa.tab.c"
    break;

  case 37: /* access_specifier: PRIVATE  */
#line 536 "javaa.y"
                {(yyval.intval) = 2;}
#line 2123 "javaa.tab.c"
    break;

  case 38: /* access_specifier: PRIVATE PROTECTED  */
#line 538 "javaa.y"
                {(yyval.intval) = 6;}
#line 2129 "javaa.tab.c"
    break;

  case 39: /* access_specifier: PROTECTED  */
#line 540 "javaa.y"
                {(yyval.intval) = 4;}
#line 2135 "javaa.tab.c"
    break;

  case 40: /* access_specifier: PUBLIC  */
#line 542 "javaa.y"
                {(yyval.intval) = 1;}
#line 2141 "javaa.tab.c"
    break;

  case 41: /* access_specifier: %empty  */
#line 543 "javaa.y"
          {(yyval.intval)=0;}
#line 2147 "javaa.tab.c"
    break;

  case 42: /* interfaces: IMPLEMENTS interfacelist  */
#line 548 "javaa.y"
                {break;}
#line 2153 "javaa.tab.c"
    break;

  case 43: /* interfaces: %empty  */
#line 549 "javaa.y"
                {break;}
#line 2159 "javaa.tab.c"
    break;

  case 44: /* interfacelist: interfacelist classname  */
#line 554 "javaa.y"
                { AddToInterfaceList((yyvsp[0].string));}
#line 2165 "javaa.tab.c"
    break;

  case 45: /* interfacelist: classname  */
#line 556 "javaa.y"
                { AddToInterfaceList((yyvsp[0].string));}
#line 2171 "javaa.tab.c"
    break;

  case 47: /* fieldlist: %empty  */
#line 561 "javaa.y"
          {break;}
#line 2177 "javaa.tab.c"
    break;

  case 48: /* field: FIELD access_specifier field_modifiers type IDENTIFIER fieldconstant  */
#line 565 "javaa.y"
                {NewField((yyvsp[-4].intval)|(yyvsp[-3].intval), (yyvsp[-1].string), (yyvsp[-2].string), (yyvsp[0].argtype));}
#line 2183 "javaa.tab.c"
    break;

  case 49: /* fieldconstant: '=' INTCONSTANT  */
#line 570 "javaa.y"
             {(yyval.argtype).type = INTCONSTANT;
              (yyval.argtype).intval = (yyvsp[0].intval);
             }
#line 2191 "javaa.tab.c"
    break;

  case 50: /* fieldconstant: '=' FLOATCONSTANT  */
#line 574 "javaa.y"
             {(yyval.argtype).type = FLOATCONSTANT;
              (yyval.argtype).floatval = (yyvsp[0].floatval);
             }
#line 2199 "javaa.tab.c"
    break;

  case 51: /* fieldconstant: '=' LONGCONSTANT  */
#line 578 "javaa.y"
             {(yyval.argtype).type = LONGCONSTANT;
              (yyval.argtype).longval = (yyvsp[0].longval);
             }
#line 2207 "javaa.tab.c"
    break;

  case 52: /* fieldconstant: '=' DOUBLECONSTANT  */
#line 582 "javaa.y"
             {(yyval.argtype).type = DOUBLECONSTANT;
              (yyval.argtype).doubleval = (yyvsp[0].doubleval);
             }
#line 2215 "javaa.tab.c"
    break;

  case 53: /* fieldconstant: %empty  */
#line 586 "javaa.y"
             {(yyval.argtype).type = 0;
             }
#line 2222 "javaa.tab.c"
    break;

  case 54: /* field_modifiers: static_entry final_entry transient_entry volatile_entry  */
#line 592 "javaa.y"
                { (yyval.intval) = (yyvsp[-3].intval) | (yyvsp[-2].intval) | (yyvsp[-1].intval) | (yyvsp[0].intval) ;}
#line 2228 "javaa.tab.c"
    break;

  case 56: /* methodlist: %empty  */
#line 597 "javaa.y"
          {break;}
#line 2234 "javaa.tab.c"
    break;

  case 57: /* $@3: %empty  */
#line 601 "javaa.y"
                                                   {NewNewMethod((yyvsp[-1].intval)|(yyvsp[0].intval));}
#line 2240 "javaa.tab.c"
    break;

  case 58: /* $@4: %empty  */
#line 606 "javaa.y"
          { 
	    char* tmpstr; 
	    /*message("Calling NewMethod.");*/
	    tmpstr = ConsStrings("(",ConsStrings((yyvsp[-5].string),ConsStrings(")",(yyvsp[-8].string))));
	    /*message(tmpstr);*/
	    NewMethod((yyvsp[-7].string), tmpstr, (yyvsp[-1].intval), (yyvsp[0].intval)); }
#line 2251 "javaa.tab.c"
    break;

  case 59: /* method: METHOD access_specifier method_modifiers $@3 returntype IDENTIFIER '(' methodarguments ')' throwslist MAX_STACK INTCONSTANT max_locals_decl $@4 '{' code exceptiontable linenumbertable localvariabletable '}'  */
#line 618 "javaa.y"
                {EndMethod();}
#line 2257 "javaa.tab.c"
    break;

  case 60: /* throwslist: THROWS throwsentries  */
#line 623 "javaa.y"
                {break;}
#line 2263 "javaa.tab.c"
    break;

  case 61: /* throwslist: %empty  */
#line 624 "javaa.y"
                {break;}
#line 2269 "javaa.tab.c"
    break;

  case 62: /* throwsentries: throwsentries classname  */
#line 629 "javaa.y"
                {AddToThrowsList((yyvsp[0].string));}
#line 2275 "javaa.tab.c"
    break;

  case 63: /* throwsentries: classname  */
#line 631 "javaa.y"
                {AddToThrowsList((yyvsp[0].string));}
#line 2281 "javaa.tab.c"
    break;

  case 64: /* max_locals_decl: MAX_LOCALS INTCONSTANT  */
#line 636 "javaa.y"
                {(yyval.intval) = (yyvsp[0].intval);}
#line 2287 "javaa.tab.c"
    break;

  case 65: /* max_locals_decl: %empty  */
#line 637 "javaa.y"
                {(yyval.intval) = -1;}
#line 2293 "javaa.tab.c"
    break;

  case 66: /* returntype: type  */
#line 642 "javaa.y"
                { (yyval.string) = (yyvsp[0].string); }
#line 2299 "javaa.tab.c"
    break;

  case 67: /* returntype: VOID  */
#line 644 "javaa.y"
                { char* tempstring;
	     	  tempstring = (char *) malloc(strlen("B"));
	     	  strcpy(tempstring,"V");
	     	  (yyval.string) = tempstring;
	  	}
#line 2309 "javaa.tab.c"
    break;

  case 68: /* arguments: argumentlist  */
#line 653 "javaa.y"
                { (yyval.string) = (yyvsp[0].string);}
#line 2315 "javaa.tab.c"
    break;

  case 69: /* arguments: %empty  */
#line 654 "javaa.y"
          {(yyval.string) = NULL;}
#line 2321 "javaa.tab.c"
    break;

  case 70: /* argumentlist: type ',' argumentlist  */
#line 658 "javaa.y"
                {
		  /*message("in arguments with comma.");*/
		  (yyval.string) = ConsStrings((yyvsp[-2].string),(yyvsp[0].string));
		}
#line 2330 "javaa.tab.c"
    break;

  case 71: /* argumentlist: type  */
#line 663 "javaa.y"
                { (yyval.string) = (yyvsp[0].string); /*message("in arguments");*/}
#line 2336 "javaa.tab.c"
    break;

  case 72: /* methodarguments: methodargumentlist  */
#line 669 "javaa.y"
                { (yyval.string) = (yyvsp[0].string);}
#line 2342 "javaa.tab.c"
    break;

  case 73: /* methodarguments: %empty  */
#line 670 "javaa.y"
          {(yyval.string) = NULL;}
#line 2348 "javaa.tab.c"
    break;

  case 74: /* methodargumentlist: methodargument ',' methodargumentlist  */
#line 674 "javaa.y"
                {
		  /*message("in arguments with comma.");*/
		  (yyval.string) = ConsStrings((yyvsp[-2].string),(yyvsp[0].string));
		}
#line 2357 "javaa.tab.c"
    break;

  case 75: /* methodargumentlist: methodargument  */
#line 679 "javaa.y"
                { (yyval.string) = (yyvsp[0].string); /*message("in arguments");*/}
#line 2363 "javaa.tab.c"
    break;

  case 76: /* methodargument: type  */
#line 682 "javaa.y"
                { (yyval.string) = (yyvsp[0].string); 
		  /*message("calling IncrementLocalVarSlot");*/
		  IncrementLocalVarSlot((yyvsp[0].string)); /*message("in methodargument");*/}
#line 2371 "javaa.tab.c"
    break;

  case 77: /* methodargument: type IDENTIFIER  */
#line 686 "javaa.y"
                { (yyval.string) = (yyvsp[-1].string); NewLocalVar((yyvsp[0].string), (yyvsp[-1].string));/*message("in methodargument");*/}
#line 2377 "javaa.tab.c"
    break;

  case 78: /* type: basetype arrayadder  */
#line 691 "javaa.y"
                {
		  /*message("In type.");*/
		  (yyval.string) = ConsStrings((yyvsp[0].string),(yyvsp[-1].string));
		}
#line 2386 "javaa.tab.c"
    break;

  case 79: /* basetype: BYTE  */
#line 698 "javaa.y"
                { (yyval.string) = ConsStrings("B",""); }
#line 2392 "javaa.tab.c"
    break;

  case 80: /* basetype: CHAR  */
#line 700 "javaa.y"
                { (yyval.string) = ConsStrings("C",""); }
#line 2398 "javaa.tab.c"
    break;

  case 81: /* basetype: DOUBLE  */
#line 702 "javaa.y"
                { (yyval.string) = ConsStrings("D",""); }
#line 2404 "javaa.tab.c"
    break;

  case 82: /* basetype: FLOAT  */
#line 704 "javaa.y"
                { (yyval.string) = ConsStrings("F",""); }
#line 2410 "javaa.tab.c"
    break;

  case 83: /* basetype: INT  */
#line 706 "javaa.y"
                { (yyval.string) = ConsStrings("I",""); }
#line 2416 "javaa.tab.c"
    break;

  case 84: /* basetype: LONG  */
#line 708 "javaa.y"
                { (yyval.string) = ConsStrings("J",""); }
#line 2422 "javaa.tab.c"
    break;

  case 85: /* basetype: SHORT  */
#line 710 "javaa.y"
                { (yyval.string) = ConsStrings("S",""); }
#line 2428 "javaa.tab.c"
    break;

  case 86: /* basetype: BOOLEAN  */
#line 712 "javaa.y"
                { (yyval.string) = ConsStrings("Z",""); }
#line 2434 "javaa.tab.c"
    break;

  case 87: /* basetype: classname  */
#line 714 "javaa.y"
                {
		 (yyval.string) = ConsStrings("L", ConsStrings((yyvsp[0].string),";"));
	   	 /*message($$);*/
		 /*message("Got classname.");*/}
#line 2443 "javaa.tab.c"
    break;

  case 88: /* arrayadder: '[' ']' arrayadder  */
#line 722 "javaa.y"
                {(yyval.string) = ConsStrings("[",(yyvsp[0].string));}
#line 2449 "javaa.tab.c"
    break;

  case 89: /* arrayadder: %empty  */
#line 723 "javaa.y"
          {(yyval.string)=NULL;}
#line 2455 "javaa.tab.c"
    break;

  case 90: /* method_modifiers: static_entry abstract_entry final_entry native_entry synchronized_entry  */
#line 729 "javaa.y"
                { (yyval.intval) = (yyvsp[-4].intval) | (yyvsp[-3].intval) | (yyvsp[-2].intval) | (yyvsp[-1].intval) | (yyvsp[0].intval);}
#line 2461 "javaa.tab.c"
    break;

  case 91: /* localvar: type IDENTIFIER  */
#line 733 "javaa.y"
                {NewLocalVar((yyvsp[0].string), (yyvsp[-1].string));}
#line 2467 "javaa.tab.c"
    break;

  case 92: /* arrayorclassname: classname  */
#line 738 "javaa.y"
                {(yyval.string) = (yyvsp[0].string);}
#line 2473 "javaa.tab.c"
    break;

  case 93: /* arrayorclassname: basetype '[' ']' arrayadder  */
#line 740 "javaa.y"
                {(yyval.string) = ConsStrings("[",ConsStrings((yyvsp[0].string),(yyvsp[-3].string)));}
#line 2479 "javaa.tab.c"
    break;

  case 94: /* code: op_list  */
#line 745 "javaa.y"
                {break;}
#line 2485 "javaa.tab.c"
    break;

  case 95: /* op_list: op_list op_line  */
#line 749 "javaa.y"
                {break;}
#line 2491 "javaa.tab.c"
    break;

  case 96: /* op_list: %empty  */
#line 751 "javaa.y"
                {break;}
#line 2497 "javaa.tab.c"
    break;

  case 97: /* op_line: label op  */
#line 755 "javaa.y"
                {break;}
#line 2503 "javaa.tab.c"
    break;

  case 98: /* op_line: op  */
#line 757 "javaa.y"
                {break;}
#line 2509 "javaa.tab.c"
    break;

  case 99: /* op_line: localvar  */
#line 759 "javaa.y"
                {break;}
#line 2515 "javaa.tab.c"
    break;

  case 100: /* op_line: label localvar  */
#line 761 "javaa.y"
                {break;}
#line 2521 "javaa.tab.c"
    break;

  case 101: /* label: LABEL  */
#line 765 "javaa.y"
                {DefineLabel((yyvsp[0].string));}
#line 2527 "javaa.tab.c"
    break;

  case 102: /* op: no_arg_op  */
#line 769 "javaa.y"
                {GenNoArgCode((yyvsp[0].intval));
		}
#line 2534 "javaa.tab.c"
    break;

  case 103: /* op: one_arg_op argument  */
#line 772 "javaa.y"
                {GenOneArgCode((yyvsp[-1].intval), (yyvsp[0].argtype));
		}
#line 2541 "javaa.tab.c"
    break;

  case 104: /* op: fieldref_arg_op type classfieldmethodname  */
#line 775 "javaa.y"
                {GenFieldArgCode((yyvsp[-2].intval), (yyvsp[0].classfieldmethodstruct).classname, (yyvsp[0].classfieldmethodstruct).fieldmethodname, (yyvsp[-1].string));
		}
#line 2548 "javaa.tab.c"
    break;

  case 105: /* op: methodref_arg_op returntype classfieldmethodname '(' arguments ')'  */
#line 779 "javaa.y"
                {GenMethodArgCode((yyvsp[-5].intval), (yyvsp[-3].classfieldmethodstruct).classname, (yyvsp[-3].classfieldmethodstruct).fieldmethodname,
		         	 ConsStrings("(",ConsStrings((yyvsp[-1].string),
				   ConsStrings(")",(yyvsp[-4].string))))); 
		}
#line 2557 "javaa.tab.c"
    break;

  case 106: /* op: class_arg_op classname  */
#line 784 "javaa.y"
                {GenClassArgCode((yyvsp[-1].intval), (yyvsp[0].string));
		}
#line 2564 "javaa.tab.c"
    break;

  case 107: /* op: ANEWARRAY arrayorclassname  */
#line 787 "javaa.y"
                {GenClassArgCode((yyvsp[-1].Rk).terminal, (yyvsp[0].string));
		}
#line 2571 "javaa.tab.c"
    break;

  case 108: /* op: INVOKEINTERFACE returntype classfieldmethodname '(' arguments ')' INTCONSTANT  */
#line 791 "javaa.y"
                {GenINVOKEINTERFACECode((yyvsp[-6].Rk).terminal, (yyvsp[-4].classfieldmethodstruct).classname,
				 (yyvsp[-4].classfieldmethodstruct).fieldmethodname,
		         	 ConsStrings("(",ConsStrings((yyvsp[-2].string),
				   ConsStrings(")",(yyvsp[-5].string)))), (yyvsp[0].intval)); 
		}
#line 2581 "javaa.tab.c"
    break;

  case 109: /* op: label_arg_op IDENTIFIER  */
#line 797 "javaa.y"
                {GenLabelArgCode((yyvsp[-1].intval), (yyvsp[0].string));
		}
#line 2588 "javaa.tab.c"
    break;

  case 110: /* op: localvar_arg_op localvar_arg  */
#line 800 "javaa.y"
                {GenLocalVarArgCode((yyvsp[-1].intval),(yyvsp[0].intval));
		}
#line 2595 "javaa.tab.c"
    break;

  case 111: /* op: IINC localvar_arg INTCONSTANT  */
#line 803 "javaa.y"
                {GenIINCCode((yyvsp[-2].Rk).terminal,(yyvsp[-1].intval),(yyvsp[0].intval));
		}
#line 2602 "javaa.tab.c"
    break;

  case 112: /* op: LOOKUPSWITCH DEFAULT IDENTIFIER '{' lookuplist '}'  */
#line 806 "javaa.y"
                {GenLOOKUPSWITCHCode((yyvsp[-5].Rk).terminal,(yyvsp[-3].string),(yyvsp[-1].lookuplistptr));
		}
#line 2609 "javaa.tab.c"
    break;

  case 113: /* op: TABLESWITCH INTCONSTANT TO INTCONSTANT DEFAULT IDENTIFIER '{' tablelist '}'  */
#line 810 "javaa.y"
                {GenTABLESWITCHCode((yyvsp[-8].Rk).terminal,(yyvsp[-7].intval),(yyvsp[-5].intval),(yyvsp[-3].string),(yyvsp[-1].tablelistptr));
		}
#line 2616 "javaa.tab.c"
    break;

  case 114: /* op: MULTIANEWARRAY arrayorclassname INTCONSTANT  */
#line 813 "javaa.y"
                {GenMULTIANEWARRAYCode((yyvsp[-2].Rk).terminal,(yyvsp[-1].string),(yyvsp[0].intval));
		}
#line 2623 "javaa.tab.c"
    break;

  case 115: /* op: NEWARRAY newarraytype  */
#line 816 "javaa.y"
                {GenNEWARRAYCode((yyvsp[-1].Rk).terminal,(yyvsp[0].intval));
		}
#line 2630 "javaa.tab.c"
    break;

  case 116: /* no_arg_op: AALOAD  */
#line 821 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2636 "javaa.tab.c"
    break;

  case 117: /* no_arg_op: AASTORE  */
#line 823 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2642 "javaa.tab.c"
    break;

  case 118: /* no_arg_op: ACONST_NULL  */
#line 825 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2648 "javaa.tab.c"
    break;

  case 119: /* no_arg_op: ALOAD_0  */
#line 827 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2654 "javaa.tab.c"
    break;

  case 120: /* no_arg_op: ALOAD_1  */
#line 829 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2660 "javaa.tab.c"
    break;

  case 121: /* no_arg_op: ALOAD_2  */
#line 831 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2666 "javaa.tab.c"
    break;

  case 122: /* no_arg_op: ALOAD_3  */
#line 833 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2672 "javaa.tab.c"
    break;

  case 123: /* no_arg_op: ARETURN  */
#line 835 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2678 "javaa.tab.c"
    break;

  case 124: /* no_arg_op: ARRAYLENGTH  */
#line 837 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2684 "javaa.tab.c"
    break;

  case 125: /* no_arg_op: ASTORE_0  */
#line 839 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2690 "javaa.tab.c"
    break;

  case 126: /* no_arg_op: ASTORE_1  */
#line 841 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2696 "javaa.tab.c"
    break;

  case 127: /* no_arg_op: ASTORE_2  */
#line 843 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2702 "javaa.tab.c"
    break;

  case 128: /* no_arg_op: ASTORE_3  */
#line 845 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2708 "javaa.tab.c"
    break;

  case 129: /* no_arg_op: ATHROW  */
#line 847 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2714 "javaa.tab.c"
    break;

  case 130: /* no_arg_op: BALOAD  */
#line 849 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2720 "javaa.tab.c"
    break;

  case 131: /* no_arg_op: BASTORE  */
#line 851 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2726 "javaa.tab.c"
    break;

  case 132: /* no_arg_op: CALOAD  */
#line 853 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2732 "javaa.tab.c"
    break;

  case 133: /* no_arg_op: CASTORE  */
#line 855 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2738 "javaa.tab.c"
    break;

  case 134: /* no_arg_op: D2F  */
#line 857 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2744 "javaa.tab.c"
    break;

  case 135: /* no_arg_op: D2I  */
#line 859 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2750 "javaa.tab.c"
    break;

  case 136: /* no_arg_op: D2L  */
#line 861 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2756 "javaa.tab.c"
    break;

  case 137: /* no_arg_op: DADD  */
#line 863 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2762 "javaa.tab.c"
    break;

  case 138: /* no_arg_op: DALOAD  */
#line 865 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2768 "javaa.tab.c"
    break;

  case 139: /* no_arg_op: DASTORE  */
#line 867 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2774 "javaa.tab.c"
    break;

  case 140: /* no_arg_op: DCMPG  */
#line 869 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2780 "javaa.tab.c"
    break;

  case 141: /* no_arg_op: DCMPL  */
#line 871 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2786 "javaa.tab.c"
    break;

  case 142: /* no_arg_op: DCONST_0  */
#line 873 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2792 "javaa.tab.c"
    break;

  case 143: /* no_arg_op: DCONST_1  */
#line 875 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2798 "javaa.tab.c"
    break;

  case 144: /* no_arg_op: DDIV  */
#line 877 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2804 "javaa.tab.c"
    break;

  case 145: /* no_arg_op: DLOAD_0  */
#line 879 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2810 "javaa.tab.c"
    break;

  case 146: /* no_arg_op: DLOAD_1  */
#line 881 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2816 "javaa.tab.c"
    break;

  case 147: /* no_arg_op: DLOAD_2  */
#line 883 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2822 "javaa.tab.c"
    break;

  case 148: /* no_arg_op: DLOAD_3  */
#line 885 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2828 "javaa.tab.c"
    break;

  case 149: /* no_arg_op: DMUL  */
#line 887 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2834 "javaa.tab.c"
    break;

  case 150: /* no_arg_op: DNEG  */
#line 889 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2840 "javaa.tab.c"
    break;

  case 151: /* no_arg_op: DREM  */
#line 891 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2846 "javaa.tab.c"
    break;

  case 152: /* no_arg_op: DRETURN  */
#line 893 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2852 "javaa.tab.c"
    break;

  case 153: /* no_arg_op: DSTORE_0  */
#line 895 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2858 "javaa.tab.c"
    break;

  case 154: /* no_arg_op: DSTORE_1  */
#line 897 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2864 "javaa.tab.c"
    break;

  case 155: /* no_arg_op: DSTORE_2  */
#line 899 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2870 "javaa.tab.c"
    break;

  case 156: /* no_arg_op: DSTORE_3  */
#line 901 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2876 "javaa.tab.c"
    break;

  case 157: /* no_arg_op: DSUB  */
#line 903 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2882 "javaa.tab.c"
    break;

  case 158: /* no_arg_op: DUP  */
#line 905 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2888 "javaa.tab.c"
    break;

  case 159: /* no_arg_op: DUP_X1  */
#line 907 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2894 "javaa.tab.c"
    break;

  case 160: /* no_arg_op: DUP_X2  */
#line 909 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2900 "javaa.tab.c"
    break;

  case 161: /* no_arg_op: DUP2  */
#line 911 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2906 "javaa.tab.c"
    break;

  case 162: /* no_arg_op: DUP2_X1  */
#line 913 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2912 "javaa.tab.c"
    break;

  case 163: /* no_arg_op: DUP2_X2  */
#line 915 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2918 "javaa.tab.c"
    break;

  case 164: /* no_arg_op: F2D  */
#line 917 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2924 "javaa.tab.c"
    break;

  case 165: /* no_arg_op: F2I  */
#line 919 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2930 "javaa.tab.c"
    break;

  case 166: /* no_arg_op: F2L  */
#line 921 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2936 "javaa.tab.c"
    break;

  case 167: /* no_arg_op: FADD  */
#line 923 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2942 "javaa.tab.c"
    break;

  case 168: /* no_arg_op: FALOAD  */
#line 925 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2948 "javaa.tab.c"
    break;

  case 169: /* no_arg_op: FASTORE  */
#line 927 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2954 "javaa.tab.c"
    break;

  case 170: /* no_arg_op: FCMPG  */
#line 929 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2960 "javaa.tab.c"
    break;

  case 171: /* no_arg_op: FCMPL  */
#line 931 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2966 "javaa.tab.c"
    break;

  case 172: /* no_arg_op: FCONST_0  */
#line 933 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2972 "javaa.tab.c"
    break;

  case 173: /* no_arg_op: FCONST_1  */
#line 935 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2978 "javaa.tab.c"
    break;

  case 174: /* no_arg_op: FCONST_2  */
#line 937 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2984 "javaa.tab.c"
    break;

  case 175: /* no_arg_op: FDIV  */
#line 939 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2990 "javaa.tab.c"
    break;

  case 176: /* no_arg_op: FLOAD_0  */
#line 941 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 2996 "javaa.tab.c"
    break;

  case 177: /* no_arg_op: FLOAD_1  */
#line 943 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3002 "javaa.tab.c"
    break;

  case 178: /* no_arg_op: FLOAD_2  */
#line 945 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3008 "javaa.tab.c"
    break;

  case 179: /* no_arg_op: FLOAD_3  */
#line 947 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3014 "javaa.tab.c"
    break;

  case 180: /* no_arg_op: FMUL  */
#line 949 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3020 "javaa.tab.c"
    break;

  case 181: /* no_arg_op: FNEG  */
#line 951 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3026 "javaa.tab.c"
    break;

  case 182: /* no_arg_op: FREM  */
#line 953 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3032 "javaa.tab.c"
    break;

  case 183: /* no_arg_op: FRETURN  */
#line 955 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3038 "javaa.tab.c"
    break;

  case 184: /* no_arg_op: FSTORE_0  */
#line 957 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3044 "javaa.tab.c"
    break;

  case 185: /* no_arg_op: FSTORE_1  */
#line 959 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3050 "javaa.tab.c"
    break;

  case 186: /* no_arg_op: FSTORE_2  */
#line 961 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3056 "javaa.tab.c"
    break;

  case 187: /* no_arg_op: FSTORE_3  */
#line 963 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3062 "javaa.tab.c"
    break;

  case 188: /* no_arg_op: FSUB  */
#line 965 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3068 "javaa.tab.c"
    break;

  case 189: /* no_arg_op: I2B  */
#line 967 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3074 "javaa.tab.c"
    break;

  case 190: /* no_arg_op: I2C  */
#line 969 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3080 "javaa.tab.c"
    break;

  case 191: /* no_arg_op: I2D  */
#line 971 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3086 "javaa.tab.c"
    break;

  case 192: /* no_arg_op: I2F  */
#line 973 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3092 "javaa.tab.c"
    break;

  case 193: /* no_arg_op: I2L  */
#line 975 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3098 "javaa.tab.c"
    break;

  case 194: /* no_arg_op: I2S  */
#line 977 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3104 "javaa.tab.c"
    break;

  case 195: /* no_arg_op: IADD  */
#line 979 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3110 "javaa.tab.c"
    break;

  case 196: /* no_arg_op: IALOAD  */
#line 981 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3116 "javaa.tab.c"
    break;

  case 197: /* no_arg_op: IAND  */
#line 983 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3122 "javaa.tab.c"
    break;

  case 198: /* no_arg_op: IASTORE  */
#line 985 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3128 "javaa.tab.c"
    break;

  case 199: /* no_arg_op: ICONST_0  */
#line 987 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3134 "javaa.tab.c"
    break;

  case 200: /* no_arg_op: ICONST_1  */
#line 989 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3140 "javaa.tab.c"
    break;

  case 201: /* no_arg_op: ICONST_2  */
#line 991 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3146 "javaa.tab.c"
    break;

  case 202: /* no_arg_op: ICONST_3  */
#line 993 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3152 "javaa.tab.c"
    break;

  case 203: /* no_arg_op: ICONST_4  */
#line 995 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3158 "javaa.tab.c"
    break;

  case 204: /* no_arg_op: ICONST_5  */
#line 997 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3164 "javaa.tab.c"
    break;

  case 205: /* no_arg_op: ICONST_M1  */
#line 999 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3170 "javaa.tab.c"
    break;

  case 206: /* no_arg_op: IDIV  */
#line 1001 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3176 "javaa.tab.c"
    break;

  case 207: /* no_arg_op: ILOAD_0  */
#line 1003 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3182 "javaa.tab.c"
    break;

  case 208: /* no_arg_op: ILOAD_1  */
#line 1005 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3188 "javaa.tab.c"
    break;

  case 209: /* no_arg_op: ILOAD_2  */
#line 1007 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3194 "javaa.tab.c"
    break;

  case 210: /* no_arg_op: ILOAD_3  */
#line 1009 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3200 "javaa.tab.c"
    break;

  case 211: /* no_arg_op: IMUL  */
#line 1011 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3206 "javaa.tab.c"
    break;

  case 212: /* no_arg_op: INEG  */
#line 1013 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3212 "javaa.tab.c"
    break;

  case 213: /* no_arg_op: IOR  */
#line 1015 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3218 "javaa.tab.c"
    break;

  case 214: /* no_arg_op: IREM  */
#line 1017 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3224 "javaa.tab.c"
    break;

  case 215: /* no_arg_op: IRETURN  */
#line 1019 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3230 "javaa.tab.c"
    break;

  case 216: /* no_arg_op: ISHL  */
#line 1021 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3236 "javaa.tab.c"
    break;

  case 217: /* no_arg_op: ISHR  */
#line 1023 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3242 "javaa.tab.c"
    break;

  case 218: /* no_arg_op: ISTORE_0  */
#line 1025 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3248 "javaa.tab.c"
    break;

  case 219: /* no_arg_op: ISTORE_1  */
#line 1027 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3254 "javaa.tab.c"
    break;

  case 220: /* no_arg_op: ISTORE_2  */
#line 1029 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3260 "javaa.tab.c"
    break;

  case 221: /* no_arg_op: ISTORE_3  */
#line 1031 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3266 "javaa.tab.c"
    break;

  case 222: /* no_arg_op: ISUB  */
#line 1033 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3272 "javaa.tab.c"
    break;

  case 223: /* no_arg_op: IUSHR  */
#line 1035 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3278 "javaa.tab.c"
    break;

  case 224: /* no_arg_op: IXOR  */
#line 1037 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3284 "javaa.tab.c"
    break;

  case 225: /* no_arg_op: L2D  */
#line 1039 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3290 "javaa.tab.c"
    break;

  case 226: /* no_arg_op: L2F  */
#line 1041 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3296 "javaa.tab.c"
    break;

  case 227: /* no_arg_op: L2I  */
#line 1043 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3302 "javaa.tab.c"
    break;

  case 228: /* no_arg_op: LADD  */
#line 1045 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3308 "javaa.tab.c"
    break;

  case 229: /* no_arg_op: LALOAD  */
#line 1047 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3314 "javaa.tab.c"
    break;

  case 230: /* no_arg_op: LAND  */
#line 1049 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3320 "javaa.tab.c"
    break;

  case 231: /* no_arg_op: LASTORE  */
#line 1051 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3326 "javaa.tab.c"
    break;

  case 232: /* no_arg_op: LCMP  */
#line 1053 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3332 "javaa.tab.c"
    break;

  case 233: /* no_arg_op: LCONST_0  */
#line 1055 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3338 "javaa.tab.c"
    break;

  case 234: /* no_arg_op: LCONST_1  */
#line 1057 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3344 "javaa.tab.c"
    break;

  case 235: /* no_arg_op: LDIV  */
#line 1059 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3350 "javaa.tab.c"
    break;

  case 236: /* no_arg_op: LLOAD_0  */
#line 1061 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3356 "javaa.tab.c"
    break;

  case 237: /* no_arg_op: LLOAD_1  */
#line 1063 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3362 "javaa.tab.c"
    break;

  case 238: /* no_arg_op: LLOAD_2  */
#line 1065 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3368 "javaa.tab.c"
    break;

  case 239: /* no_arg_op: LLOAD_3  */
#line 1067 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3374 "javaa.tab.c"
    break;

  case 240: /* no_arg_op: LMUL  */
#line 1069 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3380 "javaa.tab.c"
    break;

  case 241: /* no_arg_op: LNEG  */
#line 1071 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3386 "javaa.tab.c"
    break;

  case 242: /* no_arg_op: LOR  */
#line 1073 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3392 "javaa.tab.c"
    break;

  case 243: /* no_arg_op: LREM  */
#line 1075 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3398 "javaa.tab.c"
    break;

  case 244: /* no_arg_op: LRETURN  */
#line 1077 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3404 "javaa.tab.c"
    break;

  case 245: /* no_arg_op: LSHL  */
#line 1079 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3410 "javaa.tab.c"
    break;

  case 246: /* no_arg_op: LSHR  */
#line 1081 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3416 "javaa.tab.c"
    break;

  case 247: /* no_arg_op: LSTORE_0  */
#line 1083 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3422 "javaa.tab.c"
    break;

  case 248: /* no_arg_op: LSTORE_1  */
#line 1085 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3428 "javaa.tab.c"
    break;

  case 249: /* no_arg_op: LSTORE_2  */
#line 1087 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3434 "javaa.tab.c"
    break;

  case 250: /* no_arg_op: LSTORE_3  */
#line 1089 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3440 "javaa.tab.c"
    break;

  case 251: /* no_arg_op: LSUB  */
#line 1091 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3446 "javaa.tab.c"
    break;

  case 252: /* no_arg_op: LUSHR  */
#line 1093 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3452 "javaa.tab.c"
    break;

  case 253: /* no_arg_op: LXOR  */
#line 1095 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3458 "javaa.tab.c"
    break;

  case 254: /* no_arg_op: MONITORENTER  */
#line 1097 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3464 "javaa.tab.c"
    break;

  case 255: /* no_arg_op: MONITOREXIT  */
#line 1099 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3470 "javaa.tab.c"
    break;

  case 256: /* no_arg_op: NOP  */
#line 1101 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3476 "javaa.tab.c"
    break;

  case 257: /* no_arg_op: POP  */
#line 1103 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3482 "javaa.tab.c"
    break;

  case 258: /* no_arg_op: POP2  */
#line 1105 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3488 "javaa.tab.c"
    break;

  case 259: /* no_arg_op: RETURN  */
#line 1107 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3494 "javaa.tab.c"
    break;

  case 260: /* no_arg_op: SALOAD  */
#line 1109 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3500 "javaa.tab.c"
    break;

  case 261: /* no_arg_op: SASTORE  */
#line 1111 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3506 "javaa.tab.c"
    break;

  case 262: /* no_arg_op: SWAP  */
#line 1113 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3512 "javaa.tab.c"
    break;

  case 263: /* no_arg_op: WIDE  */
#line 1115 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3518 "javaa.tab.c"
    break;

  case 264: /* one_arg_op: BIPUSH  */
#line 1119 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3524 "javaa.tab.c"
    break;

  case 265: /* one_arg_op: LDC  */
#line 1121 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3530 "javaa.tab.c"
    break;

  case 266: /* one_arg_op: LDC_W  */
#line 1123 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3536 "javaa.tab.c"
    break;

  case 267: /* one_arg_op: LDC2_W  */
#line 1125 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3542 "javaa.tab.c"
    break;

  case 268: /* one_arg_op: SIPUSH  */
#line 1127 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3548 "javaa.tab.c"
    break;

  case 269: /* methodref_arg_op: INVOKESTATIC  */
#line 1133 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3554 "javaa.tab.c"
    break;

  case 270: /* methodref_arg_op: INVOKENONVIRTUAL  */
#line 1135 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3560 "javaa.tab.c"
    break;

  case 271: /* methodref_arg_op: INVOKEVIRTUAL  */
#line 1137 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3566 "javaa.tab.c"
    break;

  case 272: /* fieldref_arg_op: GETFIELD  */
#line 1142 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3572 "javaa.tab.c"
    break;

  case 273: /* fieldref_arg_op: GETSTATIC  */
#line 1144 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3578 "javaa.tab.c"
    break;

  case 274: /* fieldref_arg_op: PUTFIELD  */
#line 1146 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3584 "javaa.tab.c"
    break;

  case 275: /* fieldref_arg_op: PUTSTATIC  */
#line 1148 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3590 "javaa.tab.c"
    break;

  case 276: /* class_arg_op: CHECKCAST  */
#line 1153 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3596 "javaa.tab.c"
    break;

  case 277: /* class_arg_op: INSTANCEOF  */
#line 1155 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3602 "javaa.tab.c"
    break;

  case 278: /* class_arg_op: NEW  */
#line 1157 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3608 "javaa.tab.c"
    break;

  case 279: /* label_arg_op: GOTO  */
#line 1161 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3614 "javaa.tab.c"
    break;

  case 280: /* label_arg_op: GOTO_W  */
#line 1163 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3620 "javaa.tab.c"
    break;

  case 281: /* label_arg_op: IF_ACMPEQ  */
#line 1165 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3626 "javaa.tab.c"
    break;

  case 282: /* label_arg_op: IF_ACMPNE  */
#line 1167 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3632 "javaa.tab.c"
    break;

  case 283: /* label_arg_op: IF_ICMPEQ  */
#line 1169 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3638 "javaa.tab.c"
    break;

  case 284: /* label_arg_op: IF_ICMPNE  */
#line 1171 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3644 "javaa.tab.c"
    break;

  case 285: /* label_arg_op: IF_ICMPLT  */
#line 1173 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3650 "javaa.tab.c"
    break;

  case 286: /* label_arg_op: IF_ICMPGE  */
#line 1175 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3656 "javaa.tab.c"
    break;

  case 287: /* label_arg_op: IF_ICMPGT  */
#line 1177 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3662 "javaa.tab.c"
    break;

  case 288: /* label_arg_op: IF_ICMPLE  */
#line 1179 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3668 "javaa.tab.c"
    break;

  case 289: /* label_arg_op: IFEQ  */
#line 1181 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3674 "javaa.tab.c"
    break;

  case 290: /* label_arg_op: IFNE  */
#line 1183 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3680 "javaa.tab.c"
    break;

  case 291: /* label_arg_op: IFLT  */
#line 1185 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3686 "javaa.tab.c"
    break;

  case 292: /* label_arg_op: IFGE  */
#line 1187 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3692 "javaa.tab.c"
    break;

  case 293: /* label_arg_op: IFGT  */
#line 1189 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3698 "javaa.tab.c"
    break;

  case 294: /* label_arg_op: IFLE  */
#line 1191 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3704 "javaa.tab.c"
    break;

  case 295: /* label_arg_op: IFNONNULL  */
#line 1193 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3710 "javaa.tab.c"
    break;

  case 296: /* label_arg_op: IFNULL  */
#line 1195 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3716 "javaa.tab.c"
    break;

  case 297: /* label_arg_op: JSR  */
#line 1197 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3722 "javaa.tab.c"
    break;

  case 298: /* label_arg_op: JSR_W  */
#line 1199 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3728 "javaa.tab.c"
    break;

  case 299: /* localvar_arg_op: ILOAD  */
#line 1204 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3734 "javaa.tab.c"
    break;

  case 300: /* localvar_arg_op: FLOAD  */
#line 1206 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3740 "javaa.tab.c"
    break;

  case 301: /* localvar_arg_op: ALOAD  */
#line 1208 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3746 "javaa.tab.c"
    break;

  case 302: /* localvar_arg_op: LLOAD  */
#line 1210 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3752 "javaa.tab.c"
    break;

  case 303: /* localvar_arg_op: DLOAD  */
#line 1212 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3758 "javaa.tab.c"
    break;

  case 304: /* localvar_arg_op: ISTORE  */
#line 1214 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3764 "javaa.tab.c"
    break;

  case 305: /* localvar_arg_op: FSTORE  */
#line 1216 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3770 "javaa.tab.c"
    break;

  case 306: /* localvar_arg_op: ASTORE  */
#line 1218 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3776 "javaa.tab.c"
    break;

  case 307: /* localvar_arg_op: LSTORE  */
#line 1220 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3782 "javaa.tab.c"
    break;

  case 308: /* localvar_arg_op: DSTORE  */
#line 1222 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3788 "javaa.tab.c"
    break;

  case 309: /* localvar_arg_op: RET  */
#line 1224 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3794 "javaa.tab.c"
    break;

  case 310: /* localvar_arg_op: LOAD  */
#line 1226 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3800 "javaa.tab.c"
    break;

  case 311: /* localvar_arg_op: STORE  */
#line 1228 "javaa.y"
                {(yyval.intval)=(yyvsp[0].Rk).terminal;}
#line 3806 "javaa.tab.c"
    break;

  case 312: /* localvar_arg: INTCONSTANT  */
#line 1232 "javaa.y"
                { (yyval.intval) = (yyvsp[0].intval);}
#line 3812 "javaa.tab.c"
    break;

  case 313: /* localvar_arg: IDENTIFIER  */
#line 1234 "javaa.y"
                { (yyval.intval) = GetLocalVar((yyvsp[0].string));}
#line 3818 "javaa.tab.c"
    break;

  case 314: /* lookuplist: INTCONSTANT ':' IDENTIFIER lookuplist  */
#line 1238 "javaa.y"
                { (yyval.lookuplistptr) = AddToLookupList((yyvsp[0].lookuplistptr),(yyvsp[-3].intval),(yyvsp[-1].string)); }
#line 3824 "javaa.tab.c"
    break;

  case 315: /* lookuplist: %empty  */
#line 1239 "javaa.y"
                {(yyval.lookuplistptr) = NULL;}
#line 3830 "javaa.tab.c"
    break;

  case 316: /* tablelist: IDENTIFIER tablelist  */
#line 1243 "javaa.y"
                { (yyval.tablelistptr) = AddToTableList((yyvsp[0].tablelistptr),(yyvsp[-1].string)); }
#line 3836 "javaa.tab.c"
    break;

  case 317: /* tablelist: %empty  */
#line 1244 "javaa.y"
                {(yyval.tablelistptr) = NULL;}
#line 3842 "javaa.tab.c"
    break;

  case 318: /* newarraytype: BOOLEAN  */
#line 1249 "javaa.y"
                { (yyval.intval) = 4;}
#line 3848 "javaa.tab.c"
    break;

  case 319: /* newarraytype: CHAR  */
#line 1251 "javaa.y"
                { (yyval.intval) = 5;}
#line 3854 "javaa.tab.c"
    break;

  case 320: /* newarraytype: FLOAT  */
#line 1253 "javaa.y"
                { (yyval.intval) = 6;}
#line 3860 "javaa.tab.c"
    break;

  case 321: /* newarraytype: DOUBLE  */
#line 1255 "javaa.y"
                { (yyval.intval) = 7;}
#line 3866 "javaa.tab.c"
    break;

  case 322: /* newarraytype: BYTE  */
#line 1257 "javaa.y"
                { (yyval.intval) = 8;}
#line 3872 "javaa.tab.c"
    break;

  case 323: /* newarraytype: SHORT  */
#line 1259 "javaa.y"
                { (yyval.intval) = 9;}
#line 3878 "javaa.tab.c"
    break;

  case 324: /* newarraytype: INT  */
#line 1261 "javaa.y"
                { (yyval.intval) = 10;}
#line 3884 "javaa.tab.c"
    break;

  case 325: /* newarraytype: LONG  */
#line 1263 "javaa.y"
                { (yyval.intval) = 11;}
#line 3890 "javaa.tab.c"
    break;

  case 326: /* argument: IDENTIFIER  */
#line 1267 "javaa.y"
             {(yyval.argtype).type = IDENTIFIER;
              (yyval.argtype).stringval = (yyvsp[0].string);
             }
#line 3898 "javaa.tab.c"
    break;

  case 327: /* argument: INTCONSTANT  */
#line 1271 "javaa.y"
             {(yyval.argtype).type = INTCONSTANT;
              (yyval.argtype).intval = (yyvsp[0].intval);
             }
#line 3906 "javaa.tab.c"
    break;

  case 328: /* argument: LONGCONSTANT  */
#line 1275 "javaa.y"
             {(yyval.argtype).type = LONGCONSTANT;
              (yyval.argtype).longval = (yyvsp[0].longval);
             }
#line 3914 "javaa.tab.c"
    break;

  case 329: /* argument: STRING_LITERAL  */
#line 1279 "javaa.y"
             {(yyval.argtype).type = STRING_LITERAL;
              (yyval.argtype).stringval = (yyvsp[0].string);
             }
#line 3922 "javaa.tab.c"
    break;

  case 330: /* argument: FLOATCONSTANT  */
#line 1283 "javaa.y"
             {(yyval.argtype).type = FLOATCONSTANT;
              (yyval.argtype).floatval = (yyvsp[0].floatval);
	      /*message("got a float constant.");*/
             }
#line 3931 "javaa.tab.c"
    break;

  case 331: /* argument: DOUBLECONSTANT  */
#line 1288 "javaa.y"
             {(yyval.argtype).type = DOUBLECONSTANT;
              (yyval.argtype).doubleval = (yyvsp[0].doubleval);
	      /*message("got a double constant.");*/
             }
#line 3940 "javaa.tab.c"
    break;

  case 332: /* exceptiontable: EXCEPTIONS '{' exceptionslist '}'  */
#line 1296 "javaa.y"
                { break; }
#line 3946 "javaa.tab.c"
    break;

  case 333: /* exceptiontable: %empty  */
#line 1297 "javaa.y"
          {break;}
#line 3952 "javaa.tab.c"
    break;

  case 334: /* exceptionslist: exceptionslist IDENTIFIER IDENTIFIER IDENTIFIER classname  */
#line 1301 "javaa.y"
                { AddToExceptionList((yyvsp[-3].string),(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].string)); }
#line 3958 "javaa.tab.c"
    break;

  case 335: /* exceptionslist: exceptionslist IDENTIFIER IDENTIFIER IDENTIFIER INTCONSTANT  */
#line 1303 "javaa.y"
                { 
		  if ((yyvsp[0].intval) != 0) oops("Must have a class name or 0 here.");
	          AddToExceptionList((yyvsp[-3].string),(yyvsp[-2].string),(yyvsp[-1].string),NULL); 
		}
#line 3967 "javaa.tab.c"
    break;

  case 336: /* exceptionslist: %empty  */
#line 1307 "javaa.y"
                {break;}
#line 3973 "javaa.tab.c"
    break;

  case 337: /* linenumbertable: LINENUMBERTABLE '{' linenumberlist '}'  */
#line 1312 "javaa.y"
                { break; }
#line 3979 "javaa.tab.c"
    break;

  case 338: /* linenumbertable: %empty  */
#line 1313 "javaa.y"
          {break;}
#line 3985 "javaa.tab.c"
    break;

  case 339: /* linenumberlist: linenumberlist IDENTIFIER INTCONSTANT  */
#line 1317 "javaa.y"
                { AddToLineNumberList((yyvsp[-1].string),(yyvsp[0].intval)); }
#line 3991 "javaa.tab.c"
    break;

  case 340: /* linenumberlist: %empty  */
#line 1318 "javaa.y"
                {break;}
#line 3997 "javaa.tab.c"
    break;

  case 341: /* localvariabletable: LOCALVARIABLETABLE '{' localvariablelist '}'  */
#line 1323 "javaa.y"
                { break; }
#line 4003 "javaa.tab.c"
    break;

  case 342: /* localvariabletable: %empty  */
#line 1324 "javaa.y"
          {break;}
#line 4009 "javaa.tab.c"
    break;

  case 343: /* localvariablelist: localvariablelist IDENTIFIER IDENTIFIER type IDENTIFIER INTCONSTANT  */
#line 1329 "javaa.y"
                { AddToUserLocalVarList((yyvsp[-4].string),(yyvsp[-3].string),(yyvsp[-2].string),(yyvsp[-1].string),(yyvsp[0].intval)); }
#line 4015 "javaa.tab.c"
    break;

  case 344: /* localvariablelist: %empty  */
#line 1330 "javaa.y"
                {break;}
#line 4021 "javaa.tab.c"
    break;

  case 345: /* sourcefilename: SOURCEFILE STRING_LITERAL  */
#line 1335 "javaa.y"
                { SetSourceFile((yyvsp[0].string)); }
#line 4027 "javaa.tab.c"
    break;

  case 346: /* sourcefilename: %empty  */
#line 1336 "javaa.y"
                {break;}
#line 4033 "javaa.tab.c"
    break;


#line 4037 "javaa.tab.c"

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

#line 1338 "javaa.y"

