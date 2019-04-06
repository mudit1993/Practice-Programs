#include<iostream>
using namespace std;
typedef long long int lli;
lli a[100001];
int maxx(lli m,lli n){
    lli maxxx = a[m];
    for(int i=m+1;i<=n;i++){
        maxxx=max(maxxx,a[i]);
    }
return maxxx;
}
int main()
{
    lli n,i,j,sum=0;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
                int no = a[i]&a[j];
            if(no==a[i]||no==a[j]){
                sum+=maxx(i,j);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
