#include<stdio.h>
void main()
{
int a[100],b[100],c[200];
int i,j,t,s1,s2;
printf("Enter no. of elements for array A and B respectively\n");
scanf("%d%d",&s1,&s2);
printf("Enter elements in a sorted manner for array A\n");
for(i=0;i<s1;i++)
scanf("%d",&a[i]);
printf("Enter elements in a sorted manner for array B\n");
for(i=0;i<s2;i++)
scanf("%d",&b[i]);
for(i=0;i<(s1+s2);i++)
{
if(i<s1)
c[i]=a[i];
else
c[i]=b[i-s1];
}
for(i=0;i<(s1+s2);i++)
{
for(j=0;j<(s2+s1-i-1);j++)
{
if(c[j]>c[j+1])
{ 
t=c[j+1];
c[j+1]=c[j];
c[j]=t;
}
}
}
printf("The merged sorted array is\n");
for(i=0;i<s1+s2;i++)
printf("%d ",c[i]);
}

