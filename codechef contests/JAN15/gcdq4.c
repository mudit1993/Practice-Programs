#include<stdio.h>
int scan(int *no)
{
        int n=0;
        register int ch=getchar();
        for(;ch>47&&ch<58;ch=getchar())
        {
                n=(n<<1)+(n<<3)+ch-48;
        }
        *no=n;
}
int gcd(int a,int b)
 {int t;
        while(b!=0)
    {
       t=b;
       b=a%b;
       a=t;
    }
    return a;

 }
int main()
{
int t,n,q,a[100002],i,l,j,r,g;
scan(&t);
while(t--)
{
scan(&n);
scan(&q);
for(i=1;i<=n;i++)
    scan(&a[i]);
while(q--)
{
    g=100001;
    scan(&l);
    scan(&r);
    for(i=1;i<=n;i++)
    {
        if(i==l) {i=r;continue;}
        else
        {
             g=a[i];break;
        }
    }
   // printf("%d,",g);
    for(j=1;j<l;j++)
    {

            if(g==a[j]) continue;
            else if(a[j]%g==0) continue;
            else
                g=gcd(a[j],g);
            //printf("%d,",g);
        if(g==1) break;
    }
   // printf("%d-",g);
    if(g!=1)
    {
          for(j=r+1;j<=n;j++)
            {

            if(g==a[j]) continue;
            else if(a[j]%g==0) continue;
            else
                g=gcd(a[j],g);
            //printf("%d,",g);
        if(g==1) break;
        }
    }
    printf("%d\n",g);
}
}
return 0;
}
