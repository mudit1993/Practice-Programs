#include<iostream>
using namespace std;
float area(float r1,float &c)
{
	c=2*3.14*r1;
	return(3.14*r1*r1);
}
main()
{
	float r;
	cout<<"Enter radius of the circle\n";
	cin>>r;
	cout<<"Area of the circle is: "<<area(r,r)<<"\n";
	cout<<"Circumference of the circle is: "<<r<<"\n";
}

