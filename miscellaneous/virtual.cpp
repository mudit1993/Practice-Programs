#include<iostream>
using namespace std;
class base
{
public:
virtual void show();
//virtual void show()
//{
//cout<<"Yes!!\n";
//}
};
class derived:public base
{
public:
virtual void show()
{
cout<<"no\n";
}
};
void base::show()
{
cout<<"Yes!!\n";
}
class derived1:public base
{
public:
void show()
{
cout<<"hello\n";
}
};
int main()
{
base *ptr,b1;
derived d;
derived1 d1;
ptr=&b1;
ptr->show();
ptr=&d;
ptr->show();
ptr=&d1;
ptr->show();
}
