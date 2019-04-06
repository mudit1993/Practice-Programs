#include<iostream>
using namespace std;
class distances
{
int feet;
int inch;
public:
void getdistance(int f,int i)
{
feet=f;
inch=i;
}
void distadd(distances,distances);
void disp();
};
void distances::distadd(distances t1,distances t2)
{
inch=t1.inch+t2.inch;
feet=inch/12;
inch%=12;
feet+=t1.feet+t2.feet;
}
void distances::disp()
{  cout<<"Distance is:"<<feet<<"feet "<<inch<<"inches.\n";
}
int main()
{
distances c3,c2,c1;
c1.getdistance(5,11);
c2.getdistance(6,4);
c3.distadd(c1,c2);
c3.disp();
}
