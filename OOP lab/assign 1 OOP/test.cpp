#include<iostream>
using namespace std;
class a
{
static int count;
public:
a()
{
++count;
}
static void display()
{
cout<<"count="<<count;
}
};
int a::count=5;
int main()
{
a ob1,ob2,ob3;
ob1.display();
return 0;
}
