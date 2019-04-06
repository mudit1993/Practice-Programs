#include<stdio.h>
int main()
{
int t;
double t1,t2,t01,t02;
double f,temp1,temp2,temp3,temp4;
scanf("%d",&t);
while(t--)
{
    scanf("%lf%lf%lf%lf",&t01,&t02,&t1,&t2);
    temp1=1-(t1/t01);
    temp3=1-(t1/t02);
    temp2=1-(t2/t02);
    temp4=1-(t2/t01);
    f=1-(temp1*temp3*0.5)-(temp4*temp2*0.5);
    if(t01>t02)
        f*=t02/t01;
    else
        f*=(t01/t02);
    printf("%lf\n",f);


}
return 0;
}
