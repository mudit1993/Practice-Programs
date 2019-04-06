#include<stdio.h>
int main()
{
int t,n,c,m,choc,wrap,free;
scanf("%d",&t);
while(t--)
{
    choc=wrap=free=0;
scanf("%d%d%d",&n,&c,&m);
choc=n/c;
wrap=choc;
while(wrap/m!=0)
{
    free=wrap/m;
    choc+=free;
  wrap=(wrap-m)+free;
}
//6 2 2
printf("%d\n",choc);
}
return 0;
}
