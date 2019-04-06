#include<iostream>
#include<cmath>
#define mod 1000000007
using namespace std;
long long int arr[100001],sum[100002];
int main()
{
    int t;
    long long int n,i,ans,mul;
    cin>>t;
    while(t--)
    {

    sum[0]=0;
        cin>>n;
        for(i=0;i<=n;i++)
        {
            cin>>arr[i];
            sum[i+1]=(sum[i]+arr[i])%mod;
        }
    mul=2;
    ans=0;
    for(i=n;i>1;i--)
    {
        ans=ans+((((mul*arr[i])%mod)*sum[i-1])%mod)%mod;
        ans+=(((arr[i-1]*arr[i])%mod)*(int)pow(2,i-1))%mod;
         mul=(mul*2)%mod;
    }
    ans=ans+((((mul*arr[1])%mod)*sum[1])%mod)%mod;
    cout<<ans<<endl;
    }

return 0;
}
