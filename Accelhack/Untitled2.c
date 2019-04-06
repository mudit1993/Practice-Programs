#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    long long int n,sq;
scanf("%d",&t);
while(t--)
{
scanf("%lld",&n);
sq=pow(n,0.5);
printf("%lld\n",sq);
}
return 0;
}
