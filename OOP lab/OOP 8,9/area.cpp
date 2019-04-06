#include<iostream>
using namespace std;
class abc
{
static int i;
public:
abc()
{
cout<<"Enter a number\n";
cin>>i;
}
//inline void add();
void disp()
{
cout<<"Number is :"<<i;
}
};
int abc::i; 
/*inline void abc::add()
{
i=i+i;
}*/
int main()
{
abc a;
//cout<<i<<endl;
//a.add();
a.disp();
}

