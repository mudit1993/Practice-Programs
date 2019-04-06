#include<stdio.h>
int main()
{
 long long int i,n,a,a1,twos=1,flag;
 scanf("%lld",&n);
 for(i=0;i<n;i++)
 {
     twos=1;
    scanf("%lld",&a);
    a1=a;
    while(a1%10==0)
        a1/=10;
    flag=1;
    while(a1%5==0)
    {
        if(flag)
        {
        twos*=4;
        flag--;
        }
        else
        flag++;
        a1/=5;
    }
    printf("%lld\n",(a*twos));
 }
return 0;
}
