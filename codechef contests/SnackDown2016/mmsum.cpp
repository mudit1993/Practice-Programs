#include <iostream>
using namespace std;
long long int a[100001],b[100001];
int main() {
	long long t,n,i,maxx,sum,csum,k,j,ans,no,summ;
	cin>>t;
    while(t--){
            no=-999999999;
            summ=0;
            cin>>n;
            for(i=0;i<n;i++){
            cin>>a[i];
            if(no<a[i]) no = a[i];
            summ+=a[i];
            }
            ans=-999999999;
            for(j=0;j<n;j++)
            {
            if((a[j]>=0)||(a[j]<0 &&((j+1)<n && a[j+1]<a[j]) ||((j-1)>=0 && a[j-1]<a[j]))) {continue;}
            maxx=-999999999;
            csum=0;
            sum=0;

            for(i=0;i<n;i++)
            {
                if(i!=j)
                {
                    sum+=a[i];
                    if(sum>maxx)
                    {
                        maxx = sum;
                    }
                    if (sum<0)
                    {
                        sum = 0;
                    }
                }
            }
            cout<<"maxx= "<< maxx;
            if(ans<maxx){
                ans=maxx;
            }
        }
        ans=(ans<summ)?summ:ans;
        if(ans){
            cout<<ans<<endl;
        }
        else cout<<no<<endl;
    }
	return 0;
}
