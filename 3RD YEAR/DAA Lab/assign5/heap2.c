#include<stdio.h>
int a[50];
void maxheapify(int i,int size)
{
int l=(2*i),r=(2*i)+1,t;
/*int large =i;
if(a[l]>a[large] && l<=size)
large=l;
if(a[r]>a[large] && r<=size)
large=r;
//printf("large-%d i=%d,l=%d,r=%d",large,i,l,r);
if(large!=i)
{
a[i]=a[i]+a[large];
a[large]=a[i]-a[large];
a[i]=a[i]-a[large];
maxheapify(large,size);
}
*/
if(l>size || r>size)
{
return;
}
else
{
maxheapify(l,size);
maxheapify(r,size);
if(a[i]<a[l])
{
    t=a[i];
    a[i]=a[l];
    a[l]=t;
/*a[i]=a[i]+a[l];
a[l]=a[i]-a[l];
a[i]=a[i]-a[l];
*/}
if(a[i]<a[r])
{
    t=a[i];
    a[i]=a[r];
    a[r]=t;/*
a[i]=a[i]+a[r];
a[r]=a[i]-a[r];
a[i]=a[i]-a[r];
*/}
}
}
void minheapify(int i,int size)
{

int l=2*i,r=2*i+1,t;
/*int large =i;
if(a[l]<a[large] && l<=size)
large=l;
if(a[r]<a[large] && r<=size)
large=r;
if(large!=i)
{
a[i]=a[i]+a[large];
a[large]=a[i]-a[large];
a[i]=a[i]-a[large];
minheapify(large,size);
}*/
if(l>size || r>size)
{
return;
}
else
{
minheapify(l,size);
minheapify(r,size);
if(a[i]>a[l])
{
   t=a[i];
    a[i]=a[l];
    a[l]=t;
/*a[i]=a[i]+a[l];
a[l]=a[i]-a[l];
a[i]=a[i]-a[l];
*/
}
if(a[i]>a[r])
{
    t=a[i];
    a[i]=a[r];
    a[r]=t;
/*a[i]=a[i]+a[r];
a[r]=a[i]-a[r];
a[i]=a[i]-a[r];*/
}
}
}
void main()
{
int i,ch;
printf("Maxheap(press 1) min heap (press 2)\n");
scanf("%d",&ch);
int n;
printf("Enter array size\n");
scanf("%d",&n);
printf("Enter %d elements\n",n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
if(ch==1)
{
maxheapify(1,n);
printf("After Max heapify");
for(i=1;i<=n;i++)
printf("%d ",a[i]);
}
else if(ch==2)
{

minheapify(1,n);
printf("After Min heapify");
for(i=1;i<=n;i++)
printf("%d ",a[i]);
}
printf("\n");

}
