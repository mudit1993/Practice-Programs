#include<iostream>
using namespace std;
long long int s[50001],dist[50001],tim[50001];
int main()
{
long long int n,q,i,typ,maxx=0,ty,ns,cyc;
cin>>n>>q;
for(i=0;i<=n;i++)
{
    s[i]=0;
    dist[i]=0;
    tim[i]=0;
}
for(i=0;i<q;i++)
{
    cin>>typ;
    if(typ==1)
    {
        cin>>ty>>cyc>>ns;
              dist[cyc]=dist[cyc]+((ty-tim[cyc])*s[cyc]);
              tim[cyc]=ty;
              s[cyc]=ns;
    }
    else{
            cin>>ty;
            for(i=1;i<=n;i++)
            {
                dist[i]=dist[i]+((ty-tim[i])*s[i]);
                tim[i]=ty;
                if(maxx<dist[i])
                    maxx=dist[i];
            }
        cout<<maxx<<endl;
    }
}
return 0;
}
