/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long calcgcd(long long a, long long b)
{
    long long r;
  if((a < 1) || (b < 1))
        return -1;
    do
    {
        r = a % b;
        if(r == 0)
            break;
        a = b;
        b = r;
    }
    while(1);

    return b;
}
long long NonDividingPrime(long long a, long long b)
{
	if(b==1)
		return 0;
	long long gcd = calcgcd(a,b);
	if(gcd==1)
		return 1;
	return NonDividingPrime(a,b/gcd);
}
int main()
{
	long long a,b;
	long long i;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&a);
		scanf("%lld",&b);
		if(NonDividingPrime(a,b))
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 0;

}
*/
#include <stdio.h>
#include <math.h>

int main(void) {
	// your code goes here
	int t, flag;
	unsigned long long a, b, m, n;

	scanf ("%d", &t);

	while (t--) {
	    scanf ("%llu %llu", &a, &b);
	    m = a;
	    n = b;

	    while (a != 1) {

	        a = m;
	        b = n;

	        while (b) {
                a = a % b;
                a ^= b ^= a ^= b;
            }

            n = n / a;
            printf("%llu\n",n);
	    }

	    if (n > 1) {
	        printf ("No\n");
	    } else {
	        printf ("Yes\n");
	    }
	}

	return 0;
}
