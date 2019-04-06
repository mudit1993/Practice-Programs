#include<stdio.h>
int main()
{
long n,n1,k,i,j,temp=0;
scanf("%ld",&n1);
long T[n1];
for(i=0;i<n1;i++)
{
    temp=0;
    scanf("%ld%ld",&n,&k);
    long arr[n][2];
    for(j=0;j<n;j++)
    {
    scanf("%ld%ld",&arr[j][0],&arr[j][1]);
    if(arr[j][0]<=k && arr[j][1]>temp)
    T[i]=arr[j][1];
    }
}
for(i=0;i<n1;i++)
printf("%d\n",T[i]);
return 0;
}

