a.out: p11.yacc p11.lex
	yacc -d p11.yacc && lex p11.lex
	gcc y.tab.c lex.yy.c -ly -ll -Wno-implicit-function-declaration
