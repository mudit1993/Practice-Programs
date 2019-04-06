#include<stdio.h>
int main()
{
int t,n,i,j;
long long int minn;
scanf("%d",&t);
while(t--)
{
    minn=1000000000;
    scanf("%d",&n);
    long long int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(minn>(abs(a[i]-a[j])))
                minn=abs(a[i]-a[j]);
        }
    }
printf("%d\n",minn);
}
return 0;
}
