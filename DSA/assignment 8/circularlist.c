#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
}*NODE;
NODE start=NULL;
NODE create(NODE);
NODE delete_val(NODE);
NODE delete_pos(NODE);
void disp(NODE);
main()
{
int opt;
do{
printf("\nMain Menu\n");
printf("1)Create\n");
printf("2)Delete value\n");
printf("3)Delete position\n");
printf("4)Display\n");
printf("5)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
start=create(start);
printf("Link list created\n");
break;
case 2:
start=delete_val(start);
printf("Number deleted\n");
break;
case 3:
start=delete_pos(start);
break;
case 4:
disp(start);
break;
case 5:
printf("Thank you!\n");
}
}while(opt>=1&&opt<5);
}
NODE create(NODE start)
{

int x;NODE ptr;
printf("Enter val(-1 to exit)\n");
scanf("%d",&x);
while(x!=-1)
{
NODE new_node;
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=x;
if(start==NULL)
{
start=new_node;
new_node->next=start;
ptr=new_node;
}
else
{
new_node->next=start;
ptr->next=new_node;
start=new_node;
}

printf("Enter more val(-1 to exit)\n");
scanf("%d",&x);
}//end of while loop
return start;
}

NODE delete_val(NODE start)
{
int val,c=1,c1=1,flag=0,flag1=0;
NODE ptr,prev,ptr1;
ptr=prev=start;
printf("Enter a value to be deleted\n");
scanf("%d",&val);
while(ptr->next!=start)
{if(ptr->data==val)
c++;
ptr=ptr->next;
}
if(ptr->data==val)
    c++;
ptr1=ptr;
//ptr=start;
while(c1<c)
{ptr=prev=start;
flag=0;
if(start == NULL)
printf("Link list does not exist\n");
else
{
	while((ptr!=start||flag==0)&& ptr->data!=val)
	{
	prev=ptr;
	ptr=ptr->next;
	flag=1;
	}
	if(ptr==start && ptr->next==start)
	{start=NULL;flag1=1;}
	else if(ptr==start  && flag==1 && flag1==0)
	{
	printf("Element does not exist\n");break;
	}
	else if(ptr==start && ptr->next!=start)
	{flag1=1;
	start=ptr->next;
	ptr1->next=start;
	}
	else
	{
	flag1=1;
	prev->next=ptr->next;
	}free(ptr);
}
c1++;
}
return start;
}
NODE delete_pos(NODE start)
{
NODE ptr1,ptr,prev;
int pos,c=1,flag=0;
ptr=prev=ptr1=start;
while(ptr1->next!=start)
ptr1=ptr1->next;
printf("Enter a position to be deleted\n");
scanf("%d",&pos);
if(start==NULL)
printf("Link list does not exist\n");
else
{
	while((ptr!=start||flag==0) && c<pos)
	{
	prev=ptr;
	ptr=ptr->next;
	c++;
	flag=1;
	}
	if(c==1)
	{
	if(ptr->next==start)
	{start=NULL;free(ptr);}
	else
	{
	start=ptr->next;
	ptr1->next=start;
    free(ptr);
	}
	}
	else if(ptr==start && flag==1)
	{
    printf("Position invalid\n");
	}
	else
	{prev->next=ptr->next;
	free(ptr);
	}
}
return start;
}
void disp(NODE start)
{int c=0;
NODE ptr=start;
printf("List is:\n");
while(ptr->next!=start)
{c==1;
printf("%d->",ptr->data);
ptr=ptr->next;
}
if(start==NULL)
printf("empty\n");
else if(c==0)
printf("%d",ptr->data);
}
