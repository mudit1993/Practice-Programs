#include<iostream>
using namespace std;
int main(){
int t;
long long int m,n;
cin>>t;
while(t--){
    cin>>n>>m;
   // if(m==1 && n==1) {cout<<"Yes"<<endl;continue;}
    if(m==1 || n==1)
    {
        if(m==1){
           if(n%2==0){cout<<"Yes"<<endl;continue;}
           else {cout<<"No"<<endl;continue;}
        }
        else {
            if(m%2==0){cout<<"Yes"<<endl;continue;}
           else {cout<<"No"<<endl;continue;}
        }
    }

if(m%2==1 && n%2==1) cout<<"No"<<endl;
else cout<<"Yes"<<endl;
}
return 0;
}
