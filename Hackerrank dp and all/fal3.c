#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
long long int arr1[3000][3000];
 int main()
{
   long long int n;
   cin>>n;
   long long int arr[n];

   for(int i=0;i<n;i++)
    cin>>arr[i];
  long long int max=0;

 //  memset(arr1,0,sizeof(arr1));
 for(int i=1;i<n;i++)
 {
     for(int j=0;j<i;j++)
     {
         long long int res=arr[j]*arr[i];

         if((i-1)>(j+1))
         {
             if(res+arr1[j+1][i-1]>res)
                res=res+arr1[j+1][i-1];
         }
          if(max<res)
            max=res;
          arr1[j][i]=res;
     }

 }
 //for(int i=0;i<n;i++)
 {
   //  for(int j=0;j<n;j++)
     {
     //   cout<<arr1[i][j]<<"  ";
     }
  // cout<<endl;
 }
    cout<<max;
   return 0;
}
