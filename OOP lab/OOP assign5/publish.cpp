#include<iostream>
using namespace std;
class publisher
{
protected:
char *name,*address;
public:
void get()
{
name=new char;
address=new char;
cout<<"Enter name of the publisher and address of the publisher"<<endl;
cin>>name>>address;
}
};
class book:public publisher
{
protected:
char *bname,*author,*isbn,*year;
float price;
public:
void get1()
{
bname=new char;
author=new char;
isbn=new char;
year=new char;
cout<<"Enter Book name,Author Name,isbn no.,year of publication,price respectively\n";
cin>>bname>>author>>isbn>>year>>price;
}
};
class bil:private book
{
protected:
int copies;
int tot;
public:
void disp()
{
get();
get1();
cout<<"Enter No. of copies\n";
cin>>copies;
cout<<"\nPublisher Name:"<<name<<"\nAddress of the publisher:"<<address<<"\nBook Name:"<<bname<<"\nAuthor name:"<<author<<"\nISBN Number:"<<isbn<<"\n Year of Publication:"<<year<<"\nPrice of each Book:"<<price<<"\n No.of Copies:"<<copies<<"\n Total price"<<(price*copies)<<endl;
}
};
main()
{
bil a;
a.disp();
}
