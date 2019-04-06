#include<stdio.h>
int main()
{
int T,i,n,pos=0;
scanf("%d",&T);
while(T--)
{
    pos=0;
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
if((arr[pos]+pos)<=(arr[i]+i))
pos=i;
}
printf("%d",(arr[pos]+pos));
}
return 0;
}

