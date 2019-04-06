#include<iostream>
using namespace std;
int arr[100001],sum[100001];
bool prime[100001];
int main(){
    long long int q,a,b,i,cnt=0,lim=1,pre=1;
    for(i=1;i<=5;i++){
            cnt++;
        lim=lim*10;

        for(int j=pre;j<lim;j++){
        arr[j]=0-cnt;
        prime[j]=true;
        sum[j]=0;
        }
        pre=lim;
    }
    arr[1]=0;
   for (i=2; i<=100000; i++)
    {
        if (prime[i] == true)
        {
            for (int j=i; j<=100000; j += i){
                prime[j] = false;
                arr[j]++;
            }
        }
    }
    sum[0]=0;
    for(i=1;i<=100000;i++){
        if(arr[i]==0){
            sum[i]=sum[i-1]+1;
        }
        else{
            sum[i]=sum[i-1];
        }
    }
    cin>>q;
    while(q--){
    cin>>a>>b;
    cout<<sum[b]-sum[a-1]<<endl;
    }

return 0;
}
