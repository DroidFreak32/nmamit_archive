%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B NL
%%
stmt:A A A A A A A A A A S B NL{printf("valid");exit(0);}
    S:A S |
      ;
%%
int yyerror()
{
printf("invalid");
}
int main()
{
printf("enter string\n");
yyparse();
return 0;
}
