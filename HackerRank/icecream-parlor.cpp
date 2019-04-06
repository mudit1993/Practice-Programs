#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

   int t,m,n,a[10001],cpy[10001],i,sum,j,k;
   cin>>t;
   while(t--)
   {
       sum=0;
       cin>>m>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            cpy[i]=a[i];
        }
        sort(a,a+n);
        for(i=0,j=n-1;i<n&&j>=0;)
        {
            sum=a[i]+a[j];
            if(sum>m)
                j--;
            else if(sum<m)
                i++;
            else
                break;
        }
       for(k=0;k<n;k++)
       {
        if(a[i]==cpy[k])
            cout<<k+1<<" ";
       }

       for(k=0;k<n;k++)
       {
        if(a[j]==cpy[k])
            cout<<k+1<<endl;
       }
   }
    return 0;
}
