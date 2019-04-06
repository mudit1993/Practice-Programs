#include<iostream>
#include<cmath>
#define mod 1000000007
using namespace std;
long long int arr[100001],sum[100002],ut[100002];
int main()
{
    int t;
    long long int n,i,ans,mul;
    cin>>t;
    while(t--)
    {
    mul=2;
        cin>>n;
        for(i=0;i<=n;i++)
             cin>>arr[i];
             if(n==1){
                cout<<arr[0]*arr[1]*2<<endl;
                continue;}
        ut[0]=arr[0]*2;
        ut[1]=arr[1]*2;
        sum[0]=ut[0];
        sum[1]=ut[1]+ut[0];
        ans=0;
        for(i=2;i<=n;i++)
        {
            mul=(mul*2)%mod;
            ut[i]=(arr[i]*mul)%mod;
            sum[i]=(sum[i-1]+ut[i])%mod;
        }
    /*    for(i=0;i<=n;i++)
            cout<<" "<<sum[i];
        cout<<endl;
        for(i=0;i<=n;i++)
            cout<<" "<<ut[i];
        cout<<endl;
       */
        ans=(ans+((sum[n-1]*arr[n])%mod)%mod)%mod;
        mul=2;
        for(i=n-1;i>=1;i--)
        {
            ans=(ans+(mul*(sum[i-1]*arr[i])%mod)%mod)%mod;
            mul=(mul*2)%mod;
            //cout<<ans<<" ";
        }
      //  ans=(ans+((int)pow(2,n-1)*(arr[0]*arr[1])%mod)%mod)%mod;

    cout<<ans<<endl;
    }

return 0;
}
