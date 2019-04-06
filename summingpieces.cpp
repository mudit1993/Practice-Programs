#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void get_count(int* arr, int start, int end){
if(start==end){
arr[start] += 1;
return;
}

for(int i=start;i<=end;++i){
int shift=(end-i-1);
int len=(i-start+1);
for(int j=start;j<=i;++j){
arr[j]+=(len)*(shift>0?(1<<shift):1);
}
get_count(arr,i+1,end);
}
}

int main(){
int n=11;
for(int j=3;j<n;j++){
int *arr=new int[j];
get_count(arr,0,j-1);
for(int i=0;i<j;i++)
cout << arr[i] <<" ";
cout << endl;
}
}
