#include<iostream>
using namespace std;
template<class xyz>
void change(xyz &a,xyz &b)
{
 a=a+b;
 b=a-b;
 a=a-b;
//cout<<a<<","<<b<<endl;
}

int main()
{
 int x,y;
float a,b;
 cout<<"Enter 2 numbers :"<<endl;
 cin>>x>>y;
cout<<"Before swap:"<<x<<","<<y<<endl;
 change(x,y);
cout<<"After swap:"<<x<<","<<y<<endl;
cout<<"Enter 2 numbers :"<<endl;
 cin>>a>>b;
cout<<"Before swap:"<<a<<","<<b<<endl;
 change(a,b);
cout<<"After swap:"<<a<<","<<b<<endl;
return 0;
}
