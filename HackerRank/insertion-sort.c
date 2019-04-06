#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
long long int a[100000],cnt=0;
void merge(int low,int mid,int high)
{
long long int i=low,j=mid+1,k=low,q;
long long int b[high];
while(i<=mid && j<=high)
{
if(a[i]<=a[j])
{
b[k]=a[i];
i++;
}
else {
b[k]=a[j];
cnt+=(mid-i+1);
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

int main(void) {
    long long int N,t,i;
    scanf("%lld", &t);
    while(t--){
        cnt=0;
    scanf("%lld", &N);
    for(i = 0; i < N; i++)
        scanf("%lld", &a[i]);
    mergesort(0,N-1);
    printf("%lld\n",cnt);
    }
    return 0;
}
