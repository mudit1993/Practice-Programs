%{
	int c1 = 0, v1 = 0, os = 0, nl = 0, comma = 0, semi = 0;
%}

C	[a-zA-Z]
V	[aeiouAEIOU]

%%

{V}	{v1++;}
{C}	{c1++;}
\n	{nl++;}
\,	{comma++;}
\;	{semi++;}
.	{os++;}

%%

int yywrap()
{
	return 1;
}

main()
{
	system("clear");
	yyin = fopen("lex.yy.c", "r");
	yylex();
	printf("\nNo. of Consonants: %d", c1);
	printf("\nNo. of Vowels: %d", v1);
	printf("\nNo. of New Lines: %d", nl);
	printf("\nNo. of Commas: %d", comma);
	printf("\nNo. of Semi Colons: %d", semi);
	printf("\nNo. of Other Symbols: %d", os);
	printf("\n\n");
	fclose(yyin);
}
