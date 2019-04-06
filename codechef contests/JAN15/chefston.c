#include<stdio.h>
int main()
{
int t,n,i;
long long int k,a[100000],x,maxx;
scanf("%d",&t);
while(t--)
{
maxx=0;
scanf("%d%lld",&n,&k);
for(i=0;i<n;i++)
{
scanf("%lld",&x);
a[i]=k/x;
}
for(i=0;i<n;i++)
{
    scanf("%lld",&x);
    if((a[i]*x)>maxx)
        maxx=a[i]*x;
}
printf("%lld\n",maxx);
}
return 0;
}
