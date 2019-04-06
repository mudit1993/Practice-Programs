#include<stdio.h>
#include<malloc.h>
typedef struct node
{
int data;
struct node *next;
}*NODE;
NODE start=NULL;
NODE create(NODE);
NODE ascend(NODE);
NODE descend(NODE);
void disp(NODE);
int c=0;
main()
{
int opt;
do{
printf("\nMain Menu\n");
printf("1)Create\n");
printf("2)Sort in ascending order\n");
printf("3)sort in descending order\n");
printf("4)Display\n");
printf("5)Exit\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
start=create(start);
printf("Link list created with %d nodes\n",c);
break;
case 2:
start=ascend(start);
printf("Sorted in ascending order!\n");
break;
case 3:
start=descend(start);
printf("Sorted in descending order!\n");
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
{ c++;
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

NODE ascend(NODE start)
{
    int i,j;
    NODE ptr,prev,prev1;
    for(i=0;i<c;i++)
    { ptr=prev=prev1=start;
        ptr=ptr->next;
        for(j=0;j<c-i-1;j++)
        {
            if(prev->data>ptr->data)
            {
                if(j==0)
                {
                    start=prev->next;
                    prev1=start;
                }
                prev->next=ptr->next;
               ptr->next=prev;
               if(j>0)
                {
               while(prev1->next!=prev)
               prev1=prev1->next;
               prev1->next=ptr;
                }
               ptr=prev->next;

            }
            else
             {

                prev=ptr;
                ptr=ptr->next;
                while(prev1->next!=prev)
                    prev1=prev1->next;
             }
        }
    }
    return start;
}

NODE descend(NODE start)
{
    int i,j;
    NODE ptr,prev,prev1;
    for(i=0;i<c;i++)
    { ptr=prev=prev1=start;
        ptr=ptr->next;
        for(j=0;j<c-i-1;j++)
        {
            if(prev->data<ptr->data)
            {
                if(j==0)
                {
                    start=prev->next;
                    prev1=start;
                }
                prev->next=ptr->next;
               ptr->next=prev;
               if(j>0)
                {
               while(prev1->next!=prev)
               prev1=prev1->next;
               prev1->next=ptr;
                }
               ptr=prev->next;

            }
            else
             {

                prev=ptr;
                ptr=ptr->next;
                while(prev1->next!=prev)
                    prev1=prev1->next;
             }
        }
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
printf("%d",ptr->data);
}


