%{
    #include "y.tab.h"
%}
%%
"if" {return IF;}
[sS][0-9]* {return S;}
"<"|">"|"=="|"!="|"<="|">=" {return RELOP;}
[0-9]+ {return NUMBER;}
[a-zA-Z][0-9a-zA-Z]* {return ID;}
\n {;}
. {return yytext[0];}
%%

