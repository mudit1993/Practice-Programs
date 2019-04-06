#include<stdio.h>
#include<math.h>
long long int arr[100005];
void heapify(int i,int size)
{
int l=(2*i),r=(2*i)+1;
long long int t;
int large =i;
if(arr[l]>arr[large] && l<=size)
large=l;
if(arr[r]>arr[large] && r<=size)
large=r;
//printf("large-%d i=%d,l=%d,r=%d",large,i,l,r);
if(large!=i)
{
    t=arr[i];
    arr[i]=arr[large];
    arr[large]=t;
heapify(large,size);
}
}
void buildheap(int size)
{
    int i;
    for(i=size/2;i>=1;i--)
    {
   heapify(i,size);
    }
}
void deleteheap(int size)
{
    long long int t;
    t=arr[1];
    arr[1]=arr[size];
    arr[size]=t;
   // size--;
   // heapify(1,size);
}
int main()
{
int t,n,n1,i,k,j;
long long int sum,power;
scanf("%d",&t);
arr[0]=0;
while(t--)
{
    sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    n1=n;
    while(n1){
        buildheap(n1);
        //printf("%d-%d\n",a[1],n1);
        deleteheap(n1);
        n1--;
    }
    k=0;
    n1=n-1;
    power=1;
    while(k!=n1){
    power=(power*2)%1000000007;
    k++;
    //printf("%lld,",sum);
    for(i=1,j=i+k;i<=n1 && j<=n;i++,j++)
    {
        sum = (sum+(power*(arr[j]-arr[i])))%1000000007;
        //sum = (sum+(((long long int)pow(2,k-1)%1000000007)*(arr[j]-arr[i])))%1000000007;
       // printf("%lld,",sum);
    }
    }
    printf("%lld\n",sum/2);
}
return 0;
}
