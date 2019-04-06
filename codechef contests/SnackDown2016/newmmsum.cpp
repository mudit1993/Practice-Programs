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
              for(i=0;i<n;i++)
            a[i]=0;

            int k=0;
            for(i=0;i<n;i++){
            cin>>csum;
            if(csum<0)
            {
                if(a[k]>0) k++;
            a[k++]=csum;
            }
            else
            {
                a[k]+=csum;
            }
            if(no<csum) no = csum;
            summ+=a[i];
            }
            if(csum>=0) k++;
            n=k;
           // for(i=0;i<n;i++)
            //cout<<a[i]<<",";
            ans=-999999999;
            maxx=-999999999;
            csum=0;
            sum=0;
            mindigg=0;
            i=0;
            while(i<n && a[i]<=0)i++;
          //  cout<<i<<endl;
            for(;i<n;i++)
            {
                    sum+=a[i];
                    if(a[i]<0)
                    {
                        if(mindigg>a[i])
                        {
                            sum+=mindigg;
                           mindigg=a[i];
                            sum-=a[i];
                        }
                        if(i>0 && sum<a[i-1]) sum=a[i-1];
                       // else
                    //    sum+=a[i];

                        //sum+=a[i];
                    }
                    if(sum>maxx)
                    {
                        maxx = sum;
                    }
                    if (sum<0)
                    {
                        sum=0;
                        mindigg=0;
                    }
            }

        if(maxx!=0 && maxx!=-999999999){
            cout<<maxx<<endl;
        }
        else cout<<no<<endl;
    }
	return 0;
}
