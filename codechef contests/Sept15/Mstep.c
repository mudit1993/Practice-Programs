#include<stdio.h>
int main()
{
    int t,x[250001],y[250001],i,j,no,n;
    long long int sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&no);
                x[no]=i;
                y[no]=j;
            }
            n*=n;
    for(i=1;i<=n-1;i++)
        sum+=abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
    printf("%lld\n",sum);
    }

    return 0;
}
