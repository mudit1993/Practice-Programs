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
     for(t=0;t<n;t++)
        printf("%d ",a[t]);
    printf("\n");
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

int main()
{
    int i;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quick=ins=0;
quicksort(0,n-1);
if(n==1)
    printf("%d\n",a[0]);
   return 0;
}

