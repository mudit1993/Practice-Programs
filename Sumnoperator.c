#include<stdio.h>

int Add(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry now contains common set bits of x and y
        int carry = x & y;
        printf("carry %d\n",x&y);

        // Sum of bits of x and y where at least one of the bits is not set
        x = x ^ y;
 printf("x %d\n",x);
        // Carry is shifted by one so that adding it to x gives the required sum
        y = carry << 1;
        printf("y %d\n",y);
    }
    return x;
}

int main()
{
    printf("%d", Add(15, 31));
    return 0;
}
