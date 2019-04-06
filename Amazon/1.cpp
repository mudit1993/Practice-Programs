#include<iostream>
using namespace std;
long long int c[100001],n;
long long int srch(long long int no){
  long long int l=1,u=n,mid;
  int f=0;
    while(l<=u){
         mid=(l+u)/2;
         if(no==c[mid]){
             f=1;
             break;
         }
         else if(no<c[mid]){
             u=mid-1;
         }
         else
             l=mid+1;
    }
    if(f==1) return mid;
    else return l;

}

int main(){
long long int q,i,no,ans;
cin>>n;
c[0]=0;
for(i=1;i<=n;i++){
    cin>>no;
    c[i]=c[i-1]+no;
}
cin>>q;
while(q--){
        cin>>no;
ans=srch(no);
cout<<ans<<endl;
}
return 0;
}
