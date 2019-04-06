#include <iostream>
#include<cmath>
#include<cstdio>

using namespace std;
long long a[100000];
int main() {
    long long  n,i;
    long long sum=0;
    cin>>n;
    for(i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    }
    if(sum%2==1){
        sum=(sum+1)/2;
    }
    else sum/=2;
    if(sum<n)
    cout<<n<<endl;
    else
    cout<<sum<<endl;
	return 0;
}
