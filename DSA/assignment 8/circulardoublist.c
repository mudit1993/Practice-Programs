#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
struct node *prev;
}*NODE;
NODE start=NULL;
NODE create(NODE);
NODE delete_val(NODE);
NODE delete_pos(NODE);
void disp(NODE);
NODE insert_at(NODE);
main()
{
int opt;
do{
printf("\nMain Menu\n");
printf("1)Create\n");
printf("2)Insert\n");
printf("3)Delete value\n");
printf("4)Delete position\n");
printf("5)Display\n");
printf("6)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
start=create(start);
printf("Link list created\n");
break;
case 2:insert_at(start);
printf("Number inserted!\n");
break;
case 3:
start=delete_val(start);
printf("Number deleted\n");
break;
case 4:
start=delete_pos(start);
break;
case 5:
disp(start);
break;
case 6:
printf("Thank you!\n");
}
}while(opt>=1&&opt<6);
}




NODE create(NODE start)
{
    start=NULL;
int x;NODE ptr,ptr1;
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
new_node->prev=start;
ptr=new_node;
ptr1=new_node;
}
else
{
new_node->next=start;
ptr->next=new_node;
ptr1->prev=new_node;
new_node->prev=ptr;
start=new_node;
ptr1=ptr1->prev;
}
printf("Enter more val(-1 to exit)\n");
scanf("%d",&x);
}//end of while loop
return start;
}

NODE insert_at(NODE start)
{
    int pos,c=1,flag=0;
    NODE ptr=start;
    printf("Enter the position where you want to enter ..:");
    scanf("%d",&pos);
     while((ptr!=start|| flag==0) && c<pos)
    {
        flag=1;
        ptr=ptr->next;
        c=c+1;
    }
        if(c==pos)
    {
         NODE temp=(NODE)malloc(sizeof(struct node));
        printf("Enter the data..:\n");
        scanf("%d",&temp->data);
        if(pos==1)
          {
              temp->prev=start->prev;
              temp->next=start;
            start->prev->next=temp;
            start->prev=temp;
            start=temp;
          }
         else if(ptr==start && flag==1)
          {
              temp->next=ptr;
              temp->prev=ptr->prev;
              ptr->prev->next=temp;
              ptr->prev=temp;
          }
          else
            {
                temp->prev=ptr->prev;
                temp->next=ptr;
                ptr->prev->next=temp;
                ptr->prev=temp;
            }
    }
    else
        printf("Invalid Input\n");
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
	start->prev=ptr1;
	ptr1->next=start;
	}
	else
	{
	flag1=1;
	ptr->next->prev=prev;
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
	start->prev=ptr1;
	ptr1->next=start;
	free(ptr);}
	}
	else if(ptr==start && flag==1)
	printf("Position invalid\n");
	else
	{
	ptr->next->prev=prev;
	prev->next=ptr->next;
	free(ptr);
	}
}
return start;
}
void disp(NODE start)
{
int c=0;
NODE ptr1,ptr=start;
if(start==NULL)
    printf("List Empty\n");
else{
printf("Traversing forward\n");
while(ptr->next!=start)
{
c++;
printf("%d<->",ptr->data);
ptr=ptr->next;
}
printf("%d\nTraversing backwards:\n",ptr->data);
ptr1=ptr;
while(ptr->prev!=ptr1)
{c--;
printf("%d<->",ptr->data);
ptr=ptr->prev;
}
printf("%d",ptr->data);
}
}
