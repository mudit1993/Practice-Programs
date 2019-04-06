#include<iostream>
using namespace std;
class abc
{
static int c;
public:
abc()
{
c++;
}
void disp()
{
cout<<"No.of objects:"<<c;
}
};
int abc::c=0;
int main()
{
abc a,b,c,d;
a.disp();
}
