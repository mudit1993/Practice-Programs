#include<iostream>
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
    for(i=n;i>=1;i--)
    {
        ans=ans+((((mul*arr[i])%mod)*sum[i])%mod)%mod;
        mul=(mul*2)%mod;
    }
    cout<<ans<<endl;
    }

return 0;
}
