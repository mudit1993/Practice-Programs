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
    for(i=0;i<27;i++)cnt[i]=0;
    cin>>a;
    cin>>k;
    len=a.length();
    for(i=0;i<len;i++){
        ch=a[i];
        cnt[ch-'a']++;
    }
    for(i=0;i<26;i++){
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

    long long suml=0,sumr=0,diff;
    for(iti=freq.begin();iti!=freq.end();++iti){
            suml=sumr=0;
           //  cout<<iti->first<<"="<<iti->second<<",";
        for(itj=freq.begin();itj!=freq.end();++itj){
          diff=abs(iti->first-itj->first);
      //    cout<<iti->first<<","<<itj->first<<","<<diff<<" ";
            if(iti->first<=itj->first){
                    suml+=(itj->first-iti->first)*itj->second;
                    if(diff>k)
                    sumr+=((diff-k)*itj->second);
                   // cout<<"sum="<<sum;
            }
            else {
                sumr+=(itj->first*itj->second);
                if(diff>k)
                    suml+=(itj->first*itj->second);
            }

     }
        if(maxx>suml && suml!=0){ maxx=suml;
        }
        if(maxx>sumr && sumr!=0){ maxx=sumr;
        }
    }
    if(maxx!=999999999)
    cout<<maxx<<endl;
    else
    cout<<"0\n";
    }
	return 0;
}
