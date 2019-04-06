#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int arr[100002],gcdl[100002],gcdr[100002];
int gcd(int a,int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main() {
    int t,n,q;
    int i,l,r;
     cin>>t;
    while(t--){
        cin>>n>>q;
        for(i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        gcdl[1]=arr[1];
        gcdr[n]=arr[n];
    for(i=1;i<n;i++){
        gcdl[i+1]=gcd(gcdl[i],arr[i+1]);
        gcdr[n-i]=gcd(gcdr[n-i+1],arr[n-i]);
    }
    gcdl[0]=gcdl[2];
    gcdr[n+1]=gcdr[n-1];
    while(q--){
        scanf("%d%d",&l,&r);
     printf("%d\n",gcd(gcdl[l-1],gcdr[r+1]));
    }
    }
	return 0;
}
