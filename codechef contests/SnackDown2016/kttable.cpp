#include <iostream>
using namespace std;
long long int a[10001];
int main() {
	long long t,n,i,cnt,b,temp;
	cin>>t;
    while(t--){
            cin>>n;
            cnt=0;
            temp=0;
            for(i=0;i<n;i++){
                cin>>a[i];
            }
            for(i=0;i<n;i++){
                cin>>b;
                if((a[i]-temp)>=b){
                    cnt++;
                }
                temp=a[i];
            }
    cout<<cnt<<endl;
    }
	return 0;
}
