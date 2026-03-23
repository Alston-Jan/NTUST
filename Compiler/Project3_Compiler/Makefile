# Compiler and tools
CC = gcc
LEX = flex
YACC = bison -d

# Files
LEX_SRC = Project3.l
YACC_SRC = parser.y
YACC_HDR = parser.tab.h
YACC_C   = parser.tab.c
LEX_C   = lex.yy.c

OBJS = $(YACC_C) $(LEX_C) codegen.o symboltable.o
EXEC = compiler

# Default target
all: $(EXEC)

# Compile parser
$(YACC_C) $(YACC_HDR): $(YACC_SRC)
	$(YACC) $(YACC_SRC)

# Compile lexer
$(LEX_C): $(LEX_SRC)
	$(LEX) $(LEX_SRC)

# Object files
codegen.o: codegen.c codegen.h
	$(CC) -c codegen.c

symboltable.o: symboltable.c symboltable.h
	$(CC) -c symboltable.c

$(LEX_C): $(YACC_HDR)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

test: $(EXEC)
	@echo "== Generating .jasm files from testcases/*.sd =="
	@for file in $(wildcard testcases/*.sd); do \
		name=$$(basename $$file .sd); \
		echo "Compiling $$file -> testcases/$$name.jasm"; \
		./$(EXEC) $$file testcases/$$name.jasm; \
	done

# Clean
clean:
	rm -f $(EXEC) *.o $(YACC_C) $(YACC_HDR) $(LEX_C)
	rm -f testcases/*.jasm

