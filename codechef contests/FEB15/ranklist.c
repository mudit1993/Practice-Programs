#include<stdio.h>
int main()
{
    int t,i;
    long long int n,s,sum;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%lld%lld",&n,&s);
    if(n==s){printf("%d\n",n-1);continue;}
    for(i=1;i<=n && (n-i+1)<s;i++)
    {
        s-=i;
    }
    if((n-i+1)==s )
        printf("%d\n",n-i+1);
    else if((n-i+1)>s )
        printf("%d\n",n-i+2);
    }
return 0;
}
