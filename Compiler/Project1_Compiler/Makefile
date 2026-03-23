.PHONY: all clean

all: scanner

scanner: lex
	g++ -o scanner -O lex.yy.c hashtable.c symboltable.c

lex: 
	lex Project1.l

test: scanner
	./scanner < tests/HelloWorld.sd > tests/HelloWorld.out
	./scanner < tests/fib.sd > tests/fib.out
	./scanner < tests/example.sd > tests/example.out
	./scanner < tests/Sigma.sd > tests/Sigma.out


clean:
	$(RM) scanner
	$(RM) tests/*.out
