#include<iostream>
#include<string.h>
using namespace std;
class abc
{
char* i;
public:
void show()
{
cout<<i;
}
void get()
{
i=new char[10];
cin>>i;
}
void operator +(abc b)
{
strcat(i,b.i);
}
};


int main()
{
abc a,b;
a.get();
b.get();
a+b;
a.show();
}
