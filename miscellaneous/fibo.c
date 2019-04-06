#include<stdio.h>
void fibo(n,c,a,b)
{
if(n<0)
return 1;
else
{
printf("%d,",c);
c=a+b;
a=b;
b=c;
return(n-1,c,a,b);
}
}
main()
{
int n=5;
fibo(n,0,-1,1);
}
