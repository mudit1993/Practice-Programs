#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<malloc.h>
struct node
{    int no;
    struct node *next;
}*NODE;
struct node *arr[1001];
int dist[1001],que[1001],fro,bac,chk[1001];
void push()
{
    struct node *ptr=arr[que[fro]]->next;
    while(ptr!=NULL)
    {
        if(chk[ptr->no]==0)
       {
           que[bac++]=ptr->no;
           dist[ptr->no]=dist[que[fro]]+1;
           chk[ptr->no]=1;
        }
        ptr=ptr->next;
    }
    fro++;
}
int main() {

    unsigned int t,n,m,a,b,i,start,m1;
    struct node *ptr=NULL;
    struct node *new_node;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%u%u",&n,&m);
        for(i=0;i<=n;i++)
        {
            arr[i]=(struct node*)malloc(sizeof(struct node));
            arr[i]->no=i;
            arr[i]->next=NULL;
        }
        m1=m;
        while(m1--)
        {
            scanf("%u%u",&a,&b);
            ptr=arr[a];
            while(ptr->next!=NULL && ptr->no!=b)
            {
                ptr=ptr->next;
            }
            if(ptr->next==NULL)
            {
                new_node=(struct node*)malloc(sizeof(struct node));
                new_node->no=b;
                new_node->next=NULL;
                ptr->next=new_node;
            }
             ptr=arr[b];
            while(ptr->next!=NULL && ptr->no!=a)
            {
                ptr=ptr->next;
            }
            if(ptr->next==NULL)
            {
                new_node=(struct node*)malloc(sizeof(struct node));
                new_node->no=a;
                new_node->next=NULL;
                ptr->next=new_node;
            }
         }
            for(i=0;i<=n;i++)
        {
            dist[i]=-1;
            chk[i]=0;
        }
        scanf("%u",&start);
        fro=bac=0;
        que[bac++]=start;
        dist[start]=0;
        chk[start]=1;
        while(fro!=bac)
        {
            push();
        }
        for(i=1;i<=n;i++)
        {
            if(dist[i]>0)
            printf("%u ",dist[i]*6);
            else if(dist[i]==-1)
                printf("-1 ");
            //printf("%u ",que[i]);
        }
       // for(i=bac;i<=n-1;i++)
         //   printf("-1 ");


        //printf("hi");

        /*for(i=1;i<=n;i++)
        {
            ptr=arr[i];
            while(ptr!=NULL)
            {printf("%u, ",ptr->no);
            ptr=ptr->next;}
            printf("\n");
            //arr[i]->next=NULL;
        }*/
        printf("\n");
    }
    return 0;
}
