/*Program to calc no of words,chars,lines,spaces*/
%{
    #include<stdio.h>
    int l=0,c=0,w=0,s=0;
%}
WORD [^ \n\t,\.:?]+
SPACE [ ]
LINE [\n]
CHAR .
%%
{WORD} {w++;c=c+yyleng;}
{SPACE} {s++;}
{LINE} {l++;}
{CHAR} {c++;}
%%
int yywrap() { return 1; }
main(){
    printf("Enter string:\n");
    yylex();
    printf("\nCharacters=%d\nLines=%d\nWords=%d\nSpaces=%d\n",c,l,w,s);
}
