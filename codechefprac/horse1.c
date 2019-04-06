#include<stdio.h>
long long int arr[5000];
int i,j;
int partition(int a[],int l,int h)
{
   int pivot;
   pivot=a[l];
   i=l-1;
   j=h+1;
   while(1)
   {
   do{
   j--;
   }while(a[j]>pivot);
      do{
   i++;
   }while(a[i]<pivot);
   if(i<j)
   {
   a[i]=a[i]+a[j];
   a[j]=a[i]-a[j];
   a[i]=a[i]-a[j];
   }
   else return j;
   }
}
void quicksort(int a[],int p,int r)
{
if(p<r)
{
int q=partition(a,p,r);
quicksort(a,p,q);
quicksort(a,q+1,r);
}
}
int main()
{
int n,t;
long long int minn;
scanf("%d",&t);
while(t--)
{
    scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%lld",&arr[i]);
quicksort(arr,0,n-1);
for(i=0;i<n;i++) printf("%d,",arr[i]);
minn=abs(arr[0]-arr[1]);
printf("\n%d\n",minn);
for(i=1;i<n-1;i++)
{
    if(abs(arr[i]-arr[i+1])<minn)
    minn=abs(arr[i]-arr[i+1]);
}
printf("%d\n",minn);
}
return 0;
}
