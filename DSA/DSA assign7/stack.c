#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
}*NODE;
NODE start=NULL;
NODE push(NODE);
NODE pop(NODE);
void disp();
main()
{
int opt;
do{
printf("\nMain Menu\n");
printf("1)Create or insert more values\n");
printf("2)Delete values from stack\n");
printf("3)Display the list\n");
printf("4)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
start=push(start);
printf("stack created or value added\n");
break;
case 2:
start=pop(start);
break;
case 3:
disp(start);
break;
case 4:
printf("Thank you!\n");
}
}while(opt>=1&&opt<4);
}
NODE push(NODE start)
{
NODE new_node,top;
top=start;
int x;
printf("Enter a value(-1 to Exit)\n");
scanf("%d",&x);
while(x!=-1)
{
top=start;
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=x;
new_node->next=NULL;
if(start==NULL)
start=new_node;
else
{
while(top->next!=NULL)
{
top=top->next;
}
top->next=new_node;
}
printf("Enter more val(-1 to exit)\n");
scanf("%d",&x);
}
return start;
}
NODE pop(NODE start)
{
NODE top=start,ptr=start;
while(top->next!=NULL)
{
ptr=top;
top=top->next;
}
ptr->next=NULL;
free(top);
return start;
}
void disp(NODE start)
{
NODE top=start;
printf("Stack is:\n");
while(top->next!=NULL)
{
printf("%d->",top->data);
top=top->next;
}
printf("%d\n",top->data);
}

