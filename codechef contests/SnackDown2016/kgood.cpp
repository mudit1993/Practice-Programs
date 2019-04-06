#include<iostream>
#include<map>
#include<cmath>
typedef long long ll;
using namespace std;

int main() {
    int t;
    long k,len,i,cnt[27];
    string a;
    char ch;
    cin>>t;
    while(t--){

    map<ll,ll> freq;
    for(i=0;i<27;i++) cnt[i]=0;
    cin>>a;
    cin>>k;
    len=a.length();
    for(i=0;i<len;i++){
        ch=a[i];
        cnt[ch-'a']++;
    }
    for(i=0;i<27;i++){
        if(freq.count(cnt[i])>0){
            freq[cnt[i]]++;
        }
        else{
            freq[cnt[i]]=1;
        }
    }
    freq.erase(0);
    map<ll,ll>::iterator iti,itj;
    long long maxx=999999999;

    long long sum=0,diff;
    for(iti=freq.begin();iti!=freq.end();++iti){
            sum=0;
           //  cout<<iti->first<<"="<<iti->second<<",";
        for(itj=freq.begin();itj!=freq.end();++itj){
          diff=abs(iti->first-itj->first);
      //    cout<<iti->first<<","<<itj->first<<","<<diff<<" ";
            if(diff>k){
                if(iti->first<=itj->first){
                    sum+=((diff-k)*itj->second);
                   // cout<<"sum="<<sum;
                }
                else {
                    sum+=(itj->first*itj->second);
                }
                }
     }
        if(maxx>sum && sum!=0){ maxx=sum;
        }
    }
    if(maxx!=999999999)
    cout<<maxx<<endl;
    else
    cout<<"0\n";
    }
	return 0;
}
