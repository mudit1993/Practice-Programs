#include<stdio.h>
int main()
{
int T,i,n,pos=0;
scanf("%d",&T);
while(T>0)
{
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
if(arr[pos]<=arr[i])
pos=i;
}
printf("%d",(arr[pos]+pos));
T--;
}
return 0;
}
