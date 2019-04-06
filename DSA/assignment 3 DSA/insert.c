#include<stdio.h>
void main()
{
int a[100];
int i,no,pos;
printf("Enter 10 elements in a sorted manner\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
printf("Enter an element to be inserted\n");
scanf("%d",&no);
for(i=0;i<10;i++)
{
if(no>a[i] && a[i]>a[i+1])
{
pos=i; break;
}
if(no<a[i] && a[i]<a[i+1])
{ pos=i;break;
}
pos=10;
a[pos]=no;
}
printf("Updated array is:\n");
if(pos==10)
{
for(i=0;i<11;i++)
printf("%d ",a[i]);
}
else{
for(i=11;i>pos;i--)
a[i]=a[i-1];
a[pos]=no;
for(i=0;i<11;i++)
printf("%d ",a[i]);
}
}
