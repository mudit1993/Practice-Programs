#include<iostream>
using namespace std;
class dollar;
/*class dollar
{
float dol;
public:
dollar()
{
cout<<"Enter dollars\n";
cin>>dol;
//l.rup=dol*61;
}
float get()
{
    return dol;
}
//operator float()
//{
//return dol;
//}
};*/
class rupee
{
float rup;
public:
void put()
{
cout<<"Rs."<<rup;
}
rupee(){
}
rupee(dollar ob)
{
  rup=61*ob.dollar::get();
}
};
class dollar
{
float dol;
public:
dollar()
{
cout<<"Enter dollars\n";
cin>>dol;
//l.rup=dol*61;
}
float get()
{
    return dol;
}
//operator float()
//{
//return dol;
//}
};
//rupee::rupee(dollar d)
//{
//rup=d*61;
//}
int main()
{
rupee a;
dollar b;
//b.get(a);
a=b;
a.put();
return 0;
}
