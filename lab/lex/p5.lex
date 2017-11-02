%{
    #include<stdio.h>
    int is_simple=1;
%}
%%
    /* Space/tab/newline followed by BUT/AND/OR followed by Space/tab/newline */
[ \t\n][bB][uU][Tt][ \t\n] {is_simple=0;}
[ \t\n][oO][rR][ \t\n] {is_simple=0;}
[ \t\n][aA][nN][dD][ \t\n] {is_simple=0;}
. {;}
%%
int yywrap(){ return 1; }
void main(){
    printf("\nEnter a sentence\n");
    yylex();
    if(is_simple==0)
        printf("\nSentence is compound\n");
    else
        printf("\nSentence is simple\n");
    yywrap();
}
