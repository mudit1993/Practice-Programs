#include<stdio.h>
int main()
{
    int t;
    long long int a,b,maxx;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a>b) maxx=a; else maxx=b;
        printf("%lld %lld\n",maxx,(a+b));
    }
return 0;
}
