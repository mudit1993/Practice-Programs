#include<stdio.h>
int i,j;
long long int c[100000],b[100000];
int partition(int l,int h)
{
    long long int t;
   int pivot;
   pivot=c[l];
   i=l-1;
   j=h+1;
   while(1)
   {
   do{
   j--;
   }while(c[j]<pivot);
      do{
   i++;
   }while(c[i]>pivot);
   if(i<j)
   {
   t=c[i];
   c[i]=c[j];
   c[j]=t;
   t=b[i];
   b[i]=b[j];
   b[j]=b[i];
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
    int t,n,k,m;
    double f,sum,minn;

    scanf("%d",&t);
    while(t--)
    {
        minn=100000000.0f;
        scanf("%d",&n);
        for(k=0;k<n;k++)
        {
            scanf("%lld%lld",&c[k],&b[k]);

        }
        //quicksort(0,n-1);
        for(m=0;m<n;m++)
        {
            for(k=m+1;k<n;k++)
            {
                sum=((double)(abs(c[m]-c[k]))/2)+((double)(abs(b[m]-b[k]))/2);
                if(sum<minn)
                {
                    minn=sum;
                }
               // else sum=0;
            }
        }
        //        f=(float)(a[n-1]+a[n-2])/2;
        printf("%0.6f",minn);

    }
return 0;
}

