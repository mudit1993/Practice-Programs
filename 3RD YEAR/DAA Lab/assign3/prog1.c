#include<stdio.h>
void main()
{
int n,i,mid,f=0,l;
printf("Enter number of elements\n");
scanf("%d",&n);
printf("Enter %d elements\n",n);
int arr[n+1];
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
l=n-1;
while(f<l)
{
mid=(f+l)/2;
if(arr[mid]==0)
{
f=mid+1;
}
else if(arr[mid]==1)
{
l=mid-1;
}
}
if(arr[l]==1)
{
printf("Number of 0's is %d\n",(l));
printf("Number of 1's is %d\n",(n-l));
}
else{
printf("Number of 0's is %d\n",(l+1));
printf("Number of 1's is %d\n",(n-l-1));
}
}

