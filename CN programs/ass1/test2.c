#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	fp = fopen("one.txt", "w");
	printf("Enter data: ");
	char name[255];
	scanf("%s", name);
	int i;
	for (i=0; name[i] != '\0'; i++)
		putc(name[i],fp);
	fclose(fp);
	fp=fopen("one.txt", "r");
	while( (ch = getc(fp)) != EOF)
		printf("%c",ch);
	fclose(fp);
	
	return 0;
}
