#include <iostream>
#include <algorithm>
#include <vector>
#define mod 1000000007
using namespace std;

typedef long long int ll;
int main() {

    ll t,n,k,no,i,psize,nsize;
    bool zero=false;
    cin>>t;
    while(t--){
    ll prod=1;
    cin>>n>>k;
    vector<ll> pos;
    vector<ll> neg;
    for(i=0;i<n;i++){
    cin>>no;
    if(no>0) pos.push_back(no);
    else if(no<0) neg.push_back(no);
    else zero=true;
    }
    psize=pos.size();
    nsize=neg.size();
    if(k>(psize+nsize))
        cout<<"0\n";
    else if(k==(psize+nsize)){
        ll i,j,prod=1;
        if(zero==true && nsize%2==1) {
            cout<<"0\n";
            continue;
        }
        for(i=0;i<neg.size();i++){
            prod=(prod*neg[i])%mod;
            while(prod<0)
            prod=prod+mod;
        }
        for(j=0;j<pos.size();j++){
            prod=(prod*pos[j])%mod;
        }
        cout<<prod<<endl;continue;
    }
    else{
        if(psize==0 && nsize>0){   //zeroes and -ves
            if(k%2==1 && zero==true)
                 cout<<"0\n";
            else{
                sort(neg.begin(),neg.end());
                vector<ll>::iterator it;
                prod=1;
                if(k%2==0)
                for(it=neg.begin();it!=neg.end() && (k--)!=0 ;++it){
                    prod= (prod*(*it))%mod;
                }
                else{
                    for(int i=neg.size()-1;(k--)!=0 ;--i){
                    prod= (prod*(neg[i]))%mod;
                }
                }
                while(prod<0)
                    prod=prod+mod;
                cout<<prod<<endl;
            }
        }
        else if(nsize==0 && psize>0){  //  zeroes and +ves
             sort(pos.begin(),pos.end(),greater<ll>());
                vector<ll>::iterator it;
                prod=1;
                for(it=pos.begin();it!=pos.end() && (k--)!=0 ;++it){
                    prod= (prod*(*it))%mod;
                }
                while(prod<0)
                    prod=prod+mod;
                cout<<prod<<endl;
        }
        else{// both -ves and +ves
        prod=1;
        ll left=0;
          sort(pos.begin(),pos.end(),greater<ll>());
          sort(neg.begin(),neg.end());
          vector<ll>::iterator it;
          ll j=0,tmp1,tmp2;
          i=0;
        if(k>psize && k!=(psize+nsize)){
            left= k-psize;
            if(left%2) left++;
               for(;i<left;){
                    prod=prod*((neg[i]*neg[i+1])%mod)%mod;
                    //left-=2;
                    i+=2;
                }
                //left=k-psize;
                neg.erase(neg.begin(),neg.begin()+left);
                nsize=neg.size();
                i=0;
        }
        k-=left;
        while(k>1){
                tmp1=tmp2=1;
            if((i+1)<nsize){
                tmp1=(neg[i]*neg[i+1]);
            }
            if((j+1)<psize){
                tmp2=(pos[j]*pos[j+1]);
            }
            if(tmp1>=tmp2){
                i+=2;
                prod=(prod*(tmp1%mod))%mod;
            }
            else{
                j+=2;
                 prod=(prod*(tmp2%mod))%mod;
            }
            k-=2;
        }
        if(k==1 && j<psize) prod=(prod*pos[j])%mod;
        else if(k==1) prod=(prod*neg[i])%mod;
          while(prod<0)
            prod=prod+mod;
         cout<<prod<<endl;
        }

    }
    }
	return 0;
}
