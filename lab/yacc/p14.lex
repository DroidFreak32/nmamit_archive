%{
#include "y.tab.h"
%}
%%
"int" {return INT;}
"char" {return CHAR;}
" " {return SP;}
"\n" {return NL;}
"," {return COM;}
";" {return SC;}
[a-zA-Z][0-9a-zA-Z]* {return ID;}
. {return yytext[0];}
%%

