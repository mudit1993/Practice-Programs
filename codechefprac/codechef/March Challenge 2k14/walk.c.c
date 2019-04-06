#include<stdio.h>
int main()
{
int T,i,n,pos=0;
scanf("%d",&T);
while(T--)
{
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
pos=0;
for(i=0;i<n;i++)
{
    if((arr[pos]+pos)<=(arr[i]+i))
    pos=i;
}
printf("%d\n",(arr[pos]+pos));
}
return 0;
}
