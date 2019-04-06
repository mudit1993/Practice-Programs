#include<stdio.h>
int main()
{
    int t,a[1001],i,n,m,pos,odd;
scanf("%d",&t);
for(i=0;i<1001;i++)
    a[i]=-10;
while(t--)
{
odd=0;
scanf("%d%d",&n,&m);
for(i=1;i<=m;i++)
{
scanf("%d",&pos);
a[pos]=t;
}
for(i=1;i<=n;i++)
    {
        if(a[i]!=t && odd%2==0)
        {
           odd++;
            a[i]=t;
            printf("%d ",i);
        }
        else if(a[i]!=t && odd%2==1)
            odd++;

    }
printf("\n");
for(i=1;i<=n;i++)
    {
        if(a[i]!=t)
        {
            a[i]=t;
            printf("%d ",i);
        }
    }
    printf("\n");
}
return 0;
}
