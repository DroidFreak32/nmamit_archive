%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NL A B
%%
stmt:A A A A A A A A A A S B NL {printf("valid\n");exit(0);}
;
S: S A|
;
%%
int yyerror()
{
printf("Invalid\n");
}
int main()
{
printf("Enter the string\n");
yyparse();
}
