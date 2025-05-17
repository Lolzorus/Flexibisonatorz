all: traducteur

traducteur: ../src/traducteur.l ../src/traducteur.y
	bison -d ../src/traducteur.y
	flex ../src/traducteur.l
	gcc lex.yy.c traducteur.tab.c -o traducteur

clean:
	rm -f traducteur lex.yy.c traducteur.tab.* output.c

