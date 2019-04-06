#include<stdio.h>
int main()
{
    int t,n,i;

    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d",&n);
        int a[5*n];
        int p[n];
        for(i=1;i<=5*n;i++)
            a[i]=i;
        for(i=1;i<=n;i++)
        scanf("%d",&p[i]);

      t--;
    }

    return 0;
}
