%{
#include<stdio.h>
%}
%start Stmt
%token ID NL
%left '+' '-'
%left '*' '/'
%%                   /* beginning of rules section */

Stmt: T NL {printf("\nThe evaluated value is:%f",(float)$1); exit(0);}
 ;
T:T'+'T {$$=$1+$3;}
 |T'-'T {$$=$1-$3;}
 |T'*'T {$$=$1*$3;}
 |T'/'T {  if($3==0)
            {
               printf("Cannot divide by 0");
               exit(0);
            }
            else
              $$=$1/$3;
         }
 |'('T')' {$$=$2;}
 |ID {$$=$1;}
 ;
%%
int main()
{
 printf("\nGive a numeric expression:");
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
