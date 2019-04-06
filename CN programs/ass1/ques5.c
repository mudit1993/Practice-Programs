#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
	char name[25];
	float mark1;
	float mark2;
}Student;

void Swap(Student * s)
{
	float temp;
	temp = s->mark1;
	s->mark1 = s->mark2;
	s->mark2 = temp;
}

int main()
{
	system("clear");
	
	Student s;
	
	printf("Enter Student Name: ");	
	scanf("%s", s.name);
	printf("Enter Student marks in two subjects: ");	
	scanf("%f%f", &s.mark1, &s.mark2);

	printf("\n\nMarks before swapping: %f\t%f", s.mark1, s.mark2);	
	Swap(&s);
	printf("\n\nMarks before swapping: %f\t%f", s.mark1, s.mark2);
	
	printf("\n\n");
	return 0;
}
