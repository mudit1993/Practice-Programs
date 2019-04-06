#include<iostream>
using namespace std;

template<class xyz>

void arithmetic(xyz a, xyz b)
{
 cout<<"Addition   : "<<a+b<<endl;
 cout<<"Difference : "<<a-b<<endl;
 cout<<"Quotient   : "<<a/b<<endl;
 cout<<"Product    : "<<a*b<<endl;
}

int main()
{
 int x,y; 
 cout<<"Enter 2 numbers :"<<endl;
 cin>>x>>y;
 arithmetic(x,y);
return 0;
}
