#include<iostream>
using namespace std;
class abc
{
int a;
public:
void get()
{
cout<<"Enter number:\n";
cin>>a;
}
abc compare(abc a1)
{
if(a1.a>a)
return a1;
else
return (*this);
}
void disp()
{
cout<<"Larger number is:"<<a<<endl;
}
};
int main()
{
abc a1,a2;
a1.get();
a2.get();
(a2.compare(a1)).disp();
return 0;
}

