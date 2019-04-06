#include<iostream>

using namespace std;
int arr[10000],gc[10000];
int gcd(int a,int b)
{
    int c;
while(a!=b && a!=0)
{
    c=b%a;
    b=a;
    a=c;
}
return b;
}
int main()
{
    int t,n,i,odd,balls,pivot,even;
    cin>>t;
    while(t--)
    {
        odd=balls=even=0;
        cin>>n;
        cin>>arr[0];
        pivot=gc[0]=arr[0];
        if(n==1){
            if(arr[0]==1) cout<<"1\n";
            else cout<<"0\n";
        }
        else{
        for(i=1;i<n;i++)
        {
        cin>>arr[i];
        if(pivot>arr[i]){
            balls+=(pivot-arr[i]);
            arr[i]=pivot;
        }
        else  pivot=arr[i];
        }
        for(i=1;i<n;i++)
        {
            gc[i]=gcd(gc[i-1],arr[i]);
            odd+=(arr[i]&1);
        }
        even=n-odd;
        if(gc[n-1]==1)
        {
            odd+=(arr[0]&1);
            cout<<odd+balls<<endl;
        }
        else
            cout<<balls<<endl;
        }
    }
return 0;
}
