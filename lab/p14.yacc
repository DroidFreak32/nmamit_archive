%{
#include<stdio.h>
#include<stdlib.h>
%}
%token ID SP COM SC NL INT CHAR
%%
stmt: type SP list SC NL {printf("Valid Declaration Statement\n");exit(0);};
type: INT|CHAR;
list:	ID
		|list COM ID
		|list COM SP ID
		|list SP COM SP ID;
%%
int yyerror(char *msg)
{
printf("Given expression is not valid\n");
exit(0);
}
int main()
{
	printf("Enter the expression\n");
	yyparse();
	return 0;
}
