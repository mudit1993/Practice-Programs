#include<iostream>
using namespace std;
class abc
{ int a;
public:
void get(int a)
{
//a=a;
this->a=a;
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
cout<<"Value is:"<<a<<endl;
}
};
int main()
{
abc a1,a2;
int s;
cout<<"Enter a number:\n";
cin>>s;
a1.get(s);
cout<<"Enter a number:\n";
cin>>s;
a2.get(s);
(a2.compare(a1)).disp();
}
