#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
}*NODE;
NODE start1=NULL;
NODE start2=NULL;
NODE create(NODE);
NODE merge(NODE,NODE);
void disp(NODE);
main()
{
int opt,c=0;
do{
printf("\nMain Menu\n");
printf("1)Create\n");
printf("2)Merge\n");
printf("3)Display\n");
printf("4)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
if(c==0){
start1=create(start1);
printf("Link list created\n");
disp(start1);
c++;
}
start2=create(start2);
printf("Link List created\n");
if(start2!=NULL)
disp(start2);
break;
case 2:
start1=merge(start1,start2);
break;
case 3:
disp(start1);
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


NODE merge(NODE start1,NODE start2)
{
if(start2!=NULL)
{
NODE ptr=start1;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=start2;
}
return start1;
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
}


