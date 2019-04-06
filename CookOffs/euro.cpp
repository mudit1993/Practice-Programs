#include <iostream>
#include<cmath>
#include<cstdio>

using namespace std;
int denom[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};
int main() {
    long long t,c,l,i,posc=-1;
    long long sum=0;
    cin>>t;
    while(t--){
    sum=0;
    cin>>c>>l;
    for(i=0;i<15;i++){
        if(c==denom[i]) {posc=i;break;}
    }
    int i=posc-1;
    sum=l;
    while(i>=2){
        if((denom[i]+sum)<c){
            while((denom[i]+sum)<c){
                sum=denom[i]+sum;
               // cout<<sum<<",";
            }
        }
        i--;
    }
    /*
    int dig= l%10;
    if(dig==5){
        sum+=4;*/
    cout<<sum<<endl;
    }

	return 0;
}
