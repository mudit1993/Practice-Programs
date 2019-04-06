#include <iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define mod 1000000007
long long s[100000],desc[100000];
int main() {
    int t;
    long long max,min,n,i;
     cin>>t;
    while(t--){
        max=min=0;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>s[i];
         sort(s,s+n);
         for(i=0;i<n;i++){
         min = (2*min + s[i])%mod;
         max = (2*max + s[n-i-1])%mod;
         }
          cout<<(max+mod-min)%mod<<"\n";

    }
	return 0;
}
