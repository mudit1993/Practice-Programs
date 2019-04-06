#include<iostream>
using namespace std;
int x[150],y[150],z[150];
int main()
{
int n,r,t,flag,i;
cin>>t;
while(t--)
{
    flag=1;
    cin>>n>>r;
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    if(n==1)
        cout<<"0\n";
    else{
        if((x[0]>0 && x[1]>0)||(x[0]<0 && x[1]<0))
          { flag=0;}
            if((y[0]>0 && y[1]>0)||(y[0]<0 && y[1]<0))
            {flag=0;}
            if((z[0]>0 && z[1]>0)||(z[0]<0 && z[1]<0))
                {flag=0;
                }
           cout<<flag<<endl;
    }
}

return 0;
}
