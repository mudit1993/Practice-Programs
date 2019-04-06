#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int i,t;
    long long int n,a[100000],sumnon,sum,cx,maxx,x,neg,y,val;
    scanf("%d",&t);
    while(t--)
    {
     val=0;sumnon=0;sum=0;maxx=0;x=y=-1;cx=-1,neg=0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
         scanf("%lld",&a[i]);
            if(a[i]>0)
                sumnon+=a[i];
            else neg++;
            val=a[i]+sum;
            if(val>0)
               { if(sum==0)
                    cx=i;
                sum=val;
               }
            else sum=0;
            if(sum>maxx)
            {    maxx=sum;
                x=cx;
                y=i;
             }
        }
        sum=0;
        if(x>=0)
        for(i=x;i<=y;i++)
            sum+=a[i];
            if(neg==n)
            {maxx=-10001;
            for(i=0;i<n;i++)
            {
                if(a[i]>maxx)
                    maxx=a[i];
            }
             sumnon=sum=maxx;
        }
        printf("%lld %lld\n",sum,sumnon);
    }
     return 0;
}
