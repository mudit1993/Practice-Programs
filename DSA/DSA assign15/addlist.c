#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
}*NODE;
NODE start1=NULL;
NODE start2=NULL;
NODE start3=NULL;
NODE create(NODE);
void disp(NODE);
NODE add(NODE,NODE);
main()
{
int opt;
do{
printf("\nMain Menu\n");
printf("1)Create\n");
printf("2)Add\n");
//printf("3)Delete position\n");
printf("3)Display result \n");
printf("4)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
start1=create(start1);
printf("Link list 1 created\n");
disp(start1);
start2=create(start2);
printf("Link list 2 created\n");
disp(start2);
break;
case 2:
start3=add(start1,start2);
printf("List added\n");
break;
case 3:
disp(start3);
break;
case 4:
printf("Thank you!\n");
}
}while(opt>=1&&opt<4);
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
printf("Enter more val(-1 to exit)\n");
scanf("%d",&x);
}//end of while loop
return start;
}



void disp(NODE start)
{
NODE ptr=start;
while(ptr->next!=NULL)
{
printf("%d->",ptr->data);
ptr=ptr->next;
}
printf("%d",ptr->data);
}	



NODE add(NODE start1,NODE start2)
{
NODE ptr1=start1,ptr2=start2,ptr;
NODE new_node;
while(ptr1!=NULL && ptr2!=NULL)
{
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=ptr1->data+ptr2->data;
new_node->next=NULL;
if(start3==NULL)
{
start3=new_node;
ptr=start3;
}
else
{
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
}
ptr1=ptr1->next;
ptr2=ptr2->next;
}

if(ptr1==NULL || ptr2==NULL)
{
if(ptr1!=NULL)
{
while(ptr1!=NULL)
{
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=ptr1->data;
new_node->next=NULL;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
ptr1=ptr1->next;
}
//ptr1=ptr1->next;
}
else if(ptr2!=NULL)
{
while(ptr2!=NULL)
{
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=ptr2->data;
new_node->next=NULL;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
ptr2=ptr2->next;
}
}
}
return start3;
}

