all: parser

parser: parser.y Project2.l hashtable.c symboltable.c
	bison -d -o parser.tab.c parser.y
	flex Project2.l
	gcc -o parser parser.tab.c lex.yy.c hashtable.c symboltable.c -lfl -lm

clean:
	rm -f *.o *.tab.c *.tab.h lex.yy.c parser output
	rm -f testcases/*.out

test: parser
	./parser < testcases/HelloWorld.sd > testcases/HelloWorld.out
	./parser < testcases/fib.sd > testcases/fib.out
	./parser < testcases/example.sd > testcases/example.out
	./parser < testcases/Sigma.sd > testcases/Sigma.out
	./parser < testcases/array.sd > testcases/array.out