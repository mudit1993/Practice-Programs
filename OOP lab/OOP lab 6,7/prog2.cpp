#include<iostream>
using namespace std;
class student1
{
protected:
char *name;
int roll;
public:
void get1()
{
name=new char;
cout<<"Name,roll\n";
cin>>name>>roll;
}
};

class sports:public virtual student1
{
protected:
int mark;
public:
void get()
{
cout<<"enter sports marks\n";
cin>>mark;
}
};


class marks:public virtual student1
{
protected:
int m1,m2,m3,tot;
public:
void get()
{
cout<<"Enter marks of students in 3 sub\n";
cin>>m1>>m2>>m3;
tot=m1+m2+m3;
}
};


class grade:public sports,public marks
{
char grad;
public:
void grades()
{
/*student1::get1();
sports::get();
marks::get();*/
tot=(tot+mark)/4;
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
grade g;
g.student1::get1();
g.sports::get();
g.marks::get();
g.grades();

}
