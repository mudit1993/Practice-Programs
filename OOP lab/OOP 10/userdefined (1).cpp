#include<iostream>
using namespace std;
void abcd(int i,int j)throw(int)
{
if(j==0)
throw j;
else
cout<<i/j;
}
main()
{
int i,j;
cout<<"Enter 2 values\n";
cin>>i>>j;
try{
abcd(i,j);
}
catch(int p)
{
cout<<"Second number is zero!\n";
}
}
