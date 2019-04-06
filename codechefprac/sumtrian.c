#include<stdio.h>
int a[100][100],n,b[100][100];
/*int sum(int k,int i,int j,int s)
{
    if(n==k) {sum+=a[i][j];return sum;}
    else if((a[i+1][j])>a[i+1][j+1])
    {s+=a[i+1][j];
    sum(k++)}
    else if(a[i+1][j]<a[i+1][j+1])
         s+=a[i+1][j+1];
    else


}*/
void main()
{
int t,n,i,j,maxx,s=0;
scanf("%d",&t);
while(t--)
{maxx=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=0;s++;
        }
    }
    b[0][0]=a[0][0];
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
           // b[i][j]=a[i][j];
            if(maxx<b[i][j]) maxx=b[i][j];
            if(b[i+1][j]<b[i][j]+a[i+1][j] && (i+1)<n)
            b[i+1][j]=b[i][j]+a[i+1][j];
            if(b[i+1][j+1]<b[i][j]+a[i+1][j+1] && (i+1)<n)
            b[i+1][j+1]=b[i][j]+a[i+1][j+1];
           //if((a[i][j]+a[i+1][j])>(a[i][j+1]+a[i+1][j+1]));
        }
    }
    printf("%d\n",maxx);
}
}
