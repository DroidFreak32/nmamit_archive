%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NL LETTER UND DIGIT
%%
stmt:var NL {printf("Valid\n");
exit(0);}
;
var:LETTER alphanumeric
;
alphanumeric:LETTER alphanumeric|DIGIT alphanumeric| UND alphanumeric|LETTER|DIGIT|
;
%%
int yyerror()
{
printf("Invalid\n");
exit(0);
}
int main()
{
printf("Enter a variable\n");
yyparse();
}
