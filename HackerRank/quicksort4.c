#include<stdio.h>
int a[20],n,quick,ins;
int partition(int l,int h)
{
   int pivot,t,i,j;
   pivot=a[h];
   i=l;j=l;
    while(i<=h && j<=h){
        if(a[i]>pivot)
            {
            i++;continue;
        }
   t=a[j];
   a[j]=a[i];
   a[i]=t;
   quick++;
    i++;j++;
    }
    return j-1;
}
void quicksort(int p,int r)
{
    if((r-p)>=1)
    {
        int q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}
void insertionSort(int ar_size, int *  ar) {
    int temp,k,i,j;
    for(j=1;j<ar_size;j++)
    {
        temp=ar[j];
        i=j-1;
    while(i>=0 && ar[i]>temp)
    {
        ar[i+1]=ar[i];
        i--;
    ins++;
    }
    ar[i+1]=temp;

   }
}
int main()
{
    int i,b[10000];
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
 for(i=0;i<n;i++)
        b[i]=a[i];
insertionSort(n,b);
quick=ins=0;
quicksort(0,n-1);
printf("%d\n",abs(ins-quick));
   return 0;
}

