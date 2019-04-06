#include<stdio.h>
#include<math.h>
int number(long long int n)
{
    long long int no;
    int  mid=15;
    no=pow(2,mid);
    while(no>n)
    {
        mid--;
        no=pow(2,mid);
    }
     while(no<n)
    {
        mid++;
        no=pow(2,mid);
    }

   // if(no==n) return mid;
    if(no>n) return (mid-1);
    else return(mid);
}
int main()
{
   long long int n,a[30];
    int i;
      for(i=1;i<=29;i++)
        a[i]=0;
    scanf("%lld",&n);
// printf("%lld",n);
        //i=number(n);
        //printf("%d ",i);
    while(n!=0)
    {
        i=number(n);
        //printf("i=%d\n",i);
        a[i]=pow(2,i);
        n-=pow(2,i);
    }
    for(i=1;i<=29;i++)
    {
        if(a[i]>0) printf("%lld ",a[i]);
    }
    printf("\n");
return 0;
}
