#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int a[200001],i,j;
int partition(int l,int h)
{
   int pivot,t;
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
   t=a[i];//=a[i]+a[j];
   a[i]=a[j];//-a[j];
   a[j]=t;//a[i]-a[j];
   }
   else return j;
   }
}
void quicksort(int p,int r,int mid)
{
if(p<r)
{
int q=partition(p,r);
if(q==mid)
    return;
quicksort(p,q,mid);
quicksort(q+1,r,mid);
}
}
int main()
{
    int n,k;
    scanf("%d",&n);
    for(k=0;k<n;k++)
    scanf("%d",&a[k]);
    quicksort(0,n-1,n/2);
    printf("%d\n",a[n/2]);
    return 0;
}
