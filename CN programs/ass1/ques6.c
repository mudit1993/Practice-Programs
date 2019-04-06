#include<stdio.h>
#include<stdlib.h>

typedef struct Birthday
{
	int date;
	int month;
	int year;
}Birthday;

PrintDate(Birthday * b)
{
	printf("%d - %d - %d", b->date, b->month, b->year);
}

typedef struct Father
{
	char name[25];
	Birthday dob;
}Father;

typedef struct Son
{
	char name[25];
	Birthday dob;
	Father father;
}Son;

int main()
{
	system("clear");

	Son s;
	
	printf("Enter son name: ");
	scanf("%s", s.name);
	printf("Enter son date of birth (dd-mm-yy): ");
	scanf("%d%d%d", &s.dob.date, &s.dob.month, &s.dob.year);
	printf("Enter father name: ");
	scanf("%s", s.father.name);
	printf("Enter father date of birth (dd-mm-yy): ");
	scanf("%d%d%d", &s.father.dob.date, &s.father.dob.month, &s.father.dob.year);
	
	printf("\n\nInfo\n\n");
	printf("Son Name: ", s.name);
	printf("\nSon DOB: ");
	PrintDate(&s.dob);
	printf("\n\nFather Name: ", s.father.name);
	printf("\nFather DOB: ");
	PrintDate(&s.father.dob);
	
	printf("\n\n");
	return 0;
}
