%{
#include "y.tab.h"
extern int yyval;
%}
%%
\n {return NL;}
[0-9]+ {yylval=atoi(yytext);return NUM;}
. {return yytext[0];}
%%


