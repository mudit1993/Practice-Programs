%{
#include<stdio.h>
%}

%start Stmt
%token ID1 ID2 NL
%%                   /* beginning of rules section */

Stmt: S NL {printf("\nSuccessful parsing."); exit(0);}
 ;
S: A A {printf("\nReduced by production 1.");}
 ;
A: ID1 A {printf("\nReduced by production 2.");}
 |
  ID2 {printf("\nReduced by production 3.");}
 ;

%%
int main()
{
 printf("\nGive a string:");
 yyparse();
}

yyerror(char *s)
{
  printf("\nError: %s\n",s);
}

int yywrap()
{
  return(1);
}
