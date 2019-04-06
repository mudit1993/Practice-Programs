#include<stdio.h>
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
int main()
{
    int t,n,q,a[100001],f[100001],l[100001],i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        f[1]=a[1];
        for(i=2;i<=n;i++)
        {
            f[i]=gcd(f[i-1],a[i]);
        }
        l[n]=a[n];
        for(i=n-1;i>0;i--)
        {
            l[i]=gcd(l[i+1],a[i]);
        }
        while(q--)
        {
            scanf("%d%d",&j,&k);
            if(j==1)
            {
                printf("%d\n",l[k+1]);
                continue;
            }
            else if(k==n)
            {
                printf("%d\n",f[j-1]);
                continue;
            }
            else
            {
                printf("%d\n",gcd(f[j-1],l[k+1]));
            }
        }
    }
    return(0);
}
