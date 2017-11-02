%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NL ID NUM
%left '+''-'
%left '*''/'
%%
stmt:exp NL {printf("EXPRESSION IS VALID\n");
exit(0);}
;
exp:exp'+'exp
   |exp'-'exp
   |exp'*'exp
   |exp'/'exp
   |ID|NUM
;
%%
int yyerror()
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
