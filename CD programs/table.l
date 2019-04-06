%{
	#include<stdio.h>
	int rp=0;
	int kw=0;
	int num=0;
	int id=0;
	
%}
alphabet [a-zA-Z]
digit	[0-9]
identifier {alphabet}+({digit}|{alphabet})*
%%
"<="	{printf("relop\tLE\n");rp++;}
"<"		{printf("relop\tL\n");rp++;}
">="	{printf("relop\tGE\n");rp++;}
">"		{printf("relop\tG\n");rp++;}
"="		{printf("relop\tEQ\n");rp++;}
"<>"	{printf("relop\tNE\n");rp++;}
"-"		{printf("artop\tSUB\n");rp++;}
"+"		{printf("artop\tADD\n");rp++;}
"*"		{printf("artop\tMUL\n");rp++;}
"/"		{printf("artop\tDIV\n");rp++;}
"#"     {printf("op\tHASH\n");}
"."     {printf("op\tDOT\n");}
"{"		{printf("op\tOPBR\n");}
"}"     {printf("op\tCLBR\n");}
"("		{printf("op\tOPBR\n");}
")"     {printf("op\tCLBR\n");}
";"     {printf("op\tsemicolon\n");}
","     {printf("op\tcomma\n");}

-?([0-9]+\.?[0-9]+)([eE][-+]?[0-9]+)?	{printf("number\tnumber\n");  num++;}
"if"|"else"|"switch"|"break"|"for"|"while"|"do"|"int"|"float"|"double"|"char"|"return"|"main"|"void"|"include"|"stdio.h"		{printf("%s\t%s\n",yytext,yytext); kw++;}
{identifier}	{printf("id\t%s\n",yytext);  id++;}

%%
void main()
{
	yyin=fopen("sym","r");
	yylex();
	printf("no. of keywords:%d\n",kw);
	printf("no. of operators:%d\n",rp);
	printf("no. of numbers:%d\n",num);
	printf("no. of identifiers:%d\n",id);
	fclose(yyin);
}
