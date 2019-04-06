#include<iostream>

using namespace std;
long long int arr[2237][2237];
int main()
{
    long long int i,j,t,n,diff;
    bool flag;
    int index;
    cin>>t;
    diff=arr[0][1]=1;
    for(i=2;i<2237;i++)
    {
        diff+=2;
        arr[0][i]=arr[0][i-1]+diff;
        cout<<arr[0][i]<<" ";
    }
    for(i=1;i<2237;i++)
        for(j=i+1;j<2237;j++)
        {
            arr[i][j]=arr[0][i]+arr[0][j];
        }
    while(t--)
    {
        flag=false;
        cin>>n;
        for(i=1;i<2237;i++)
        {
            for(j=i+1;j<2237 && arr[i][j]<=n;j++)
            {
                if(arr[i][j]==n)
                {flag=true;break;}
            }
            if(flag)
                break;
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

return 0;
}
