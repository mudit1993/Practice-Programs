#include<iostream>
using namespace std;
typedef long long int lli;
lli a[100001],ck[100001];

int main(){
    lli t,n,i,no,i1;
    cin>>t;
    while(t--){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>no;
        a[i]=(i+no+1)%n;
        if(a[i]==0) a[i]=n;
    }
    lli cnt=0;
    for(i=1;i<=n;i++){
    for(int j=0;j<=100000;j++){
       ck[j]=0;
    }
        ck[i]=1;
        i1=a[i];
        //if(i1==i){ck[i]=2;continue;}
        while(ck[i1]==0){
        //if(i1==a[i1]){ck[i1]=2;break;}
        //else{
            ck[i1]++;
            i1=a[i1];
        //}
        }
        if(i1==i) cnt++;
        //i1=a[i];
       /* while(ck[i1]<2){
        ck[i1]=3;
        }*/
    }
   /* for(i=1;i<=n;i++){
        if(ck[i]==2){cnt++;}
    }*/
   // cout<<"Count = "<<cnt<<"\n";
    cout<<cnt<<"\n";

  /*for(i=1;i<=n;i++){
       cout<<ck[i]<<",";
    }*/

    }
return 0;
}
