#include<stdio.h>
#include<stdlib.h>
%}
%token NL ID NUM
%left '+''-'
%left '*''/'
%%
stmt:exp NL {printf("valid expression\n");}
     ;
exp:exp '+' exp
   |exp '-' exp
  |exp '*' exp
   |exp '/' exp
  |'(' exp ')'
    |ID
    |NUM
;
%%
int yyerror()
{
printf("invalid expression\n");
exit(0);
}
int main()
{
printf("enter expression\n");
yyparse();
return 0;
}

