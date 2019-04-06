#include<stdio.h>
int a[50];
void heapify(int *a,int i,int size)
{
int l=2*i,r=(2*i)+1;
int large=i;int s;

if(a[l]>a[large] && l<=size)
large=l;
if(a[r]>a[large] && r<=size)
large=r;
if(large==i)
{
return;
}
else{
a[large]=a[large]+a[i];
a[i]=a[large]-a[i];
a[large]=a[large]-a[i];
heapify(a,large,size);
}
}
int build_heap(int *a,int size)
{
int i;
for(i=(size/2);i>=1;i--)
heapify(a,i,size);
return a[1];
}


void main()
{
int i,ch,n1;
int n,k=1;
printf("Enter array size\n");
scanf("%d",&n);
int b[n];
n1=n;
printf("Enter %d elements\n",n);
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
while(n1>=1){
b[k]=build_heap(a,n1);
for(i=1;i<=n-1;i++)
a[i]=a[i+1];
n1--;
k++;
}
printf("Sorted Array:");
for(i=1;i<=n;i++)
printf("%d ",b[i]);
printf("\n");
}
