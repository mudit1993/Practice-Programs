#include<stdio.h>
#define mod 1000000000
int main()
{
    int t,i,j,n,m,r,r1;
    unsigned long long int dp[2][2001],sum;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d%d",&n,&m);
    //h=n>m?n:m;
    for(i=0;i<=m;i++)
    {
       dp[0][i]=1;
       dp[1][i]=1;
    }
    dp[1][0]=1;
    for(j=2;j<=m;j++)
    {
        r=j%2;
        r1=(j-1)%2;
    for(i=1;i<=m;i++)
    {
        dp[r][i]=(dp[r][i-1]+dp[r1][i])%mod;
    }
    }
   //for(i=0;i<=m;i++)
  //     printf("%lld ",dp[m%2][i]);
//printf("\n");
r1=(m-1)%2;
    r=m%2;

for(i=0;i<=m;i++)
    dp[r1][i]=dp[r][i];
 //for(i=0;i<=m;i++)
  //     printf("%lld ",dp[(m-1)%2][i]);
//printf("\n");
    for(j=1;j<n;j++)
    {
        sum=0;
    for(i=m;i>=0;i--)
    {
        sum=(sum+dp[r1][i])%mod;
        dp[r1][i]=(sum*dp[r][i])%mod;
        //dp[r][i]=(dp[r][i-1]+dp[r1][i])%mod;
    }
    }
    sum=0;
    for(i=0;i<=m;i++)
        sum=(sum+dp[r1][i])%mod;
    printf("%lld\n",sum);
    }
return 0;
}
