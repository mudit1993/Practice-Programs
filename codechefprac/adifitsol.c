#include<stdio.h>
//int x[10][100001];
int main()
{
    int x[10][100001];
    int n,m,i,j,t,k;
    long int b1,b2;
    char a[100000];
    scanf("%d%d",&n,&m);
    scanf("%s",a);
    for(i=0;i<10;i++)
    {
        x[i][0]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<10;j++)
        {
            x[j][i]=x[j][i-1];
        }
        x[a[i-1]-48][i]++;
    }
    while(m--)
    {
        scanf("%d",&t);
        b1=b2=0;
        k=a[t-1]-48;
        for(j=0;j<k;j++)
        {
            b1=b1+x[j][t]*(k-j);
        }
        for(j=k;j<10;j++)
        {
            b2=b2+x[j][t]*(j-k);
        }
        printf("%ld\n",b1+b2);
    }
    return(0);
}
