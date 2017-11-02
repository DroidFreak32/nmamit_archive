/*Program to calc no of words,chars,lines,spaces from  File*/
%{
    #include<stdio.h>
    int l=0,c=0,w=0,s=0;
%}
    /*Set if chars NOT having punctuations/newlines/tab spaces */
WORD [^ \n\t,\.:?]+
SPACE [ ]
LINE [\n]
CHAR .
%%
    /*yyleng returns the length of the matched string --> add it to number of chars */
{WORD} {w++;c=c+yyleng;}
{SPACE} {s++;}
{LINE} {l++;}
{CHAR} {c++;}
%%
int yywrap() { return 1; }
int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./a.out <Source File>\n");
        exit(0);    
    }
    yyin=fopen(argv[1],"r");
    yylex();
    printf("\nCharacters=%d\nLines=%d\nWords=%d\nSpaces=%d\n",c,l,w,s);
    return 0;
}
