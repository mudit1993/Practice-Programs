#include<iostream>
#include<string>

using namespace std;

int main()
{
unsigned long long prev,curr,maxx;
unsigned int t,n,i,cnt;
string ans,chef;
cin>>t;
while(t--)
{
    cnt=0;
cin>>n>>ans>>chef;
for(i=0;i<n;i++)
{
    if(ans[i]==chef[i])
        cnt++;
}
if(cnt<n)
 {
cin>>prev;
maxx=prev;
for(i=1;i<=cnt;i++)
{
    cin>>curr;
      maxx=max(curr,maxx);
}
for(i=cnt+1; i<=n;i++)
    cin>>curr;
    cout<<maxx<<endl;
 }
else{
    for(i=0;i<=n;i++)
    cin>>curr;
    cout<<curr<<endl;
}
}
return 0;
}

