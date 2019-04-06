#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int a[100000];
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
void mergesort(long long int p,long long int r)
{
if(p<r)
{
long long int q=(p+r)/2;
mergesort(p,q);
mergesort(q+1,r);
merge(p,q,r);
}
}
int main() {

long long int t,n,cnt,i,sum,no;
scanf("%lld",&t);
while(t--)
{
    sum=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    mergesort(0,n-1);
    cnt=1;
    no=a[0];
    for(i=1;i<n;i++)
    {
        if(no==a[i])
        {
            cnt++;
        }
        else{
            if(cnt>1)
                sum+=(cnt*(cnt-1));
            no=a[i];
            cnt=1;
        }
    }
    if(cnt>1)
        sum+=(cnt*(cnt-1));
    printf("%lld\n",sum);
}
    return 0;
}
