#include <iostream>
using namespace std;
long long int a[100001],b[100001];
int main() {
	long long t,n,i,maxx,sum,csum,k,j,ans,no,summ,mindigg;
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
            maxx=-999999999;
            csum=0;
            sum=0;
            mindigg=0;
            for(i=0;i<n;i++)
            {
                    sum+=a[i];
                    if(mindigg>a[i] && sum>0){
                            mindigg=a[i];
                        }
                    if(sum>maxx)
                    {
                        maxx = sum;
                    }
                    if (sum<0)
                    {
                        if(mindigg<=a[i]){
                                sum = 0;
                        }
                        else{
                            cout<<"mindigg="<<mindigg<<endl;
                                if(mindigg!=0){
                                sum-=mindigg;
                                sum+=a[i];
                                cout<<"sum="<<sum<<",";
                                }
                                else
                                {
                                    mindigg=a[i];
                                    sum-=a[i];
                                }
                                if(sum<0)
                                {
                                    mindigg=0;
                                    sum=0;
                                }
                        }
                    }
                    cout<<"maxx="<<maxx<<endl;
            }

        if(maxx){
            cout<<maxx<<endl;
        }
        else cout<<no<<endl;
    }
	return 0;
}
