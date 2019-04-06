#include<stdio.h>
int main()
{
int t,n,no,cnt=0,maxx,i;
long long int tot;
scanf("%d",&t);
while(t--)
{
    maxx=0;
    cnt=0;
    tot=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&no);
        if(maxx<no)
        {
            maxx=no;cnt=1;
        }
        else if(maxx==no) cnt++;
    }
   for(i=0;i<cnt;i++)
   {
       tot=tot*2%1000000007;
   }
        printf("%lld\n",tot-1);
}
return 0;
}
