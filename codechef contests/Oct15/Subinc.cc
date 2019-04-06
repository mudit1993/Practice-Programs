#include<iostream>
using namespace std;
int main()
{
unsigned int t,i,n,cnt;
unsigned long no,prev,sum;
cin>>t;
while(t--)
{
    cin>>n;
    cin>>prev;cnt=1;sum=1;
    for(i=1;i<n;i++)
    {
        cin>>no;
        if(prev<=no)
            cnt++;
        else
            cnt=1;
        sum+=cnt;
        prev=no;
    }
    cout<<sum<<endl;
}
return 0;
}
