#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct employee
{
char name[40];
int id;
float basicsal;
int roll;
struct employee *next;
}*NODE;
NODE start=NULL;
NODE create(NODE);
NODE sort(NODE);
void disp(NODE);
main()
{
int i;
for(i=0;i<3;i++)
{ 
start=create(start);
}
start=sort(start);
disp(start);
}
NODE create(NODE start)
{
NODE new_node;
char n[40];
int id1;
float bs;
printf("Enter name,ID,Basic salary respectively\n");
scanf("%s%d%f",n,&id1,&bs);
new_node=(NODE)malloc(sizeof(struct employee));
strcpy(new_node->name,n);
new_node->id=id1;
new_node->basicsal=bs;
if(start==NULL)
{
start=new_node;
new_node->next=NULL;
}
else{
new_node->next=start;
start=new_node;
}
return start;
}
NODE sort(NODE start)
{
int j,i,c=3,t;
NODE ptr,save,save1;
//ptr=start;
//save1=start; 
save=start;
while(save!=NULL)
{ ptr=save;
while(ptr!=NULL)
{
if((ptr->basicsal<ptr->next->basicsal)&& ptr->next!=NULL)
{
t=ptr->next->basicsal;
save1=ptr->next;
//ptr->basicsal=ptr->next->basicsal;
//ptr->next->basicsal=t;
}
else
ptr=ptr->next;
}
save->basicsal=t+save->basicsal;
save1->basicsal=save->basicsal-t;
save->basicsal=save->basicsal-t;
save=save->next;
}
return start;
}
void disp(NODE start)
{
NODE new_node;
new_node=start;
while(new_node!=NULL)
{
printf("Name: %s\n ID: %d\n Basicsalary: %f\n\n",new_node->name,new_node->id,new_node->basicsal);
new_node=new_node->next;
}
}
