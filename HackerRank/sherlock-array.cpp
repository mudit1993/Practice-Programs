#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

   int t,n,a[100000],l[100000],r[100000],i;
   cin>>t;
   while(t--)
   {
       cin>>n;
        for(i=0;i<n;i++)
             cin>>a[i];
             l[0]=a[0];
              r[n-1]=a[n-1];
        for(i=1;i<n;i++)
        {
            l[i]=l[i-1]+a[i];
            r[n-1-i]=r[n-i]+a[n-i-1];
        }
        for(i=0;i+2<n;i++)
        {
            if(l[i]==r[i+2])
            {
                cout<<"YES\n";
                break;
            }
        }
        if(i+2==n||n==2)
            cout<<"NO\n";
       else if(n==1)
           cout<<"YES\n";
   }

    return 0;
}
