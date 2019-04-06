#include<stdio.h>
int a[50];
void maxheapify(int i,int size)
{
/*int l=(2*i),r=(2*i)+1;
int large =i;
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
if(2*i>size || (2*i)+1 >size)
{
return;
}
else
{
maxheapify(2*i,size);
maxheapify(((2*i)+1),size);
if(a[i]<a[2*i])
{
a[i]=a[i]+a[2*i];
a[2*i]=a[i]-a[2*i];
a[i]=a[i]-a[2*i];
}
if(a[i]<a[(2*i)+1])
{
a[i]=a[i]+a[(2*i)+1];
a[(2*i)+1]=a[i]-a[(2*i)+1];
a[i]=a[i]-a[(2*i)+1];
}
}
}
void minheapify(int i,int size)
{
/*
int l=2i,r=2i+1;
int large =i;
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
if(2*i>size || (2*i)+1 >size)
{
return;
}
else
{
minheapify(2*i,size);
minheapify(((2*i)+1),size);
if(a[i]>a[2*i])
{
a[i]=a[i]+a[2*i];
a[2*i]=a[i]-a[2*i];
a[i]=a[i]-a[2*i];
}
if(a[i]>a[(2*i)+1])
{
a[i]=a[i]+a[(2*i)+1];
a[(2*i)+1]=a[i]-a[(2*i)+1];
a[i]=a[i]-a[(2*i)+1];
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
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
printf("\n");

}
