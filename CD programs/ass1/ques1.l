%{
	int c1 = 0, v1 = 0, os = 0;
%}

%option noyywrap

C	[a-zA-Z]
V	[aeiouAEIOU]

%%

END {return 1;}
{C} {c1++;}
{V} {v1++;}
.	{os++;}

%%

main()
{
	system("clear");
	printf("Enter a string ending with END: ");
	yylex();
	printf("\nNo. of Consonants: %d", c1);
	printf("\nNo. of Vowels: %d", v1);
	printf("\nNo. of Other Symbols: %d", os);
	printf("\n\n");
}
