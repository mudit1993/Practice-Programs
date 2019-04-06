#include<stdio.h>
int main()
{
long i,j,L,M,N,E1=0,E2=0,r,c,f1=-1,f2=-1;
scanf("%ld%ld",&N,&M);
long arr[N][M];
for(i=0;i<N;i++)
{
    for(j=0;j<M;j++)
    {
        scanf("%ld",&arr[i][j]);
    }
}
scanf("%ld",&L);
long arr1[L][2];
for(i=0;i<L;i++)
{
     for(j=0;j<2;j++)
     {
    scanf("%ld",&arr1[i][j]);
    }
    if(arr1[i][0]<=N&&arr1[i][1]<=M&&arr1[i][0]>=0 &&arr1[i][1]>=0 && f1==-1)
    {
        r=arr1[i][0];
        c=arr1[i][1];
        E1+=arr[r-1][c-1];
    }
    else
    {
        f1=0;
        E1=-1;
    }
    if(arr1[i][0]<=M&&arr1[i][1]<=N&&arr1[i][0]>=0 &&arr1[i][1]>=0 && f2==-1)
    {
        c=arr1[i][0];
        r=arr1[i][1];
         E2+=arr[r-1][c-1];
    }
    else
        {
            E2=-1; f2=0;
        }
}
if(E1>=E2)
    printf("%d",E1);
else if(E1<=E2)
    printf("%d",E2);
return 0;
}

