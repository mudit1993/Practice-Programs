#include<stdio.h>
#include<malloc.h>
typedef struct exp
{
int flag;
int coef;
int x;
int y;
int z;
struct exp *next;
}*NODE;
NODE add(NODE,NODE);
NODE start=NULL;
NODE start1=NULL;
NODE create(NODE);
void disp(NODE);


main()
{
int opt;
printf("For Expression 1\n");
do{
	printf("\nMAIN MENU\n");
	printf("1)create \n");
	printf("2)display\n");
	printf("3)exit for exp 1\n");
	scanf("%d",&opt);
 switch(opt)
{
case 1: start=create(start);
        printf("List created\n");
	break;
 case 2: disp(start);
	break;
case 3: printf("expression 1 created\n");
}
}while(opt>=1 && opt<=2);

printf("For Expression 2\n");
do{
	printf("\nMAIN MENU\n");
	printf("1)create \n");
	printf("2)display\n");
	printf("3)exit for exp 2\n");
	scanf("%d",&opt);
 switch(opt)
{
case 1: start1=create(start1);
        printf("expression created\n");
	break;
 case 2: disp(start1);
	break;
case 3: printf("expression 2 created\n");
}
}while(opt>=1 && opt<=2);
start=add(start,start1);
printf("After addition\n");
disp(start);
}



NODE create(NODE start)
{
NODE new_node;
int a,b,c,co,e;
printf("Start creation-press any integer?(-1 to exit)\n");
scanf("%d",&e);
while(e!=-1)
{
new_node=(NODE)malloc(sizeof(struct exp));
printf("Enter Exponents for variables x,y,z and their coefficient respectively\n");
scanf("%d%d%d%d",&a,&b,&c,&co);
new_node->flag=0;
new_node->x=a;
new_node->y=b;
new_node->z=c;
new_node->coef=co;
if(start==NULL)
{
start=new_node;
new_node->next=NULL;
}
else
{
new_node->next=start;
start=new_node;
}
printf("press any integer to continue?(-1 to exit)");
scanf("%d",&e);
}
return start;
}
void disp(NODE start)
{
 NODE ptr=start;
if(start==NULL)
printf("Polynomial does not exist\n");
else
{
 while(ptr->next!=NULL)
{
printf("(%dx^%dy^%dz^%d)+",ptr->coef,ptr->x,ptr->y,ptr->z);
ptr=ptr->next;
}
 //if(start==NULL)
//printf("Polynomial does not exist\n");
//else
printf("(%dx^%dy^%dz^%d)\n",ptr->coef,ptr->x,ptr->y,ptr->z);
}
}




NODE add(NODE start2,NODE start1)
{
NODE ptr=start2,ptr1=start1,prev=start2;
//int i=0;
while(ptr!=NULL)
{
ptr1=start1;
ptr->flag=1;
while(ptr1!=NULL)
{
if(ptr->x==ptr1->x && ptr->y==ptr1->y && ptr->z==ptr1->z && ptr1->flag==0)
{
ptr->coef+=ptr1->coef;
ptr1->flag=1;
}
//i++;
//printf("%d\n",i);
ptr1=ptr1->next;
}
prev=ptr;
ptr=ptr->next;
}
ptr1=start1;
while(ptr1!=NULL)
{
if(ptr1->flag==0)
{
prev->next=ptr1;
prev=prev->next;
}
ptr1=ptr1->next;
}
prev->next=NULL;
return start2;
}
