#include<iostream>
using namespace std;
class abc
{
int i,j;
public:
abc()
{
cout<<"Enter values for i,j\n";
cin>>i>>j;
}
void disp()
{
cout<<"i="<<i<<",j="<<j<<endl;
}

friend void operator -(abc &p)
{
p.i=-p.i;
p.j=-p.j;
}
friend void operator -(abc a,abc b)
{
cout<<"i="<<a.i-b.i<<",j="<<a.j-b.j<<endl;
}
};

int main()
{
abc a1,a2;
a1.disp();
a2.disp();
cout<<"After operator overloading\n";
-a1;
-a2;
a1.disp();
a2.disp();
a1-a2;
cout<<endl;
a1.disp();
a2.disp();
}
