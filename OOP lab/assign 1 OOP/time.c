#include<iostream>
using namespace std;
class times
{
int hrs;
int mins;
public:
void get_time(int h,int m)
{
hrs=h;
mins=m;
}
void timeadd(times,times);
void disp();
};
void times::timeadd(times t1,times t2)
{
mins=t1.mins+t2.mins;
hrs=mins/60;
mins%=60;
hrs+=t1.hrs+t2.hrs;
}
void times::disp()
{  cout<<"Time is:"<<hrs<<"Hours "<<mins<<"minutes.\n";
}
int main()
{
times c3,c2,c1;
c1.get_time(5,50);
c2.get_time(6,40);
c3.timeadd(c1,c2);
c3.disp();
}
