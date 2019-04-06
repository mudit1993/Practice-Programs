
#include<iostream>
using namespace std;
int tree[100001],sum[100001];
int color[100001];
int main(){
    long long int n,c,i,j;
    cin>>n>>c;
    tree[0]=-1;
    tree[1]=0;
    for(i=2;i<=n;i++){
        cin>>tree[i];
    }
    for(i=1;i<=n;i++){
        cin>>color[i];
        sum[i]=-1;
    }
    sum[1]=-1;
    for(i=2;i<=n;i++){
            bool flag=true;
            j=i;
        while(tree[j]!=0){
            if(color[tree[j]]==color[i]){
                flag=false;break;
            }
            else{
                   // cout<<i<<" j="<<j;
                j=tree[j];
            }
        }
        if(!flag){
            sum[i]=tree[j];
        }
    }
    for(i=1;i<=n;i++){
        cout<<sum[i]<<" ";
    }
    cout<<endl;


return 0;
}
