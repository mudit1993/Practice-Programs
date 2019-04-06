#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long int a[100001],b[100001];
int main() {
	long long t,n,i,maxx,sum,csum,k,j,ans,no,summ;
	cin>>t;
    while(t--){
            no=-999999999;
            summ=0;
            vector<long long> neg;
             cin>>n;
            for(i=0;i<n;i++)
            a[i]=0;
            long long minn=0,minpos=0;
            int k=0;
            for(i=0;i<n;i++){
            cin>>csum;
            if(csum<0)
            {
                if(a[k]>0) {
                    k++;
                    minn=0;
                }
                if(minn>csum) {minn=csum;minpos=k;}
            a[k++]=csum;
            }
            else
            {
                if(minn<0){
                    neg.push_back(minpos);
                    minn=0;
                }
                a[k]+=csum;
            }
            if(no<csum) no = csum;
            summ+=a[i];
            }
            if(csum>=0) k++;
            n=k;
           /* for(j=0;j<n;j++)
            {
                cout<<a[j]<<",";
            }
            cout<<endl;
            vector<long long>::iterator it;
            for(it=neg.begin();it!=neg.end();++it){
                cout<<*it<<" ";
            }*/
            ans=-999999999;
            vector<long long>::iterator it;
            for(it=neg.begin();it!=neg.end();++it)
            {
            maxx=-999999999;
            csum=0;
            sum=0;
            for(i=0;i<n;i++)
            {
                if(i!=*it)
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
           // cout<<"maxx= "<< maxx;
            if(ans<maxx){
                ans=maxx;
            }
        }
       // ans=(ans<summ)?summ:ans;
        if(ans!=-999999999 && ans!=0){
            cout<<ans<<endl;
        }
        else {
                ans=max(ans,summ);
                ans=max(ans,no);
                cout<<ans<<endl;
        }
    }
	return 0;
}
