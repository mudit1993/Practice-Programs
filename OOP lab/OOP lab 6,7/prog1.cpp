#include<iostream>
using namespace std;
class abc
{
public:
abc()
{
cout<<"Default constructor in base class\n";
}
abc(int p)
{
cout<<"Parameterized constructor in base class\n";
}
~abc()
{
cout<<"destructor in base class\n";
}
};

class def:public abc
{
public:
def()
{
cout<<"Default constructor in derived class\n";
}
def(int p):abc(p)
{
//abc(5);
cout<<"Parameterized constructor in derived class\n";
}
~def()
{
cout<<"destructor in derived class\n";
}
};

main()
{
def d1;
def d2(3);
}
