%{
#include "y.tab.h"
%}
%%
\n {return NL;}
[A-Za-z][a-zA-Z0-9]* {return ID;}
[0-9]+ {return NUM;}
. {return yytext[0];}
%%

