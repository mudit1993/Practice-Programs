#include<stdio.h>
#include<malloc.h>
typedef struct node
{
long data;
struct node *next;
}*NODE;
NODE start=NULL;
NODE create(NODE,long);
void last(NODE,long);

int main()
{
    long n;
    do{
            scanf("%ld",&n);
            if(n==0)
                goto bye;
    }while(n>200000 || n<0);
    if(n!=0)
    {
        if(n==1)
            printf("1\n");
        else{
    start=create(start,n);
    last(start,n);
        }
    }
    while(n!=0)
    {

    do{
            scanf("%ld",&n);
            if(n==0)
                goto bye;
    }while(n>200000 || n<0);
    if(n==1)
        printf("1\n");
    else{
    start=NULL;
    start=create(start,n);
    last(start,n);
    }
}
bye:;
}

NODE create(NODE start,long n)
{
NODE new_node;
while(n!=0)
{
new_node=(NODE)malloc(sizeof(struct node));
new_node->data=n;
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
n--;
}//end of while loop
return start;
}


void last(NODE start,long n)
{
    NODE ptr=start,endd=start;
    while(endd->next!=NULL)
        endd=endd->next;
    while(n!=2)
        {
        start=start->next;
        free(ptr);
        ptr=start;
        start=start->next;
        endd->next=ptr;
        endd=endd->next;
        n--;
            }
            printf("%d\n",start->next->data);
            while(start!=NULL)
            {
                ptr=start;
                start=start->next;
                free(ptr);
            }

}
