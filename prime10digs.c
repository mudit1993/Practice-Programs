#include<stdio.h>
#include<math.h>
int prime(long long int no)
{
    long long int j;
    for(j=3;j<=sqrt(no);j=j+2)
    {
        if(no%j==0){return 0;}
    }
    return 1;
}
int main()
{
long long int i,cnt=0;
for(i=9999999999;i<10000050000;i=i+4)
{
if(prime(i)==1){
        cnt++;
    printf("%lld,",i);}
}
printf("\ncnt=%lld\n",cnt);
return 0;
}
