#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
	int roll;
	char name[25];
	float mark1;
	float mark2;
	float mark3;
}Student;

void Calculate(Student * s)
{
	float total = s->mark1 + s->mark2 + s->mark3;
	float average = total / 3.0f;
	char grade;
	
	if (average >= 90.0f)
	{
		grade = 'O';
	}
	else if (average >= 80.0f)
	{
		grade = 'E';
	}
	else if (average >= 70.0f)
	{
		grade = 'A';
	}
	else if (average >= 60.0f)
	{
		grade = 'B';
	}
	else if (average >= 50.0f)
	{
		grade = 'C';
	}
	else if (average >= 40.0f)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}
	
	printf("\nTotal = %f", total);
	printf("\nAverage = %f", average);
	printf("\nGrade = %c", grade);
}

int main()
{
	system("clear");
	
	Student s;
	
	printf("Enter Student Roll Number: ");	
	scanf("%d", &s.roll);
	printf("Enter Student Name: ");	
	scanf("%s", s.name);
	printf("Enter Student marks in three subjects: ");	
	scanf("%f%f%f", &s.mark1, &s.mark2, &s.mark3);
	Calculate(&s);
	
	printf("\n\n");
	return 0;
}
