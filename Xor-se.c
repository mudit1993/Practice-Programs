#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
long long int xored(long long int x)
{
    long long int t,sum,i;
    t=(floor(x/4)*4);
    for(i=t;i<=x;i++)
        sum^=i;
    return sum;
}
int main(){
    long long int Q,i,sum,a0;
    scanf("%lld",&Q);
    for(a0 = 0; a0 < Q; a0++){
        long L;
        long R;
        sum=0;
        scanf("%ld %ld",&L,&R);
       printf("%lld\n",xored(L-1)^xored(R));
    }
    return 0;
}
