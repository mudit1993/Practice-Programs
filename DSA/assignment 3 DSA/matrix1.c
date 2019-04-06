#include<stdio.h>
void input();
int m,n,a[100][100];
void main()
{
printf("Enter no. of rows and columns respectively\n");
scanf("%d%d",&m,&n);
input();
disp();
}

void input()
{int i,j;
printf("Enter %d elements\n",(m*n));
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
}
disp()
{int i,j;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
}
