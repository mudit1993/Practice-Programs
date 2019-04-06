#include<stdio.h>
int main()
{
int t,n,a[100001],i,maxx,no;

scanf("%d",&t);
while(t--)
{
    maxx=0;
    for(i=0;i<100001;i++)
        a[i]=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&no);
a[no]++;
if(maxx<a[no]) maxx=a[no];
}
printf("%d\n",n-maxx);
}
return 0;
}
