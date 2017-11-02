%{
    #include<stdio.h>
    int s=0,p=0;
%}
%%
    /* fprintf() replaces matched regex ?*/
"printf" {p++; fprintf(yyout,"writef");}
"scanf" {s++; fprintf(yyout,"readf");}
%%
int yywrap(){ return 1; }
int main(int argc,char *argv[]){
    if (argc !=3 )    {
        printf("Usage: ./a.out <src> <dest>\n");
        exit(0);
    }
    yyin=fopen(argv[1],"r");
    yyout=fopen(argv[2],"w");
    yylex();
    printf("No of scanf statement are %d",s);
    printf("\nNo of printf statement are %d\n",p);
    return 0;
}