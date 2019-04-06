#include<stdio.h>
int gcd(int a,int b)
 {int t;
        while(b!=0)
    {
       t=b;
       b=a%b;
       a=t;
    }
    return a;
 }
int main()
{
    int t;
    long long int a,b,c,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        n=gcd(a,b);
        a=-1;b=1;
        for(i=0;i<=n;i++)
        {
            c=(a+b)%1000000007;
            a=b;
            b=c;
        }
    printf("%lld\n",c);
    }
return 0;
}
