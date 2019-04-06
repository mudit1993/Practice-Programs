#include<iostream>
using namespace std;
class abc
{
int i;
public:
void get()
{
cin>>i;
}
void disp()
{
cout<<i;
}
friend void operator -(int m,abc p)
{
cout<<m-p.i;
}
};
int main()
{
abc a;
a.get();
5-a;
}
