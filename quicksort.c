
#include<stdio.h>
int a[20],i,j;
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
void quicksort(int p,int r)
{
if(p<r)
{
int q=partition(p,r);
quicksort(p,q);
quicksort(q+1,r);
}
}
void main()
{
int n;
printf("Enter size of the array\n");
scanf("%d",&n);
printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quicksort(0,n-1);
for(i=0;i<n;i++)
printf("%d ",a[i]);
}

