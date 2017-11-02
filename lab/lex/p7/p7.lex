%{
	#include<stdio.h>
	int comm=0;
%}
%s COMMENT
%%
	/* Match one liners */
"//".* {comm++;}
"/*" {BEGIN COMMENT;}
	/* for every line in block comment, inc count */
<COMMENT>\n {comm++;}
<COMMENT>"*/" {BEGIN 0;comm++;}
<COMMENT>. {;}
	/* Rest of the remaining chars (.) and new lines(\n) are matched and the matched string is stored in yytext. */
.|\n {fprintf(yyout, "%s", yytext);}
%%
int yywrap(){ return 1; }
int main(int argc,char * argv[]){
	if(argc!=3){
		printf("Usage: ./a.out <src> <dest>\n");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
	printf("Number of comment lines = %d \n",comm);
}