#include<bits/stdc++.h>

using namespace std;

const long long M=10e9+7;
long long fibmod[15020];

int main()
{
  ios_base::sync_with_stdio(false);
  long long fibsum=0;



        fibmod[0]=0;
        fibmod[1]=1;

        for(long long i=2;i<=15019;i++)
        {
            fibmod[i]=(fibmod[i-1]%10000+fibmod[i-2]%10000)%10000;
        }

        //cout<<fibmod[1]<<" and "<<fibmod[15001];
//largest in 14999

        for(long long i=1;i<=15019;i++)
        {
            fibmod[i]=(fibmod[i]%M+fibmod[i-1]%M)%M;
        }
      cout<<fibmod[14999]<<" and "<<fibmod[0]<<endl;

    long long t;
    cin>>t;
    while(t--)
    {
        long long l,r,sum=0,i,ans=0,x,cycles;
        cin>>l>>r;
        r--;
        l--;
        long long a=0,b=1,c=1;
        cycles=(r-l)/15000;
        sum=(cycles*fibmod[14999])%M;
        cout<<"Sum="<<sum<<endl;
        l%=15000;
        r%=15000;
        if(l<r){
            if(l>0)
            sum=(sum+(fibmod[r]-fibmod[l-1]))%M;
            else
            sum=(sum+fibmod[r])%M;
        }
        else if(l>r){
            sum=(sum+fibmod[r])%M;
            sum=(sum+fibmod[14999]-fibmod[l-1])%M;
        }
        else{
            if(l>0)
                sum=(sum+(fibmod[l]-fibmod[l-1]))%M;
            else
                sum=(sum+fibmod[l])%M;
        }

       //for(i=0;i<=11;i++) cout<<fibmod[i]<<" ";





    cout<<sum%M<<endl;


    }

  return 0;
}
