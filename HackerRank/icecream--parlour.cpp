#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

   int t,m,n,a[10001],i,sum,j;
   cin>>t;
   while(t--)
   {
       sum=0;
       cin>>m>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
            {
                if(a[i]+a[j]==m)
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    sum=1;
                }

            }
            if(sum==1)
                break;
        }
   }
    return 0;
}
