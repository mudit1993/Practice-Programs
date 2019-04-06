#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");
	
	int *a, *b;
	
	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));
	
	printf("Enter two numbers: ");
	scanf("%d%d", a, b);
	
	printf("%d + %d = %d", *a, *b, *a + *b);
	
	printf("\n\n");
	return 0;
}
