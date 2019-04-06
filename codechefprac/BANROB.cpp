#include <iostream>
#include<cmath>
#include<cstdio>

using namespace std;
#define money 1000000000.0
int main() {
    int t,m;
    float p,expon;


    cin>>t;
    while(t--){
        cin>>m>>p;
      //  cout<<m<<"  "<<p<<"test\n";
        expon = pow(-p,m);
       // cout<<"expon= "<< expon<<"\n";
        float ans = money*((1.0-expon)/(p+1.0));
        //ans*=money;
        printf("%lf %lf\n", abs(ans),abs(money-ans));
        //cout<<(float)ans*1.0<<" "<<(float)(money-ans)*1.0<<endl;
    }
	return 0;
}
