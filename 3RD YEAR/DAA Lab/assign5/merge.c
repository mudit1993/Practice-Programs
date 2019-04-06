#include<stdio.h>
int a[50];
void merge(int low,int mid,int high)
{
int i=low,j=mid+1,k=low,q;
int b[high];
while(i<=mid && j<=high)
{
if(a[i]<a[j])
{
b[k]=a[i];
i++;
}
else {
b[k]=a[j];
j++;
}
k++;
}
if(i>mid)
{
for(;j<=high;)
{
b[k++]=a[j++];
}
}
else 
for(;i<=mid;)
b[k++]=a[i++];
for(q=low;q<=high;q++)
{
a[q]=b[q];
}
}
void mergesort(int p,int r)
{
if(p<r)
{
int q=(p+r)/2;
mergesort(p,q);
mergesort(q+1,r);
merge(p,q,r);
}
}
void main()
{
int n,i;
printf("Enter Array size\n");
scanf("%d",&n);
printf("Enter %d elements\n",n);
  for(i=0;i<n;i++) 
  scanf("%d",&a[i]);
 mergesort(0,n-1);
 printf("Sorted Array\n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
} 
printf("\n");
}
