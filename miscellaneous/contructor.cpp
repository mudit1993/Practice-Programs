#include<iostream>
using namespace std;
class abc
{
    public:
    abc()
    {
    cout<<"Default  base Constructor\n";
    }
    abc(int p)
    {
    cout<<"Parameterized base constructor\n";
    }
    ~abc()
    {
    cout<<"Destructor in base\n";
    }
};
class def:public abc
{
    public:
    def():abc()
    {
        abc(5);
    cout<<"Default constructor derived\n";
    }
    def(int p)//:abc(10)
    {
        abc(5);
    cout<<"Parameterized derived constructor\n";
    }
   ~def()
    {
    cout<<"Destructor in derived\n";
    }
};
int main()
{
def a1;
//def a2(20);
return 0;
}
