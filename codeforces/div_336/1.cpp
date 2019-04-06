/*#include<iostream>

using namespace std;
int main()
{
    int a[1001],b[1001],i,j,n,s,temp,time=0;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
    {
        if(a[j]<a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;

            temp=b[j];
            b[j]=b[j+1];
            b[j+1]=temp;
        }
    }
    int flr=s;
for(i=0;i<n;i++)
{
   time+=(flr-a[i]);
        if(time<b[i])
        time+=(b[i]-time);
        flr=a[i];

}
cout<<time+flr<<endl;
return 0;
}
*/
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define over999 1234567890

using namespace std;

int main()
{
    int n,o,m,t=0,a[1000],b[1000];
    cin >> n >> m;
    o=m;
    //vector< pii > v;
    for(int i=0;i<n;i++)cin >> a[i] >> b[i];

    for(int i=n-1;i>=0;i--){
        cout<<a[i]<<" "<<b[i]<<endl;
    }

    for(int i=n-1;i>=0;i--){
        t+=m-a[i];
        if(b[i]>t)t=b[i];
        m=a[i];
    }
    t+=m;
    cout << t;
    //thebestinet


    return 0;
}
