a.out: p9.yacc p9.lex
	yacc -d p9.yacc && lex p9.lex
	gcc y.tab.c lex.yy.c -ly -ll -Wno-implicit-function-declaration
