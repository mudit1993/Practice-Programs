#include<stdio.h>
int main()
{
int T,i,n,j=0,pos=0,no;
scanf("%d",&T);
int r[T+1];
while(j<T)
{ no=0;
scanf("%d",&n);
int arr[n+1];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
if(arr[pos]<=arr[i])
    pos=i;
}
no=arr[pos]+pos;
for(i=0;i<n;i++)
{
if((no-i)<arr[i])
no+=(arr[i]-(no-i));
}
r[j]=no;
j++;
}
for(i=0;i<T;i++)
    printf("%d\n",r[i]);
return 0;
}
