#include<stdio.h>
#include<malloc.h>
typedef struct exp
{
int flag;
int x;
int y;
int z;
struct exp *next;
}*NODE;

NODE start=NULL;
NODE create(NODE);
void disp(NODE);


main()
{
int opt;
do{
	printf("\nMAIN MENU\n");
	printf("1)create \n");
	printf("2)display\n");
	printf("3)exit\n");	
	scanf("%d",&opt);
 switch(opt)
{
case 1: start=create(start);
        printf("List created\n");
	break;
 case 2: disp(start);
	break;
case 3: printf("execution terminated!\n");
}
}while(opt>=1 && opt<=2);
}



NODE create(NODE start)
{
NODE new_node;
int a,b,c,e;
printf("Start creation-press any integer?(-1 to exit)\n");
scanf("%d",&e);
while(e!=-1)
{
new_node=(NODE)malloc(sizeof(struct exp));
printf("Enter Exponents for variables x,y,z respectively\n");
scanf("%d%d%d",&a,&b,&c);
new_node->flag=0;
new_node->x=a;
new_node->y=b;
new_node->z=c;
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
 while(ptr->next!=NULL)
{
printf("(x^%dy^%dz^%d)+",ptr->x,ptr->y,ptr->z);
ptr=ptr->next;
}
 if(start==NULL)
printf("Polynomial does not exist\n");
else
printf("(x^%dy^%dz^%d)\n",ptr->x,ptr->y,ptr->z);
}
