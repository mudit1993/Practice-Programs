#include<stdio.h>
int a[100000],b[100000],i,j;

int partition(int l,int h)
{
    int t;
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
   t=a[i];
   a[i]=a[j];
   a[j]=t;
   t=b[i];
   b[i]=b[j];
   b[j]=t;
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
    int t,n,k,bomb,maxx;
    scanf("%d",&t);
    while(t--)
    {
        bomb=1;
    scanf("%d",&n);
    for(k=0;k<n;k++)
          scanf("%d%d",&a[k],&b[k]);
    quicksort(0,n-1);
    maxx=b[0];
    for(k=1;k<n;k++)
    {
        if(a[k]<=maxx) {
            if(maxx<b[k])
            {
                maxx=b[k];
            }
            continue;
        }
        else{maxx=b[k]; bomb++;}
    }
    printf("%d\n",bomb);
    }
return 0;
}

