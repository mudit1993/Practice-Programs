#include<iostream>
#include<algorithm>
using namespace std;
long long int a[100000],c[100001];
int main()
{
long long int n,i,k,m,t,b,tasks,j;
bool flag;
cin>>t;
while(t--)
{
cin>>n>>k>>m;
tasks=0;
fill_n(c,100001,0);
for(i=0;i<n;i++)
    cin>>a[i];
for(i=0;i<n;i++)
    {
        cin>>b;
        a[i]-=b;
    }
    for(i=0;i<k+m;i++)
    {
        cin>>b;
        c[b]++;
    }
    sort(a,a+n);
    for(i=n-1;i>=0;i--)
    {
        flag=true;
        j=a[i];
        while(flag && j>0)
        {
            if(c[j])
            {
                tasks+=(a[i]-j);
                c[j]--;
                flag=false;
            }
            j--;
        }
        if(flag)
        {
            tasks+=a[i];
        }
    }
    cout<<tasks<<endl;
}
 return 0;
 }
