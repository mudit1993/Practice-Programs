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
void inputdata();
void calgross();
void disp();
};
void employee::inputdata()
{
cout<<"Enter name,code,basic salary,HRA and DA respectively\n";
cin>>name>>code>>basicsal>>hra>>da;
}
void employee::calgross()
{
gross=basicsal+hra+da;
}
void employee::disp()
{
cout<<"\nName:"<<name;
cout<<"\nCODE:"<<code;
cout<<"\nGross salary is "<<gross;
}
int main()
{
employee a1;
a1.inputdata();
a1.calgross();
a1.disp();
return 0;
}

