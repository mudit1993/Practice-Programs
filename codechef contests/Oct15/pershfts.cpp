#include <iostream>
#include <algorithm>
using namespace std;
long long int arr[121][5],a[100001],b[100001];

bool isEqual(int row,int n)
{
for(int i=0;i<n;i++)
{
if(b[i]!=arr[row][i])
    return false;
}
return true;
}

int main () {
    unsigned int t,i,n,k,no,cst;
    cin>>t;
  int myints[] = {1,2,3,4,5};
  int cnt=1;
  do {
        for(i=0;i<5;i++)
            arr[cnt][i]=myints[i];
    cnt++;
    } while (next_permutation(myints,myints+5));
while(t--)
{
cin>>n>>k;
if(n==k)
{
    bool flag=true;
for(i=0;i<n;i++)
{
    cin>>no;
    a[no]=i;
}
 cin>>no;
 k=no;//1st element of Q
   cst=(n-a[no])%n;
for(i=1;i<n;i++)
{
    cin>>no;
    if((((n+i)-a[no])%n)!=cst)
       {
            flag=false;
       }
}
if(flag)
{
cout<<k<<"\n";
}
else cout<<"-1\n";
continue;
}
else{
for(i=0;i<n;i++)
{
    cin>>a[i];
}
if(k==2)
{
    bool flag=true;
   for(i=0;i<n;i++)
{
    cin>>b[i];
}
for(i=1;i<=120;i++)
{
if(isEqual(i,n))
{
    cout<<i<<endl;
    flag=false;
    break;
}
}
if(flag)
    cout<<"-1\n";
}
else if(k==3)
{
cout<<"-1\n";
}
}

}
  return 0;
}
