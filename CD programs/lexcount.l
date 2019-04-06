%{
int cc=0;
int wc=0;
int lc=0;
int bc=0;
%}

word [^ \t\n]+   
eol [\n]
blank []

%%
{blank}	bc++;
{word}	{wc++;cc+=yyleng;}
{eol}	{cc++;lc++;}
.		{cc++;}
%%

main(int argc,char* argv[])
{
yyfin=fopen(argv[1],"r");
yylex();
printf("\n charcter count %d",cc);
printf("\n word count %d",wc);
printf("\n line count %d",lc);
printf("\n bcount %d",bc);
}


