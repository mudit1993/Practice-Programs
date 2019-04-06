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
NODE disp1(NODE);
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

NODE delete_val(NODE start)
{
int val,c=0,c1=0;
NODE ptr,prev;
ptr=prev=start;
printf("Enter a value to be deleted\n");
scanf("%d",&val);
while(ptr!=NULL)
{if(ptr->data==val)
c++;
ptr=ptr->next;
}
//ptr=start;
while(c1<c)
{ptr=prev=start;
if(start == NULL)
printf("Link list does not exist\n");
else
{
	while(ptr!=NULL && ptr->data!=val)
	{
	prev=ptr;
	ptr=ptr->next;
	}
	if(ptr==start && ptr->next==NULL)
	start=NULL;
	else if(ptr==NULL)
	{
	printf("Element does not exist\n");break;
	}
	else if(ptr==start && ptr->next!=NULL)
	start=ptr->next;
	else
	prev->next=ptr->next;
	free(ptr);
}
c1++;
}
return start;
}
NODE delete_pos(NODE start)
{
NODE ptr,prev;
int pos,c=1;
ptr=prev=start;
printf("Enter a position to be deleted\n");
scanf("%d",&pos);
if(start==NULL)
printf("Link list does not exist\n");
else
{
	while(ptr!=NULL && c<pos)
	{
	prev=ptr;
	ptr=ptr->next;
	c++;
	}
	if(c==1)
	{
	if(ptr->next==NULL)
	start=NULL;
	else
	start=ptr->next;
	}
	else if(ptr==NULL)
	printf("Postition invalid\n");
	else
	prev->next=ptr->next;
	free(ptr);
}
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
printf("%d\n",ptr->data);
disp1(start);
}
NODE disp1(NODE start1)
{ NODE rest=start1->next;
    if(!start1)
        return;
        //NODE rest=start1->next;// start1;
    if(!rest) return;

        return disp1(rest);
        start1->next->next=start1;
        start->next=NULL;
        start1=rest;
    printf("%d ",start1->data);

}


