#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int roll;
struct node *next;
}*NODE;
NODE start=NULL;
NODE create(NODE);
void disp(NODE);
main()
{
int opt;
do
{
printf("\n\n main menu");
printf("\n 1:create");
printf("\n 2:display");
printf("\n 3:Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
start=create(start);
printf("Link list created\n");
break;
case 2:
disp(start);
break;
}
}while(opt!=3);
//getch();
}
NODE create(NODE start)
{
NODE new_node;
int x;
printf("Enter 0 to end\n");
printf("Enter the data");
scanf("%d",&x);
while(x!=0)
{
new_node=(NODE)malloc(sizeof(struct node));
new_node->roll=x;
if(start==NULL)
{
start=new_node;
new_node->next=NULL;
}
else{
new_node->next=start;
start=new_node;
}
printf("Enter the data");
scanf("%d",&x);
}
return start;
}
void disp(NODE start)
{
NODE new_node;
new_node=start;
printf("Data content is:\n");
while(new_node!=NULL)
{
printf("%d\t",new_node->roll);
new_node=new_node->next;
}
}
