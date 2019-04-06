%{
#include<stdio.h>
/*
S-->AA
A-->aA|b
E->E+E|E*E|a
*/
%}

%start Stmt
%token NL
%left '+' '-'
%left '*'
%%                   /* beginning of rules section */

Stmt: E NL {printf("\nSuccessfull parsing."); exit(0);}
 ;
E: E '+' E { printf("\nIn Production 1.");}
 |
   E '*' E { printf("\nIn Production 2.");}
 |
  'a' { printf("\nIn Production 3.");}
 ;

%%
int main()
{
 yyparse();
}

yyerror(char *s)
{
  printf("Error: %s\n",s);
}

int yywrap()
{
  return(1);
}
