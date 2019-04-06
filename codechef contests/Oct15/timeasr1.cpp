#include<iostream>
#include<cmath>
using namespace std;
int main()
{
unsigned int t,i,j;
double a,ang,h,m,meet,diff=0.00833333,hr[12][60];
for(h=0;h<12;h++)
{
     meet=h*5.45454545;
      double meet1=floor(meet);
        //cout<<meet<<" " <<diff<<endl;
        for(m=0;m<=meet1;m++)
        {
            ang=(30*(h-(m/5)))+(0.5*m);
             if(ang>180)
                ang=360-ang;
        hr[(int)h][(int)m]=ang;
        }
                meet=floor(meet)+1;
        for(m=meet;m<60;m++)
        {
            ang=(30*((m*0.2)-h))-(0.5*m);

            if(ang>180)
                ang=360-ang;
            hr[(int)h][(int)m]=ang;
        }
     }
cin>>t;
while(t--)
{
    cin>>a;
    for(i=0;i<12;i++)
    {
        for(j=0;j<60;j++)
        {
           if(abs(hr[i][j]-a)<diff)
            {
                if(i<10){
                cout<<"0"<<i<<":";
                }
                else
                    cout<<i<<":";
                if(j<10)
                    cout<<"0"<<j<<endl;
                else
                    cout<<j<<endl;

            }
        }

    }
}
return 0;
}
