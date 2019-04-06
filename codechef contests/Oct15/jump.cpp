#include<iostream>

using namespace std;

long long int p[300001],a[300001],h[300001],sq[300001];

int main()
{
long long int n,i,j,tot=0,diff=-1,pos,sum;
cin>>n;
for(i=1;i<=n;i++)
{
    diff+=2;
cin>>p[i];
sq[i]=(diff+sq[i-1]);
}
for(i=1;i<=n;i++)
{
cin>>a[i];
}
for(i=1;i<=n;i++)
{
cin>>h[i];
}
pos=1;
for(i=2;i<n;i++)
{
    if(a[i]>=(sq[i+1-pos]) )
        continue;
    else{
        if(i==n-1)
        {
            //cout<<"hi";
            tot+=min((sq[i-pos]+1+a[i]+a[n]),sq[n-pos]+a[n]);
            tot+=a[1];
            pos=n;
        }
        else{
        tot+=sq[i-pos]+a[i];
     //  cout<<sq[i-pos]<<" "<<a[i]<<" ";
      pos=i;
        }
}
}
//cout<<tot<<" "<<a[1]<<" "<<a[n]<<" "<<sq[n-pos]<<endl;
if(pos<n)
tot=tot+a[1]+a[n]+sq[n-pos];
//cout<<"tot="<<tot<<endl;
sum=a[1]+a[n]+sq[n-1];
cout<<min(tot,sum)<<endl;
return 0;
}
