%{
	#include<stdio.h>
	int comm=0;
%}
%s COMMENT
%%
"//".* {comm++;}
"/*" {BEGIN COMMENT;}
<COMMENT>\n {comm++;}
<COMMENT>"*/" {BEGIN 0;comm++;}
<COMMENT>. {;}
.|\n {fprintf(yyout, "%s", yytext);}
%%
int yywrap(){ return 1; }
int main(int argc,char * argv[]){
	if(argc!=3){
		printf("Invalid arguements");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
	printf("Number of comment lines = %d ",comm);
}