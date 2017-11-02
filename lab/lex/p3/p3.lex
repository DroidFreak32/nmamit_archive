/*Program to calc no of +/- integer and fractions from file from  File*/
%{
    #include<stdio.h>
    int pi=0,ni=0,pf=0,nf=0;
%}
INTEGER [+]?[0-9]+
NINTEGER [-][0-9]+
FRAC [+]?[0-9]+\.[0-9]+
NFRAC [-][0-9]+\.[0-9]+
%%
{INTEGER} {pi++;}
{FRAC} {pf++;}
{NINTEGER} {ni++;}
{NFRAC} {nf++;}
%%
int yywrap() { return 1; }
main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./a.out <Source File>\n");
        exit(0);    
    }
    yyin=fopen(argv[1],"r");
    yylex();
    printf("\nIntegers: %d\nFractions: %d\nNegative integers: %d\nNegative Fractions: %d",pi,pf,ni,nf);
}
