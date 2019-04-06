#include<iostream>
#define MOD 1000000007
using namespace std;

unsigned long long int n[1001],m[1001],c[1001][1001],n1,m1,c1;
int main()
{
    unsigned long long int i,n2,m2,j,tot,sum;
for(i=0;i<=1000;i++)
{
    n[i]=m[i]=0;
}
    cin>>n1>>m1>>c1;
    for(i=0;i<n1;i++)
        {
            cin>>n2;
            n[n2]++;
        }
    for(i=0;i<m1;i++)
        {
            cin>>m2;
            m[m2]++;
        }

        for(i=1;i<=c1;i++)
        {
            c[0][i]=(n[i]*m[i])%MOD;  // maxx hemisphere
    //cout<<c[0][i]<<" ";
        }
      // cout<<endl;
       // cout<<sum<<" ";
        for(i=0;i<c1;i++)
        {
            sum=c[i][i+1];
            //cout<<"sum->"<<sum<<" ";
            tot=0;
            for(j=i+2;j<=c1;j++)
            {
                c[i+1][j]=(sum*c[0][j])%MOD;
                tot=(tot+c[i+1][j])%MOD;
                sum+=c[i][j];
                sum%=MOD;
          //      cout<<c[i+1][j]<<" ";
            }
            cout<<tot<<" ";
            //cout<<endl;
            //cout<<tot<<" ";
        }
        cout<<endl;
    return 0;
}
