#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *prev;
struct node *next;
}*NODE;
NODE start=NULL;
NODE create(NODE);
void disp(NODE);
main()
{
int opt;
do{
printf("\nMain Menu\n");
printf("1)Create\n");
printf("2)Display\n");
printf("3)Exit\n");
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
case 3:
printf("Thank you!\n");
}
}while(opt>=1&&opt<3);
}
NODE create(NODE start)
{
NODE new_node;
int x;
printf("Enter val(-1 to exit)\n");
scanf("%d",&x);
while(x!=-1)
{
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=x;
new_node->prev=NULL;
if(start==NULL)
{
start=new_node;
new_node->next=NULL;
}
else
{
start->prev=new_node;
new_node->next=start;
start=new_node;
}
printf("Enter more val(-1 to exit)\n");
scanf("%d",&x);
}//end of while loop
return start;
}
void disp(NODE start)
{
NODE ptr=start;
printf("Traversing forward\n");
while(ptr->next!=NULL)
{
printf("%d<->",ptr->data);
ptr=ptr->next;
}
printf("%d\nTraversing backwards:\n",ptr->data);
while(ptr->prev!=NULL)
{
printf("%d<->",ptr->data);
ptr=ptr->prev;
}
printf("%d",ptr->data);
}
