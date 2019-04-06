#include<stdio.h>
int main()
{
long long int m,t,i;
double c,d,p,c1,p1;
scanf("%lld",&t);
while(t--)
{
c=1000000000;d=0,i=0;
scanf("%lld%lf",&m,&p);
if(m>=2)
{
    d=c*p;
    if(p<=0.5000)
    {
        printf("%lf %lf\n",c-d,d);
    }
    else{
    while(i<m && (c-d)<(d)){
        //printf("%lf %lf %lf\n",c-d,d,c/2);
        c=d;
        d=c*p;
        i++;

    }
    if(i<m && i%2==0)
    {
        printf("%lf %lf\n",c-d,d);
    }
    else if(i<m && i%2==1)
    {
    printf("%lf %lf\n",d,c-d);
    }
    else{
        if(i%2==1)
        printf("%lf %lf\n",d,c-d);
            else
        printf("%lf %lf\n",c-d,d);
    }
    }
}
else{
    printf("%lf %lf\n",c,d);
}
}
return 0;
}
