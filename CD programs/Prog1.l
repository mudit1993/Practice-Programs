%{
#include "y.tab.h"
%}
%%
[a] { printf("\nReceived 'a'."); return (ID1);}
[b] { printf("\nReceived 'b'."); return (ID2);}
\n { return NL ;}
. { return yytext[0]; }
%%
