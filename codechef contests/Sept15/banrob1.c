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
    if(p==1)
    {
        //if(m%2==0)
        //printf("%lf %lf\n",c-d,d);
        //else
        printf("0.00000 0.00000\n");

    }
    else{

         while((c+d)>1000000000 && i<m)
            {
                c=d;
                d=c*p;
                i++;
               // printf("%lf %lf %lld\n",d,c-d,i);
            }
            if(1000000000-c<c)
        printf("%lf %lf\n",c,1000000000-c);
        else
        printf("%lf %lf\n",1000000000-c,c);
    }
}
else{
    printf("%lf %lf\n",c,d);
}
}
return 0;
}
