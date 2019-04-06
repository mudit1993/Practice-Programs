#include<stdio.h>
int main()
{
int n,i,j,k=0,n1,a[100][100],cnt=0;
scanf("%d",&n);
n1=n;
while(n1!=0){
for(i=k;i<n1-1;i++)
{
    a[k][i]=++cnt;
}
for(i=k;i<n1-1;i++)
{
    a[i][n1-1]=++cnt;
}
for(i=n1-1;i>k;i--)
{
    a[n1-1][i]=++cnt;
}
for(i=n1-1;i>k;i--)
{
    a[i][k]=++cnt;
}
k++;
n1--;
}
if(n%2==1)
    a[n/2][n/2]=++cnt;
for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
    {
    printf("%d\t",a[i][j]);
    }
    printf("\n");
    }
return 0;
}
