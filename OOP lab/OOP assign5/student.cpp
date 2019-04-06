#include<iostream>
#include<string.h>
using namespace std;
class abc
{
protected:
char *name;
char *sec;
char *date;
char *branch;
int age,roll;
public:
void get()
{name=new char;
sec=new char;
date=new char;
branch=new char;
cout<<"Enter Name,age,roll no.,secton,date of admission,branch of a student respectively\n";
cin>>name>>age>>roll>>sec>>date>>branch;
}
};
class def
{
protected:
int s1,s2,s3,s4;
public:
void get1()
{
cout<<"Enter marks of  4 subjects\n";
cin>>s1>>s2>>s3>>s4;
}
};
class efg:public abc,public def
{
int tot;
char grad;
public:
void disp()
{
cout<<"\nStudent details:\nName:"<<name<<"\n Age:"<<age<<"\n Roll no.:"<<roll<<"\nsection:"<<sec<<"\n date:"<<date<<"\n Branch:"<<branch<<endl;
tot=s1+s2+s3+s4;
cout<<"Total marks:"<<tot<<endl;
}
void grade()
{
tot/=4;
if(tot>=90)
grad='O';
else if(tot>=80 && tot<90)
grad='E';
else if(tot>=70 && tot<80)
grad='A';
else if(tot>=60 && tot<70)
grad='B';
else if(tot>=50 && tot<60)
grad='C';
else if(tot>=40 && tot<50)
grad='D';
else if(tot<40)
grad='F';
cout<<"Grade is:"<<grad<<endl;
}
};
main()
{
efg a1;
a1.get();
a1.get1();
a1.disp();
a1.grade();
}
