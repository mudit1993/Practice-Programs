#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
}*NODE;
NODE start=NULL;
NODE create(NODE,int);
void disp(NODE);
NODE rev(NODE);
NODE revnode(NODE,int);
int main()
{
int opt,no,pos;
//printf("Enter number of nodes\n");
//scanf("%d",&no);
do{
printf("\nMain Menu\n");
printf("1)Create\n2)reverse\n3)display\n4)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter number of nodes\n");
scanf("%d",&no);
start=create(start,no);
printf("List created\n");
break;
case 2:
    printf("Enter position from where to be reversed\n");
    scanf("%d",&pos);
start=revnode(start,pos);
printf("List reversed \n");
break;
case 3:
disp(start);
break;
case 4:printf("Execution Terminated!!\n");
}
}while(opt>=1 && opt<=3);
}


NODE create(NODE start,int no)
{
NODE new_node,ptr=start;
int c,i=0;
while(i<no)
{
new_node=(NODE)malloc(sizeof(struct node));
printf("Enter Data\n");
scanf("%d",&c);
new_node->data=c;
new_node->next=NULL;
if(start==NULL)
{
start=new_node;
ptr=start;
}
else
{
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=new_node;
}
i++;
}
return start;
}




/*NODE rev(NODE start)
{
NODE ptr=start;
int i=0,cnt=0;
while(ptr!=NULL)
{cnt++;
ptr=ptr->next;
}
ptr=start;
while(i<3)
{
ptr=ptr->next;
i++;
}
ptr->data=ptr->data+ptr->next->next->data;
ptr->next->next->data=ptr->data-ptr->next->next->data;
ptr->data=ptr->data-ptr->next->next->data;
return start;
}*/
NODE revnode(NODE start,int pos)
{
NODE ptr=start,prev=start,ptr1;
int i=0;
while(i<pos-1)
{
prev=ptr;
ptr=ptr->next;
i++;
}
ptr1=ptr;
while(ptr1->next!=NULL)
ptr1=ptr1->next;
prev->next=ptr1;
ptr1=ptr;
prev=prev->next;
while(prev!=ptr)
{
ptr1=ptr;
while(ptr1->next!=prev)
ptr1=ptr1->next;
prev->next=ptr1;
prev=prev->next;
}
ptr->next=NULL;
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
