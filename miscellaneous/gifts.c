#include<stdio.h>
int main()
{
int n,t,i;
scanf("%d",&t);
long long int fact=1;
while(t--)
{
    fact=1;
    scanf("%d",&n);
    if(n<=1) printf("0\n");
    else{
    for(i=2;i<=n;i++)
    {
    fact=fact*(i)*(i-1)%1000000007;
    }
printf("%lld\n",fact);
    }
}
return 0;
}
