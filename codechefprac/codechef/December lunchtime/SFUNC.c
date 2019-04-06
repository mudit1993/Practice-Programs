#include<stdio.h>
#include<math.h>
long coprime(long,long);
int main()
{
long N,K,M,i,s=0;
scanf("%ld%ld%ld",&N,&K,&M);
for(i=2;i<N;i++)
{
    if(coprime(N,i)==-1)
        s=s+pow(i,K);
}
printf("%ld",((s+1)%M));
return 0;
}


long coprime(long a,long b)
{
    long i=2,f=-1;
    while(i<=b)
    {
            if(a%i==0 && b%i==0)
            f=0;
            i++;
    }
    return f;
    }
