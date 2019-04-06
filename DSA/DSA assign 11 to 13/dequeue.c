#include<stdio.h>
void insertf();
void inserte();
void deletef();
void deletee();
void disp();
int arr[100];
int front=-1,rear=-1,size;
main()
{
int opt;
printf("Enter size of the array\n");
scanf("%d",&size);
do{
printf("\nMain menu\n");
printf("1)Insert at the front\n");
printf("2)Insert at the end\n");
printf("3)Delete from the front\n");
printf("4)Delete from the end\n");
printf("5)Display\n");
printf("6)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:insertf();
	printf("Number inserted at the front\n");
	break;
case 2:inserte();
	printf("Number inserted at the end\n");
	break;

case 3:deletef();
	printf("Number deleted from the front\n");
	break;

case 4:deletee();
	printf("Number deleted from the end\n");
	break;

case 5:disp();
	break;
case 6:printf("Execution Terminated\n");
}
}while(opt>=1 && opt<=5);
}


void insertf()
{
int val;
 if((rear+1)%size==front)
	printf("Overflow-Insertion not possible\n");
else{
printf("Enter a value\n");
scanf("%d",&val);
if(front==-1)
rear=front=0;
else 
front=(front+size-1)%size;
arr[front]=val;
}
}

void inserte()
{
int val;
 if((rear+1)%size==front)
	printf("Overflow-Insertion not possible\n");
else{
printf("Enter a value\n");
scanf("%d",&val);
if(front==-1)
rear=front=0;
else 
rear=(rear+1)%size;
arr[rear]=val;
}
}


void deletef()
{
if(front==-1)
printf("Underflow-no Queue exist\n");
else
{
if(rear==front)
rear=front=-1;
else
front=(front+1)%size;
}
}


void deletee()
{
if(front==-1)
printf("Underflow-no Queue exist\n");
else
{
if(rear==front)
rear=front=-1;
else
rear=(rear+size-1)%size;
}
}

void disp()
{
int i;
if(front==-1)
printf("Queue does not exist\n");
else
{
for(i=front;i!=rear;i=(i+1)%size)
printf("%d  ",arr[i]);
printf("%d ",arr[rear]);
}
}
