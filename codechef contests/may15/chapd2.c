#include<stdio.h>
#include<string.h>
long long int gcd(long long int a,long long int b)
{
    long long int c;
    while(b!=0)
    {

        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int t;
    long long int i,a,b,a1,quo,g;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
       if((b%2)==0 && (a%2)==1) {printf("No\n");continue;}
        g=0;
        quo = b;
    while(g!=1){
        g=gcd(a,quo);  // finds the gcd of a and factors of b
        quo=(long long int)quo/g; // new factors
       //printf("%lld\n",quo);
    }

        if(quo==1)
            printf("Yes\n");
        else
            printf("No\n");
}
return 0;
}
