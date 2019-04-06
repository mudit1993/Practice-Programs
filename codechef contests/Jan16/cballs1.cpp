#include<iostream>
#include<cmath>
using namespace std;
int arr[10000],gc[10000],gcb[10000],arr1[10000];
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
    int t,n,i,odd,balls,pivot,even,b,od;
    cin>>t;
    while(t--)
    {
        odd=balls=even=od=0;
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
        gcb[n-1]=arr[n-1];
        od+=(arr[0]&1);
        arr1[0]=arr[0];
        for(i=1;i<n;i++)
        {
            b=gcd(gc[i-1],arr[i]);
            if(b==1)
            {
                int diff=(gc[i-1]*ceil((float)arr[i]/(float)gc[i-1]))-arr[i];
                arr1[i]=arr[i]+diff;
                odd+=diff;

            }
            gc[i]=b;
            od=(arr[i]&1);
        }
        cout<<"odd="<<odd<<" od="<<od<<endl;
        for(i=n-2;i>=0;i--)
        {
            b=gcd(gcb[i+1],arr[i]);
            if(b==1)
            {
                int diff=(gcb[i+1]*ceil((float)arr[i]/(float)gcb[i+1]))-arr[i];
                cout<<"diff="<<diff<<endl;
                arr[i]+=diff;
                even+=diff;

            }
            gcb[i]=b;
        }
       // cout<<"even="<<even<<" odd="<<odd;
        cout<<(balls+min(od,min(odd,even)))<<endl;
        /*
        if(gc[n-1]==1)
        {

            cout<<odd+balls<<endl;
        }
        else
            cout<<balls<<endl;
        }*/
    }
    }
return 0;
}
