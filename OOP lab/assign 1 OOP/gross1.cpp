#include<iostream>
#include<string.h>
using namespace std;
class employee
{
int code;
char name[20];
float basicsal;
int hra,da;
float gross;
public:
void inputdata(char s[40],int c,float sal,int h,int d)
{
strcpy(name,s);
code=c;
basicsal=sal;
hra=h;
da=d;
}
void calgross();
void disp();
};
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
char n1[40];
int c1,h1,d1;
float b1;
cout<<"Enter name\n";
cin>>n1;
cout<<"Enter basic salary\n";
cin>>b1;
cout<<"Enter code, HRA and DA respectively\n";
cin>>c1>>h1>>d1;
a1.inputdata(n1,c1,b1,h1,d1);
//a1.inputdata("ABCD",211,200000,2000,2000);
a1.calgross();
a1.disp();
return 0;
}
