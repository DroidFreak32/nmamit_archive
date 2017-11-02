%{
	#include<stdio.h>
	#include<string.h>
	int noprt=0,nopnd=0,valid=1,top=-1,l=0,j=0;
	char stack[100],opnd[10][10],oprt[10][10];
%}
%%
"(" {top++; stack[top]= '(';}
"{" {top++; stack[top]= '}';}
"[" {top++; stack[top]= ']';}
")" {
		if(stack[top]!='('){
			valid=0;
			return 0;
		}
		else
			top--;
    }
"}" {
		if(stack[top]!='{'){
			valid=0;
			return 0;
		}
		else
			top--;
    }
"]" {
		if(stack[top]!='['){
			valid=0;
			return 0;
		}
		else
			top--;
    }
"+"|"-"|"/"|"*" {noprt++;
				strcpy(oprt[l],yytext);
				l++;}
				
[0-9]+|[a-zA-Z0-9]*  {nopnd++;
					  strcpy(opnd[j],yytext);
					  j++;}
%%
int main(){
	int k=0;
	printf("Enter the expression\n");
	yylex();
	if(valid==1 && top==-1 && ((nopnd-noprt)==1)){
		printf("The Expression is valid\n");
		printf("The no of operators are: %d\nOperators are: \n",l);
		for(k=0;k<l;k++)
			printf("%s\n",oprt[k]);
		printf("No of Operands are: %d\nOperands are: \n",j);
		for(k=0;k<j;k++)
			printf("%s\n",opnd[k]);
	}
		else
			printf("Exp is invalid");
		return 0;
}
int yywrap(){
	return 1;
}
