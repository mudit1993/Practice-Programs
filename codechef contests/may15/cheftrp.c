#include<stdio.h>
long int arr[100000];
void merge(int low,int mid,int high)
{
int i=low,j=mid+1,k=low,q;
long int b[high];
while(i<=mid && j<=high)
{
if(arr[i]>arr[j])
{
b[k]=arr[i];
i++;
}
else {
b[k]=arr[j];
j++;
}
k++;
}
if(i>mid)
{
for(;j<=high;)
{
b[k++]=arr[j++];
}
}
else
for(;i<=mid;)
b[k++]=arr[i++];
for(q=low;q<=high;q++)
{
arr[q]=b[q];
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
    int t,n,i;
    long int sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        mergesort(0,n-1);
    if(arr[n-1]<2)
    {
        printf("-1\n");
        continue;
    }
    for(i=0;i<n-1;i++)
    {
        sum+=arr[i];
    }
    printf("%ld\n",sum+2);
    }
return 0;
}
