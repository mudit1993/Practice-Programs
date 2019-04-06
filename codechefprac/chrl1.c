#include<stdio.h>
#include<math.h>
int main()
{
    int t,n,i,j;
    long long int k,a[11][2],maxx,wt,cost;

    scanf("%d",&t);
    while(t--)
    {
           // minn=100000001;
        maxx=wt=0;
        cost=0;
    scanf("%d%lld",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    }
    for(i=0;i<pow(2,n);i++)
    {wt=cost=0;
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                cost+=a[j][0];
                wt+=a[j][1];
            }
        }
        if(maxx<=wt && cost<=k)
        {
            maxx=wt;
            //minn=cost;
        }

    }
    printf("%lld\n",maxx);

    }
return 0;
}
