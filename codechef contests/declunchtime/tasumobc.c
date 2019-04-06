#include<stdio.h>
long long int fact(int no)
{
    long long a=1,i;
    for(i=1;i<=no; i++)
    a*= i;
    return a;
}
int main()
{
int t;
scanf("%d",&t);
long long int n,i,s=0;
while(t--)
{
    s=0;

for(i=0;i<=n;i++)
{
s+=((long long int)(fact(n))/(fact(i)*fact(n-i)))%3;
}
printf("%lld\n",s%1000000007);
}
return 0;
}
