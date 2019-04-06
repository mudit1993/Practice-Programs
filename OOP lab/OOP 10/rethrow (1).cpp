#include<iostream>
using namespace std;
void abcd(int a,int b)
{
try{
if(b==0)
throw 0;
else
cout<<a/b;
}
catch(int n)
{
cout<<"j is zero\n";
throw n;
}
}
main()
{
int i,j;
cout<<"Enter two numbers\n";
cin>>i>>j;
try{
abcd(i,j);
}
catch(...)
{
cout<<"Exception rethrown\n ";
}
}
