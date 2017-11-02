%{ 
	#include <stdio.h>
	int vow=0,cons=0;
%}
%%
[aeiouAEIOU] {vow++; }
[a-zA-Z] {cons++; }
. {;}
%%
int yywrap(){
	return 1;
}
int main()
{
	printf("Enter the string: \n");
	yylex();
	printf("\nVowels: %d\nConsonants: %d\n",vow,cons);
}
