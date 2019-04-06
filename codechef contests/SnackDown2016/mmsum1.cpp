#include <iostream>
using namespace std;
long long int a[100001],b[100001];
int main() {
	long long t,n,i,maxx,sum,csum,mindig,k;
	bool flag;
	cin>>t;
    while(t--){
            cin>>n;
            maxx=-999999999;
            mindig=999999999;
            csum=0;
            sum=0;
            k=0;
            flag=true;
            for(i=0;i<n;i++){
                cin>>a[i];
                if(a[i]==0) continue;
                if(a[i]>0 && sum>=0){
                    flag=false;
                    sum+=a[i];
                }
                else if(flag==false && a[i]<0){
                    b[k++]=sum;
                    sum=a[i];
                    flag=true;
                }
                else if(sum<0 && a[i]>0){
                    b[k++]=sum;
                    sum=a[i];
                    flag=false;
                }
                else{
                    sum+=a[i];
                }
            }
            if(sum!=0)
                b[k++]=sum;
            maxx=-9999999999
            for(i=0;i<k;i++){
            cout<<b[i]<<",";
            }
            }
	return 0;
}
