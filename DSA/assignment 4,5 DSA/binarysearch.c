#include<stdio.h>
main()
{
int a[50];
int no,f,l,flag=0,mid,r,i;
printf("Enter no. of elements\n");
scanf("%d",&r);
printf("Enter %d elements\n",r);
for(i=0;i<r;i++)
scanf("%d",&a[i]);
printf("Enter a number to be searched\n");
scanf("%d",&no);
f=0;
l=r-1;
while(f<=l)
{
mid=(f+l)/2;
if(a[mid]==no)
{
printf("Number found at position %d\n",mid+1);
flag=1;
break;
}
else if(a[mid]<no)
f=mid+1;
else
l=mid-1;
}
if(flag==0)
printf("Element does not exist\n");
}
