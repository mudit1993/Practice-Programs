#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t,n,a,b,maxx,minn,diff,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        minn = a>b?b:a;
        maxx = a>b?a:b;
        n--;
        diff=maxx-minn;
        maxx = n*maxx;
        if(diff!=0)
        for(i=n*minn;i<=maxx;i+=diff)
        {
            printf("%d ",i);

        }
        else printf("%d ",maxx);
        printf("\n");
    }


    return 0;
}
