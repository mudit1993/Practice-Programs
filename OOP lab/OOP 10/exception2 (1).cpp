#include<iostream>
using namespace std;
//void subtract(int a,int b);
void subtract(int a,int b)
{
if(a==0)
throw 1;
else if(a<0)
throw 1.1f;
else if(a<b)
throw 'c';
else
cout<<"Difference is:"<<a-b;
}
main()
{
int i,j;
cout<<"Enter two numbers\n";
cin>>i>>j;
try{
subtract(i,j);
}
catch(int a)
{
cout<<"First number is zero\n";
}
catch(float b)
{
cout<<"First number is negative\n";
}
catch(char c)
{
cout<<"First number is less than second number\n";
}
}
