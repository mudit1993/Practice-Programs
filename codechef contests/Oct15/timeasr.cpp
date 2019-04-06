#include<iostream>
#include<cmath>
using namespace std;
int main()
{
unsigned int t;
double a,ang,h,m,meet,diff=((double)1/120);
cin>>t;
while(t--)
{
    cin>>a;
    for(h=0;h<12;h++)
    {
        meet=h*((double)60/11);
        double meet1=floor(meet);
        //cout<<meet<<" " <<diff<<endl;
        for(m=0;m<=meet1;m++)
        {
            ang=(30*(h-(m/5)))+(0.5*m);
             if(ang>180)
                ang=360-ang;
                //cout<<h<<":"<<m<<"    "<<ang<<" ----abs"<<endl;

            if(abs(ang-a)<diff)
            {

                if(h<10){
                cout<<"0"<<(int)h<<":";
                }
                else
                    cout<<(int)h<<":";
                if(m<10)
                    cout<<"0"<<(int)m%60<<endl;
                else
                    cout<<(int)m%60<<endl;

            }
        }
        meet=floor(meet)+1;
        for(m=meet;m<60;m++)
        {
            ang=(30*((m*0.2)-h))-(0.5*m);

            if(ang>180)
                ang=360-ang;
            if(abs(ang-a)<diff)
            {
                if(h<10){
                cout<<"0"<<(int)h<<":";
                //cout<<"m---"<<m<<endl;

                }
                else
                    cout<<(int)h<<":";
                if(m<10)
                    cout<<"0"<<(int)m<<endl;
                else
                    cout<<(int)m<<endl;

                }
        }
    }
}
return 0;
}
