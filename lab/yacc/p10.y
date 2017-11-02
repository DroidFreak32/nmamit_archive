%{
	#include <stdio.h>
	#include <stdlib.h>
%}
%token A B NL
%%
stmt: s NL { printf("Valid\n"); exit(0); }
s:A A A A A A A A A A s B 
    |A s
    ;
%%
int yyerror(char *msg){
    printf("Invalid");
    exit(0);    
}
int main(){
    printf("\nEnter the string:\n");
    yyparse();
}
