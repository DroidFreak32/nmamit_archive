/*Program to count no of identifiers from  File*/
%{
    #include<stdio.h>
    int id=0;
%}
%%
    /* Regex for identifuer */
[_a-zA-Z][_a-zA-z0-9]* {id++;printf("ID: ");ECHO;printf("\n");}
    /* Skip all the rest */
.+ {;}
%%
int yywrap() { return 1; }
main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: ./a.out <Source File>\n");
        exit(0);    
    }
    yyin=fopen(argv[1],"r");
    yylex();
    printf("\nIdentifiers %d",id);
}
