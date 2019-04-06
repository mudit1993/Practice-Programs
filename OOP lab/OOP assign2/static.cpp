#include<iostream>
using namespace std;
class increment
{
int a;
static int s;
public:
void input()
{
cout<<"Enter a number\n";
cin>>a;
s+=8;
}
void disp()
{
cout<<"Number is: "<<a<<"\n static no. after increment is :"<<s<<"\n";
}
static void disp1()
{
    cout<<    "static no. after increment is :"<<s<<"\n";
}
};
int increment::s=4;
int main()
{
increment a1,a2,a3;
a1.input();
a1.disp();
a2.input();
a2.disp();
a3.input();
a3.disp();
a3.disp1();
return 0;
}

