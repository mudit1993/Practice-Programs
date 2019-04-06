%{
	int keyword = 0, identifier = 0, integer = 0, os = 0, floats = 0, operators = 0;
%}

D	[0-9]
L	[a-zA-Z]
V	[aeiouAEIOU]

%%

if|while|printf|scanf|int|float	{keyword++;}
[_][ \n\,\;\.]					{os++;}
[a-zA-Z_][a-zA-Z0-9]*			{identifier++;}
[0-9]+							{integer++;}
[0-9]+[\.][0-9]+				{floats++;}
[+\-*\|=<>\,/]					{operators++;}
.								{os++;}

%%

int yywrap()
{
	return 1;
}

main()
{
	system("clear");
	yyin = fopen("test.txt", "r");
	yylex();
	printf("\nNo. of Keywords: %d", keyword);
	printf("\nNo. of Identifiers: %d", identifier);
	printf("\nNo. of Integers: %d", integer);
	printf("\nNo. of Floats: %d", floats);
	printf("\nNo. of Operators: %d", operators);
	printf("\nNo. of Other Symbols: %d", os);
	printf("\n\n");
	fclose(yyin);
}
