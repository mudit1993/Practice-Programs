%{
int v=0;
int c=0;
%}
%%
[	\t\n]+       ;
[aeiouAEIOU]	v++;
[a-zA-z]	c++;
%%
main()
{
printf("\nenter any string :");
yylex();
printf("no of vowels=%d\n",v);
printf("no of consonants=%d\n",c);
}
