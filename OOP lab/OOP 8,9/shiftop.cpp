#include<iostream>
using namespace std;
class abc
{
int i;
public:friend istream &operator>>(istream &q, abc &p);
friend ostream &operator<<(ostream &q, abc &p);
};
 istream &operator>>(istream &q, abc &p)
{
q>>p.i;
return q;
}
 ostream &operator<<(ostream &q, abc &p)
{
q<<p.i;
return q;
}

int main()
{
abc a;
cout<<"Enter a number\n";
cin>>a;
cout<<a;
}
