%{	
	#include <stdio.h>
	#include <stdlib.h>
%}
%token A B NL
%%
stmt:	s NL { printf("Valid\n");exit(0); };
s:	A s B
	|
	;
%%
int yyerror(char * msg){
	printf("Invalid string\n");
}
int main(){
	printf("Enter string: \n");
	yyparse();
}