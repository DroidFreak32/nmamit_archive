%{
    #include<stdio.h>
    #include<stdlib.h>
    int c=0;
%}

%token ID NUM NL IF S ROP

%%
stmt:ifstmt NL {return c++;printf("Invalid 'if' statement\nLevels of nesting:%d",c); exit(0); }
ifstmt:IF '(' cond ')' '{' stmt '}' |S {return c++;};
cond:ID ROP ID|ID ROP NUM|NUM ROP ID|NUM ROP NUM;
%%

void yyerror()
{
    printf("Valid if statement\nLevels of nesting:%d\n",c);
}

int main()
{
    yyparse();
    return 0;
}
