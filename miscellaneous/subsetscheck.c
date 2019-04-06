#include<stdio.h>
void main()
{
int a[]={1,2,3,4,5};
int n=5,i,j;
for(i=0;i<pow(2,n);i++)
{for(j=0;j<n;j++)
if(i&1<<j)
printf("%d,",a[j]);
printf("}\n{");
}
}
