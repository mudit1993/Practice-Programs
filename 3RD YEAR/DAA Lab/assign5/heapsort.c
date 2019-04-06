#include<stdio.h>
int a[50];
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

void main()
{
int i,ch,n,n1;
printf("Enter array size\n");
scanf("%d",&n);
printf("Enter %d elements\n",n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
n1=n;
while(n1){
buildheap(n1);
//printf("%d-%d\n",a[1],n1);
deleteheap(n1);
n1--;
}
for(i=1;i<=n;i++)
printf("%d ",a[i]);
printf("\n");

}
