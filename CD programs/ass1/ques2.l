%{
	int c1 = 0, v1 = 0, os = 0, nl = 0, comma = 0, semi = 0;
%}

%option noyywrap

C	[a-zA-Z]
V	[aeiouAEIOU]

%%

END	{return 1;}
{V}	{v1++;}
{C}	{c1++;}
\n	{nl++;}
\,	{comma++;}
\;	{semi++;}
.	{os++;}

%%

main()
{
	system("clear");
	printf("Enter a string ending with END: ");
	yylex();
	printf("\nNo. of Consonants: %d", c1);
	printf("\nNo. of Vowels: %d", v1);
	printf("\nNo. of New Lines: %d", nl);
	printf("\nNo. of Commas: %d", comma);
	printf("\nNo. of Semi Colons: %d", semi);
	printf("\nNo. of Other Symbols: %d", os);
	printf("\n\n");
}
