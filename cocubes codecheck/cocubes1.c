#include<stdio.h>
int main()
{
int arr[10][10],n,i,j,k,prod=1,maxx=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[i][j]);
    }
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        prod=1;
        for(k=0;k<4;k++)
        {
            if(j+k<n)
            prod*=arr[i][j+k];
        }
        if(maxx<prod) maxx=prod;
        prod=1;
        for(k=0;k<4;k++)
        {
            if(i+k<n)
            prod*=arr[i+k][j];
        }
        if(maxx<prod) maxx=prod;
        prod=1;
        for(k=0;k<4;k++)
        {
            if(j+k<n && i+k<n)
            prod*=arr[i+k][j+k];
        }
        if(maxx<prod) maxx=prod;
        prod=1;
        for(k=0;k<4;k++)
        {
            if(i-k>0 && j+k<n)
            prod*=arr[i-k][j+k];
        }
        if(maxx<prod) maxx=prod;
    }
}
printf("%d\n",maxx);
return 0;
}
