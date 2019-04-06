%{
#include "y.tab.h"
#include<stdlib.h>
%}
%%
\n {return NL;}
[0-9]+ {yylval= atoi(yytext); return ID;}
[0-9]+"."[0-9]+ {yylval= atof(yytext); return ID;}
. {return yytext[0];}
%%
