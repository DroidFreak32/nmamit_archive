// if(a<b){if(b<c){s}}
// NO. of nested if Statements 2

%{
	#include<stdio.h>
	#include<stdlib.h>
	int count=0;
%}
%token IF RELOP S NUMBER ID
%%
stmt: if_stmt {printf("NO. of nested if Statements %d\n",count);exit(0);};
if_stmt:	IF'('cond')''{'if_stmt'}'{count++;}
			|S;
cond: x RELOP x
	;
x:ID
  |NUMBER
  ;
%%
int yyerror(char *msg)
{
printf("Given expression is not valid\n");
exit(0);
}
int main()
{
	printf("Enter the Statement\n");
	yyparse();
	return 0;
}
