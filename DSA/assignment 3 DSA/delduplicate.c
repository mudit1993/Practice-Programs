#include<stdio.h>
void main()
{
int a[10];
int i,c=10,j,k;
printf("Enter 10 elements\n");
for(i=0;i<10;i++)
scanf("%d",&a[i]);
for(i=0;i<c;i++)
{
for(j=i+1;j<10;j++)
{ 
if(a[i]==a[j])
{
for(k=j;k<c;k++)
a[k]=a[k+1];
c--;
j--;
}
}
}
for(i=0;i<c;i++)
printf("%d ",a[i]);
}

