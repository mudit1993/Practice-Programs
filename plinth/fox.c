#include<stdio.h>
int i,j;
long long int a[100000];
int partition(int l,int h)
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
void quicksort(int p,int r)
{
if(p<r)
{
int q=partition(p,r);
quicksort(p,q);
quicksort(q+1,r);
}
}
int main()
{
    int t,n,k;
    long long int c,b;
    double f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(k=0;k<n;k++)
        {
            scanf("%lld%lld",&c,&b);
            a[k]=abs(c-b);
        }
        quicksort(0,n-1);

       // f=(float)(a[n-1]+a[n-2])/2;
        printf("%0.6f",f);

    }
return 0;
}

