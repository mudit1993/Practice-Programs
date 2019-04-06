#include<stdio.h>
long long int a[100000];
void merge(int low,int mid,int high)
{
int i=low,j=mid+1,k=low,q;
long long int b[high];
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
int main()
{
long long int n,cnt=0,sum=0;
int i,j;
scanf("%I64d",&n);
for(i=0;i<n;i++)
scanf("%I64d",&a[i]);
mergesort(0,n-1);
//for(i=0;i<n;i++)
//printf("%lld,",a[i]);
for(i=0;i<n;i++)
{
if(sum<=a[i])
{
    sum+=a[i];
   cnt++;
}
}
printf("%I64d\n",cnt);
return 0;
}
