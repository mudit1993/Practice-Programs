#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");
	
	int *a;
	
	a = (int *)malloc(sizeof(int) * 5);
	
	printf("Enter 5 numbers: ");
	int i;
	for (i=0; i<5; i++)
	{
		scanf("%d", a + i);
	}
	
	printf("\n\nThe 5 numbers are: ");
	for (i=0; i<5; i++)
	{
		printf("%d	", *(a + i));
	}
	
	printf("\n\n");
	return 0;
}
