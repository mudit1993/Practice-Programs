#include<stdio.h>
#include<malloc.h>
struct node* sorts(struct node*,int);
struct node{
int no;
struct node *next;
};
int main()
{
struct node *ptr=NULL,*start=NULL,*newnode;
int n,s,i;
scanf("%d",&s);
for(i=0;i<s;i++)
{
    scanf("%d",&n);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->no=n;
    if(start==NULL)
    {
        start=newnode;
        newnode->next=NULL;
    }
    else{
            ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
}

start=sorts(start,s);
ptr=start;
while(ptr!=NULL)
{
     printf("%d ",ptr->no);
     ptr=ptr->next;
}
return 0;
}
struct node* sorts(struct node* start,int s)
{
    struct node* ptr,*prev,*first,*second;
    int cnt=0;
    second=first=ptr=prev=start;
    ptr=ptr->next;
    if(s==2)
    {
        if(ptr->no<prev->no)
        {
            start=ptr;
            ptr->next=prev;
            prev->next=NULL;
        }
        return start;
    }
    while(ptr!=NULL && (prev->no < ptr->no))
    {
        prev=prev->next;
        ptr=ptr->next;
        cnt++;
    }
    //printf("hi");
    s=s-cnt;
    //    printf("prev- %d, ptr- %d\n",prev->no,ptr->no);
    while(s-- && ptr!=NULL){
            first=second=start;
    while(first!=NULL && ptr!=NULL && (first->no <= ptr->no))
    {
        second=first;
        first=first->next;
    }
    if(first!=NULL && ptr!=NULL)
    {
          //7printf("first- %d, second- %d start- %d ptr- %d prev- %d\n",first->no,second->no,start->no,ptr->no,prev->no);
        if(first==start)
        {
            start=prev->next;
            prev->next=start->next;
            start->next=first;
            ptr=prev->next;
            //printf("prev- %d, ptr- %d start- %d\n",prev->no,ptr->no,start->no);
        }
        else if(ptr->next != NULL){
              //  printf("hi");
        second->next=prev->next;
        prev->next = ptr->next;
        ptr->next=first;
        ptr=prev->next;
        }
        else{
              //   printf("prev- %d, ptr- %d start- %d\n",prev->no,ptr->no,second->no);
          ptr->next = second->next;
          second->next=ptr;
           prev->next=NULL;
        break;
        }
    }
    if(prev->no < ptr->no) break;
    //     printf("prev- %d, ptr- %d start- %d\n",prev->no,ptr->no,start->no);
    }
    //printf("prev- %d, ptr- %d start- %d\n",prev->no,ptr->no,start->no);


    return start;
};
