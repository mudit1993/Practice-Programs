#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000];


int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n); // ascending
   // sort(arr,arr+n,greater<int>());  descending

    for(i=0;i<n;i++)
        cout<<arr[i]<<' ';

return 0;
}
