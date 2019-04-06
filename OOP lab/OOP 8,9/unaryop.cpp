#include<iostream>
using namespace std;
class abc
{
int i;
float j;
public:
void get()
{
cout<<"Enter 2 numbers\n";
cin>>i>>j;
}
void show()
{
cout<<i<<"\n"<<j<<endl;
}
abc operator ++()
{
abc temp;
temp.i=++i;
temp.j=++j;
return(temp);
}
abc operator ++(int b)
{
abc temp;
temp.i=i++;
temp.j=j++;
return(temp);
}
abc operator --()
{
abc temp;
temp.i=--i;
temp.j=--j;
return(temp);
}
abc operator --(int b)
{
abc temp;
temp.i=i--;
temp.j=j--;
return(temp);
}
};
int main()
{
abc a,b;
a.get();
//a.show();
b=a++;
b.show();
a.show();
a.get();
b=++a;
b.show();
a.show();
a.get();
b=a--;
b.show();
a.show();
a.get();
b=--a;
b.show();
a.show();
b=--a;
}
