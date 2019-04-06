#include<stdio.h>
int main()
{
int t;
long long int i,n,a,pack,k1,sum;

scanf("%d",&t);
while(t--)
{
    pack=0;
    sum=0;
scanf("%lld%lld",&n,&k1);
for(i=0;i<n;i++)
{
        scanf("%lld",&a);//each day items
        sum+=a;
        pack+=(sum/k1);// packets required
        //if(sum>=k1)
        sum%=k1;//  modulo ...  remaining items
        if(sum!=0)
            sum++;//adding bad bread
}
if((sum<k1 && sum!=0)||sum==k1)//remaining bread packet of which is not counted
printf("%lld\n",pack+1);
else
printf("%lld\n",pack);
}
return 0;
}
