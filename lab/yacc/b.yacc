%{ 
	#include<stdio.h>
	#include<stdlib.h>
%}
%token LETTER DIGIT UND NL
%%
stmt:variable NL{printf("valid");exit(0);}
variable:LETTER alphanum|LETTER
alphanum:LETTER alphanum|
         DIGIT alphanum|
         UND alphanum|
         DIGIT|
        LETTER
;
%%
int yyerror()
{
printf("invalid");
}
int main()
{
printf("enter variables\n");
yyparse();
return 0;
}

