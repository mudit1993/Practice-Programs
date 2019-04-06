#include<stdio.h>
void main()
{
int a[10];
int i,n,small,large,p1,p2;
printf("Enter 10 elements\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
small=large=a[0];
for(i=0;i<10;i++)
{
if(small>a[i])
{small=a[i];
p1=i;}
if(large<a[i])
{large=a[i];
p2=i;
}
}
a[p1]=large;
a[p2]=small;
for(i=0;i<10;i++)
printf("%d ",a[i]);
}
