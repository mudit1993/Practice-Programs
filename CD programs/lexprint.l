%{
int pc=0,sc=0;
%}
%%
printf	fprintf(yyout,"write"); pc++;
scanf	fprintf(yyout,"read");sc++;
.		ECHO;
%%
main(int argc,char* argv[])
{
if(argc!=3)
{
	printf("pass the files names\n");
	}
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
	printf("number of printf s =%d\nscanf=%d\n",pc,sc);
	}
