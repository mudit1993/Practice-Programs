#include<cstdio>
#include<iostream>
#include<set>
using namespace std;

typedef long long int lli;
lli a[100001],ck[100001];


int main(){
    lli t,n,i,no,i1,cnt;
    scanf("%lld",&t);
    while(t--){
    set<int> index;
    scanf("%lld",&n);
    cnt=0;
    for(i=1;i<=n;i++){
        ck[i]=0;
        index.insert(i);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&no);
        a[i]=(i+no+1)%n;
        if(a[i]==0) a[i]=n;
    }
    while(!index.empty()){
            set<lli>::iterator it;
    //for(it=index.begin();it!=index.end();it++){
        i=*index.begin();
        if(ck[i]==0){
        if(a[i]==i){ck[i]=i;cnt++;index.erase(i);continue;}
        ck[i]=-i;
        i1=a[i];
        while(ck[i1]==-i||ck[i1]==0){
        if(i1==a[i1]){ck[i1]=i;cnt++;index.erase(i1);break;}
        else{
            if(ck[i1]==0){ck[i1]=-i;index.erase(i1);}
            else {ck[i1]=i;cnt++;index.erase(i1);}
            i1=a[i1];
        }
        }
        }//if
        index.erase(i);
    //}
    }
   /* for(i=1;i<=n;i++){
        if(ck[i]>0){cnt++;}
    }*/
    printf("%lld\n",cnt);

    }
return 0;
}
