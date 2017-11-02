a.out: p9.y p9.lex
	yacc -d p9.y && lex p9.lex
	gcc y.tab.c lex.yy.c -ly -ll -Wno-implicit-function-declaration
