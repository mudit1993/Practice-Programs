#include<stdio.h>
#include<math.h>
int main()
{
int t;
float ls,b,minn=0.0,maxx=0.0;
scanf("%d",&t);
while(t--)
{
    scanf("%f%f",&b,&ls);
    //if(b-ls<0)
    //minn=(float)sqrt(-((b*b)-(ls*ls)));
    //else
       minn=(float)sqrt((ls*ls)-(b*b));
     maxx=(float)sqrt(((b*b)+(ls*ls)));
    printf("%f %f\n",minn,maxx);
}
return 0;
}
