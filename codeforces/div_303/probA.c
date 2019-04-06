#include<stdio.h>
int main()
{
int a[100][100],c[100];
int i,j,cnt=0,n,n1;
scanf("%d",&n);
n1=n;
for(i=0;i<100;i++)
    c[i]=1;
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
scanf("%d",&a[i][j]);
    }
}
for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(a[i][j]==1)
        {
            c[i]=0;
        }
        else if(a[i][j]==2)
            c[j]=0;
        else if(a[i][j]==3)
        {c[i]=0;c[j]=0;}
    }
}
cnt=0;
for(i=0;i<n;i++)
{
    if(c[i]==1)
    cnt++;
}
printf("%d\n",cnt);
for(i=0;i<n;i++)
{
    if(c[i]==1)
    printf("%d ",i+1);
}
return 0;
}
