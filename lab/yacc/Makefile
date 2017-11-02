a.out: p15.yacc p15.lex
	yacc -d p15.yacc && lex p15.lex
	gcc y.tab.c lex.yy.c -ly -ll -Wno-implicit-function-declaration
