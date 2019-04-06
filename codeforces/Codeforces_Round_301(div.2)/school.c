#include<stdio.h>
int a[1000],b[1000];
void minheapify(int i,int size)
{
int l=(2*i),r=(2*i)+1,t;
int large =i;
if(a[l]>a[large] && l<=size)
large=l;
if(a[r]>a[large] && r<=size)
large=r;
//printf("large-%d i=%d,l=%d,r=%d",large,i,l,r);
if(large!=i)
{
    t=a[i];
    a[i]=a[large];
    a[large]=t;
minheapify(large,size);
}
}
void heapify(int i,int size)
{
int l=(2*i),r=(2*i)+1,t;
int large =i;
if(a[l]>a[large] && l<=size)
large=l;
if(a[r]>a[large] && r<=size)
large=r;
//printf("large-%d i=%d,l=%d,r=%d",large,i,l,r);
if(large!=i)
{
    t=a[i];
    a[i]=a[large];
    a[large]=t;
heapify(large,size);
}
}
void buildheap(int size)
{
    int i;
    for(i=size/2;i>=1;i--)
    {
   heapify(i,size);
    }
}
void deleteheap(int size)
{
    int t;
    t=a[1];
    a[1]=a[size];
    a[size]=t;
   // size--;
   // heapify(1,size);
}
int main()
{
    int i,n,k,p,x,y,rem,k1,sum=0,j;
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    rem=n-k;
    for(i=1;i<=k;i++)
      {
          scanf("%d",&a[i]);
          sum+=a[i];
      }
      if((x-sum)<(n-k))
         printf("-1\n");
      else{      k1=k+1;
      j=0;
     // printf("%d\n",k1);
    for(i=k1;i<=n;i++)
    {
    if((x-(sum+y))>=(n-i))
    {
        a[i]=y;
        b[j++]=y;
        sum+=y;
    }
    else{
        a[i]=1;
        b[j++]=1;
        sum++;
    }
    }

k1=n;
while(k1){
buildheap(k1);
//printf("%d-%d\n",a[1],k1);
deleteheap(k1);
k1--;
}
//for(i=1;i<=n;i++)
//printf("%d ",a[i]);
//printf("%d\n",a[(n+1)/2]);
if(sum<=x && a[(n+1)/2]>=y)
{
    while(j--)
    printf("%d ",b[j]);
}
else printf("-1\n");
      }
return 0;
}
