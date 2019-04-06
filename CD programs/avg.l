%{
#include<stdio.h>
%}
digit         [0-9]
%%
{digit}+      return atoi(yytext);
%%
void main()
{
	int val,total=0,n=0;
	while((val=yylex())>0)
	{
		total=total+val;
		n++;
	}
	if(n>0)
		printf("the average is=%d",total);
}

