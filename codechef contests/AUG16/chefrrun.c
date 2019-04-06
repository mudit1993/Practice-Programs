#include<stdio.h>
typedef long long int lli;
lli a[100001],ck[100001];

int main(){
    lli t,n,i,no,i1,cnt;
    scanf("%lld",&t);
    while(t--){
    scanf("%lld",&n);
    cnt=0;
    for(i=0;i<=100000;i++){
        ck[i]=0;
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&no);
        a[i]=(i+no+1)%n;
        if(a[i]==0) a[i]=n;
    }

    for(i=1;i<=n;i++){
        if(ck[i]==0){
        if(a[i]==i){ck[i]=i;cnt++;continue;}
        ck[i]=-i;
        i1=a[i];
        while(ck[i1]==-i||ck[i1]==0){
        if(i1==a[i1]){ck[i1]=i;cnt++;break;}
        else{
            if(ck[i1]==0){ck[i1]=-i;}
            else {ck[i1]=i;cnt++;}
            i1=a[i1];
        }
        }
        }//if
        if(cnt==n) break;
    }
   /* for(i=1;i<=n;i++){
        if(ck[i]>0){cnt++;}
    }*/
    printf("%lld\n",cnt);

    }

return 0;
}
