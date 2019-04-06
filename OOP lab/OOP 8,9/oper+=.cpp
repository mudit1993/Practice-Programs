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
void show()
{
cout<<i<<endl;
}
void operator +=(abc p)
{
i+=p.i;
}

void operator -=(abc p)
{
i-=p.i;
}

void operator /=(abc p)
{
i/=p.i;
}

void operator *=(abc p)
{
i*=p.i;
}

};

int main()
{
abc a,b;
a.get();
b.get();
a+=b;
a.show();
a*=b;
a.show();
a-=b;
a.show();
a/=b;
a.show();
}
