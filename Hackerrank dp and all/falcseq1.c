#include<stdio.h>
long long int a[3001][3001];
int main()
{
int n,i,j;
long long int no,maxx=-1000001,sum=0;
scanf("%d",&n);
for(i=0;i<n;i++)
   {
       scanf("%lld",&no);
       a[0][i+1]=no;
       a[i+1][0]=no;
   }
for(i=2;i<=n;i++)
{sum=0;
    for(j=1;j<=(i/2);j++)
    {
        sum+=(a[i-j+1][0]*a[0][j]);

    }
    if(maxx<sum)
            maxx=sum;
}
    for(j=n-1;j>=2;j--)
    {sum=0;
    for(i=n;i>n-(j/2);i--)
    {
        sum+=(a[i][0]*a[0][n-j+1+(n-i)]);

    }
    if(maxx<sum)
            maxx=sum;
    }
printf("%lld\n",maxx);
return 0;
}
