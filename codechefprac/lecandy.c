#include<stdio.h>
int main()
{
int t,n,i;
long long int x,c;
scanf("%d",&t);
while(t--)
{//flag=0;
//sum=0;
scanf("%d%lld",&n,&c);
for(i=0;i<n;i++)
{
scanf("%lld",&x);
c-=x;
   // sum+=x;
    //printf("%d",sum);
}
if(c<0) printf("No\n");
else printf("Yes\n");
}
return 0;
}
