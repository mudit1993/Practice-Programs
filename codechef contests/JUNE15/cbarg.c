#include<stdio.h>
int main()
{
    int t,n;
    unsigned long long int sum=0,prev,p;
    long long int sub;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        prev=0;sum=0;
        while(n--)
        {
            scanf("%lld",&p);
            sub=(p-prev);
            if(sub>0)
                sum+=sub;
            prev=p;
        }
        printf("%lld\n",sum);

    }
return 0;
}
