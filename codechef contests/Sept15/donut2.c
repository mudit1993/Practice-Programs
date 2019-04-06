#include<stdio.h>
typedef long long int ll;
ll a[100001];
int main()
{
    ll t,n,m,i,chains,no;
    scanf("%lld",&t);
    while(t--)
    {
        for(i=0;i<=100000;i++)
            a[i]=0;
        scanf("%lld%lld",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%lld",&no);
            a[no]++;
        }
        chains=0;
        m--;
            for(i=1;i<=100000;i++)
            {
                while(i<m && a[i]>0)
                {
                chains+=i;
                m-=i;
                m--;
                a[i]--;
                }
                if(i>m)
                    break;
            }
        printf("%lld\n",chains+m);
    }
    return 0;
}
