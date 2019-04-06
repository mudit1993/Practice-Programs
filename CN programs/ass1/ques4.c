#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");
	
	char string[255];
	
	FILE *f;
	
	f = fopen("test.txt", "w+");
	
	fprintf(f, "Test Case\n");
	fputs("Test Case 2\n", f);
	
	fclose(f);
	
	f = fopen("test.txt", "r");
	fscanf(f, "%s", string);
	
	printf("1: %s\n", string);
	
	fgets(string, 255, (FILE *)f);
	printf("2: %s", string);
	
	fgets(string, 255, (FILE *)f);
	printf("3: %s", string);
	
	fclose(f);

	printf("\n\n");
	return 0;
}
