#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int a[200001];
void merge(int low,int mid,int high)
{
long long int i=low,j=mid+1,k=low,q;
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
    long long int n,i,x[200000],y[200000],k=0,diff=20000005,d;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    mergesort(0,n-1);
    for(i=0;i<n-1;i++)
    {
        d=abs(a[i]-a[i+1]);
        if(d==diff)
        {
            x[k]=a[i];y[k]=a[i+1];
            k++;
        }
        else if(d<diff)
        {
            diff=d;
            k=0;
            x[k]=a[i];y[k]=a[i+1];
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        printf("%lld %lld ",x[i],y[i]);
    }
    return 0;
}

