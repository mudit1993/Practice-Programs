%{
	#include<stdio.h>
	int rp=0;
	int num=0;
	int id=0;
	int kw=0;
	int i,j,k;
	char opr[100][2][10];
	char key[100][2][10];
	char number[100][2][10];
	char idn[100][2][10];	
%}
alphabet [a-zA-Z]
digit	[0-9]
identifier {alphabet}+({digit}|{alphabet})*
%%
"<="	{strcpy(opr[rp][0],"LE");	strcpy(opr[rp][1],yytext);	rp++;}
"<"	{strcpy(opr[rp][0],"LT");	strcpy(opr[rp][1],yytext);	rp++;}
">="	{strcpy(opr[rp][0],"GE");	strcpy(opr[rp][1],yytext);	rp++;}
">"	{strcpy(opr[rp][0],"GT");	strcpy(opr[rp][1],yytext);	rp++;}
"="	{strcpy(opr[rp][0],"EQ");	strcpy(opr[rp][1],yytext);	rp++;}
"<>"	{strcpy(opr[rp][0],"NE");	strcpy(opr[rp][1],yytext);	rp++;}
"-"	{strcpy(opr[rp][0],"SUB");	strcpy(opr[rp][1],yytext);	rp++;}
"+"	{strcpy(opr[rp][0],"ADD");	strcpy(opr[rp][1],yytext);	rp++;}
"*"	{strcpy(opr[rp][0],"MUL");	strcpy(opr[rp][1],yytext);	rp++;}
"/"	{strcpy(opr[rp][0],"DIV");	strcpy(opr[rp][1],yytext);	rp++;}
"#"     {strcpy(opr[rp][0],"HASH");	strcpy(opr[rp][1],yytext);	rp++;}
"."     {strcpy(opr[rp][0],"DOT");	strcpy(opr[rp][1],yytext);	rp++;}
"{"	{strcpy(opr[rp][0],"OPBR");	strcpy(opr[rp][1],yytext);	rp++;}
"}"     {strcpy(opr[rp][0],"CLBR");	strcpy(opr[rp][1],yytext);	rp++;}
"("	{strcpy(opr[rp][0],"RNDOP");	strcpy(opr[rp][1],yytext);	rp++;}
")"     {strcpy(opr[rp][0],"RNDCL");	strcpy(opr[rp][1],yytext);	rp++;}
";"     {strcpy(opr[rp][0],"SC");	strcpy(opr[rp][1],yytext);	rp++;}
","     {strcpy(opr[rp][0],"COMMA");	strcpy(opr[rp][1],yytext);	rp++;}

-?(([0-9]+\.)?[0-9]+)([eE][-+]?[0-9]+)?	{strcpy(number[num][0],"num");		strcpy(number[num][1],yytext);	num++;}
"if"|"else"|"switch"|"break"|"for"|"while"|"do"|"int"|"float"|"double"|"char"|"return"|"main"|"void"|"include"|"stdio.h"			{strcpy(key[kw][0],yytext);	strcpy(key[kw][1],yytext);	kw++;}
{identifier}	{strcpy(idn[id][0],"id");		strcpy(idn[id][1],yytext);		id++;}

%%
void main()
{
	yyin=fopen("sym","r");
	yylex();
	for(i=0;i<rp;i++)
		{
		for(j=0;j<=1;j++)
			{
			printf("%s\t",opr[i][j]);
			}
		printf("\n");
		}
	printf("\n\n");	
	for(i=0;i<kw;i++)
		{
		for(j=0;j<=1;j++)
			{
			printf("%s\t",key[i][j]);
			}
		printf("\n");
		}
		
		printf("\n\n");	
	for(i=0;i<num;i++)
		{
		for(j=0;j<=1;j++)
			{
			printf("%s\t",number[i][j]);
			}
		printf("\n");
		}
		printf("\n\n");	
	for(i=0;i<id;i++)
		{
		for(j=0;j<=1;j++)
			{
			printf("%s\t",idn[i][j]);
			}
		printf("\n");
		}
	printf("no. of keywords:%d\n",kw);
	printf("no. of operators:%d\n",rp);
	printf("no. of numbers:%d\n",num);
	printf("no. of identifiers:%d\n",id);
	fclose(yyin);
}
