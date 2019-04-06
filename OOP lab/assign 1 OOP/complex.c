#include<iostream>
using namespace std;
class complexs
{
int real;
int imagine;
public:
void get_no(int r,int i)
{
real=r;
imagine=i;
}
void complexadd(times,times);
void disp();
};
void complexs::complexadd(times t1,times t2)
{
imagine=t1.imagine+t2.imagine;
real=t1.real+t2.real;
}
void complexs::disp()
{  cout<<"Complex number after addition is:"<<real<<" + "<<imagine<<"i.\n";
}
int main()
{
complexs c3,c2,c1;
c1.get_no(5,11);
c2.get_no(6,4);
c3.complexadd(c1,c2);
c3.disp();
}