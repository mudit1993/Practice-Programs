#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int kaprekar(long long int no)
{
long long int sqr,i,l,r,temp=no,dig=0;
while(temp/=10)
    dig++;
dig++;
sqr=no*no;
r=sqr%(long long int)pow(10,dig);
l=sqr/(long long int)pow(10,dig);
if((l+r)==no)
    return 1;
else return 0;
}

int main() {


    long long int p,q,i,f=0;
    scanf("%lld%lld",&p,&q);
    for(i=p;i<=q;i++)
    {
        if(kaprekar(i)==1)
        { printf("%lld ",i);f=1;}
    }
    if(f==0)
        printf("INVALID RANGE\n");
     return 0;
}
