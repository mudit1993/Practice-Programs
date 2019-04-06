#include<iostream>
#include<conio.h>
using namespace std;
main()
{
char s,n; float t; int a,b; do{
cout<<" "<<endl;
cin>>a;
cin>>s;
cin>>b;
switch(s)
{
case '+': t=a+b;
cout<<t<<endl;
break;
case'-':t=a-b;
cout<<t<<endl;
break;
case'*':t=a*b;
cout<<t<<endl;
break;
case'%':cout<<a%b<<endl;
break;
case'/':t=a/b;
cout<<t<<endl;
break;
default:cout<<"wrong partten"<<endl;
}cout<<"do u want to go on"<<endl;
cin>>n;}while(n=='y');
cout<<"woo tired haaaa!!!!!!"<<endl;
getch();
return 0;
}
