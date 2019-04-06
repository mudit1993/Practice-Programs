#include<iostream>
#include<string.h>
using namespace std;
main()
{
char name[20];
int i;
cout<<"Enter a name\n";
cin>>name;
try{
if(name[0]<65 || name[0]>90)
throw 1;
else if(name[(strlen(name)-1)]!='.')
throw 'c';
else
cout<<name<<endl;
}
catch(int n)
{
cout<<"First letter is small\n";
}
catch(char c)
{
cout<<"Not ending with a full stop\n";
}
}
