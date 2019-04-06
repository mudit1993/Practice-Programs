#include<iostream>
using namespace std;
class abc
{
protected:
float amt;
float r;
int yrs;
public:
void get()
{
cout<<"Enter principle amount,rate%,no.of years\n";
cin>>amt>>r>>yrs;
}
};
class def: public abc
{
float si;
public:
void disp()
{
si=0.01*amt*r*yrs;
cout<<"Simple interest is :"<<si<<endl;
}
};
main()
{
def a1;
a1.get();
a1.disp();
}
