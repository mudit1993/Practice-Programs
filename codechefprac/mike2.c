#include<stdio.h>
long long int A[1000000],i,j;
int partition(int l,int h)
{
   long long int pivot;
   pivot=A[l];
   i=l-1;
   j=h+1;
   while(1)
   {
   do{
   j--;
   }while(A[j]>pivot);
      do{
   i++;
   }while(A[i]<pivot);
   if(i<j)
   {
   A[i]=A[i]+A[j];
   A[j]=A[i]-A[j];
   A[i]=A[i]-A[j];
   }
   else return j;
   }
}
void quicksort(int p,int r)
{
if(p<r)
{
long long int q=partition(p,r);
quicksort(p,q);
quicksort(q+1,r);
}
}



int main()
{
long long int N,X,sum=0,f=0,s=0;
scanf("%lld%lld",&N,&X);
for(i=0;i<N;i++)
  {
     scanf("%lld",&A[i]);
  }
  f=N;
quicksort(0,N-1);
i=0;
while(X!=0 && i<N)
{
    if(A[i]%2==0)//even
    {
        if((X-(A[i]/2))>=0)
        {
             X-=(A[i]/2);
        A[i]=(A[i]/2);
        f--;
        }
        else break;
    }
    else{
            if((X-((A[i]/2)+1))>=0)
        {
            X-=((A[i]/2)+1);
        A[i]/=2;
        f--;
        }
        else break;
   }
   i++;
}

for(i=0;i<N;i++) {
    if(A[i]==0)s++;
}
i=0;
while(X!=0 && i<N)
{
    if(X-A[i]>=0 && A[i]!=0)
    {
        X-=A[i];
        A[i]=0;
        s++;
    }
   // else break;
    i++;
}
printf("%lld %lld\n",f,s);
/*for(i=0;i<N;i++)
printf("%d ",A[i]);*/
return 0;
}
