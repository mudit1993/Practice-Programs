#include<iostream>
#include<cmath>
using namespace std;
string pat[1000];
int main()
{
int t,n,m,i,j,minx,miny,maxx,maxy,flag;
cin>>t;
while(t--)
{
    minx=miny=1001;
    maxx=maxy=-1;
    flag=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>pat[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
          if(pat[i][j]=='*')
          {
              miny=i;
              flag=1;
              break;
          }
        }
        if(flag)
        {
            break;
        }
    }
    if(flag)
    {
        flag=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(pat[j][i]=='*')
                {
                    minx=i;
                    flag=1;
                    break;
                }
            }
            if(flag)
              break;
        }
        flag=0;
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(pat[j][i]=='*')
                {
                    maxx=i;
                    flag=1;
                    break;
                }
            }
            if(flag)
              break;
        }
        flag=0;
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                if(pat[i][j]=='*')
                {
                    maxy=i;
                    flag=1;
                    break;
                }
            }
            if(flag)
              break;
        }
        //cout<<" minx-> "<<minx<<" maxx-> "<<maxx<<" miny-> "<<miny<<" maxy-> "<<maxy<<endl;
        int diff=max(maxx-minx,maxy-miny);
        cout<<ceil(diff*0.5)+1<<endl;
    }
    else
        cout<<"0\n";

}
return 0;
}
