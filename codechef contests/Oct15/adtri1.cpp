#include<iostream>
#include<cmath>
using namespace std;
long long int arr[2238],sum,sum1;
bool aa[5000000]={false};
int main()
{

    long long int i,j,t,n,diff,a,b;
    bool flag;
    cin>>t;
    arr[1]=diff=1;
    for(i=2;i<2237;i++)
    {
        diff+=2;
        arr[i]=arr[i-1]+diff;
        //cout<<aa[i+10000]<<" ";
    }

    for(i=1;i<2237;i++)
     {
         for(j=i+1;j<2237;j++)
        {
            sum=arr[i]+arr[j];
            sum1=sum;
            if(sum<5000000){
            while(sum<5000000)
            {
                aa[sum]=true;
                sum+=sum1;
            }
            }
            else break;
        }

     }
    while(t--)
    {
        cin>>n;
        //cout<<t<<"->";
        if(aa[n])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

return 0;
}
