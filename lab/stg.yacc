%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NL A B
%%
stmt:S NL {printf("Valid string\n");exit(0);}
;
S:A S B|
;
%%
int yyerror()
{
printf("Invalid string\n");
}
int main()
{
printf("Enter the string\n");
yyparse();
}
