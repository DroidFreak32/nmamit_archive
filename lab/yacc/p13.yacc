%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NL ID NUM
%left '+''-'
%left '*''/'
%%
stmt:exp NL {printf("%d\n",$1);exit(0);};
exp:exp'+'exp {$$=$1+$3;} 
    |exp'-'exp {$$=$1-$3;}
    |exp'*'exp {$$=$1*$3;}
    |exp'/'exp {if($3==0){ printf("Invalid\n"); } $$=$1/$3;}
    |'('exp')'{$$=$2;}
    |NUM {$$=$1;}
;
%%
int yyerror(){
    printf("Given expression is not valid\n");
    exit(0);
}
void main(){
    printf("Enter the expression\n");
    yyparse();
} 
