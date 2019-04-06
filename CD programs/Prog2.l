%{
#include "y.tab.h"
%}
%%
\n { return NL ;}
. { return yytext[0]; }
%%
