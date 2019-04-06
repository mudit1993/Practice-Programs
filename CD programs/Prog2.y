%{
#include<stdio.h>
%}

%start Stmt
%token NL
%%                   /* beginning of rules section */

Stmt: S NL {printf("\nSuccessful parsing."); exit(0);}
 ;
S: A S B
  | 
 ;
A: 'a'
 ;
B: 'b'
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
