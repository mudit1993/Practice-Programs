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

        //cout<<fibmod[1];


        for(long long i=1;i<=15019;i++)
        {
            fibmod[i]=(fibmod[i]+fibmod[i-1])%M;
        }

    long long t;
    cin>>t;
    while(t--)
    {
        long long l,r,sum=0,i,ans=0,x;
        cin>>l>>r;

        long long a=0,b=1,c=1;



       // for(i=2;i<=15000;i++) cout<<fibmod[i]<<endl;



       //for(i=0;i<=11;i++) cout<<fibmod[i]<<" ";


    if(l==1) l++;

        if(l<15000&&r<15000)
        {
            ans=fibmod[r-1]-fibmod[l-2];



        }
        else
        {
                long long cyc1,cyc2;
                cyc1=l/15000;
                cyc2=r/15000;

                long long x,y;

                x=((fibmod[15000]%M)*(cyc1%M))%M;

                x=(x%M+(fibmod[(l-2+15000)%15000]%M))%M;

                y=((fibmod[15000]%M)*(cyc2%M))%M;

                y=(y%M+(fibmod[(r-1+15000)%15000]%M))%M;

                //cout<<x<<" "<<y;

                ans=(y-x+M)%M;
        }



    cout<<ans%M<<endl;


    }

  return 0;
}
