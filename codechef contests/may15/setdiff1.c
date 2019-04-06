#include<stdio.h>
long long int arr[100005];
void merge(int low,int mid,int high)
{
int i=low,j=mid+1,k=low,q;
long long int b[high];
while(i<=mid && j<=high)
{
if(arr[i]<arr[j])
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
int t,n,n1,i,k,j;
long long int sum,inp,power;
scanf("%d",&t);
while(t--)
{
    sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&inp);
        arr[i]=inp;
    }
    mergesort(0,n-1);
    k=0;
    n1=n-1;
    power=1;
    while(k!=n1){
    power=(power*2)%1000000007;
    k++;
    //printf("%lld,",sum);
    for(i=0,j=i+k;j<n;i++,j++)
    {
        sum = (sum+(power*(arr[j]-arr[i]))%1000000007)%1000000007;
      //  printf("%lld,",sum);
    }
    }
    printf("%lld\n",(long long int)sum/2);
}
return 0;
}
