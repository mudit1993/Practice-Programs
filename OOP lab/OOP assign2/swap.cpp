#include<iostream>
using namespace std;
void ref(int &a,int &b)
{
a=a+b;
b=a-b;
a=a-b;
cout<<"in function \nA= "<<a<<" B= "<<b<<"\n";

}
main()
{
int a,b;
cout<<"Enter A and B respectively\n";
cin>>a>>b;
cout<<"before function call\nA= "<<a<<" B= "<<b<<"\n";
ref(a,b);
cout<<"after function call\nA= "<<a<<" B= "<<b<<"\n";
}
