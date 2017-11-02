%{
#include "y.tab.h"
%}
%%
[0-9] {return DIGIT;}
[A-Za-z] {return LETTER;}
\n {return NL;}
_ {return UND;}
. {return yytext[0];}
%%

