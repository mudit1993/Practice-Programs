#include<iostream>
using namespace std;
class employee
{
int code;
char name[20];
float basicsal;
int hra,da;
float gross;
public:
inline void inputdata();
inline void calgross();
inline void disp();
};
inline void employee::inputdata()
{
cout<<"Enter name,code,basic salary,HRA and DA respectively\n";
cin>>name>>code>>basicsal>>hra>>da;
}
inline void employee::calgross()
{
gross=basicsal+hra+da;
}
inline void employee::disp()
{
cout<<"\nName:"<<name;
cout<<"\nCODE:"<<code;
cout<<"\nGross salary is "<<gross<<"\n";
}
int main()
{
employee a1;
a1.inputdata();
a1.calgross();
a1.disp();
return 0;
}
