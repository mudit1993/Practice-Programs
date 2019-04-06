#include<iostream>
using namespace std;
main()
{
int i,j;
try{
cout<<"Enter values for i and j\n";
cin>>i>>j;
if(j==0)
throw j;
else
{
cout<<(i/j);
}
}
catch(int p)
{
cout<<"Exception:- second value is zero!\n";
}
}
