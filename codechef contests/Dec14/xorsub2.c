#include<stdio.h>
#include<math.h>
int main()
{
    int n,k,i,j,t,maxx,b[2048],x;
    scanf("%d",&t);
    for(i=0;i<2048;i++) b[i]=0;
    while(t)
    {maxx=0;
        b[0]=t;
        scanf("%d%d",&n,&k);
        for(j=0;j<n;j++)
        {scanf("%d",&x);
            for(i=0;i<2048;i++)
            {
                if(b[i]==t)
                b[x^i]=t;
            }
        }
        maxx=0;
        for(i=0;i<2048;i++)
        {
            if((k^i)>maxx && b[i]==t)
            {
                maxx=k^i;
                //printf("\n%d  ",value(k,i));
            }
        }
        t--;
        printf("%d\n",maxx);
        }
return 0;
}


