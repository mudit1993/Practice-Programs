#include<stdio.h>
main()
{
int a[50][50];
int b[50][3];
int j,i,r,c,k,cnt=0;
printf("Enter no. of rows and columns respectively\n");
scanf("%d%d",&r,&c);
printf("Enter %d elements\n",(r*c));
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
scanf("%d",&a[i][j]);
}
printf("Matrix is:\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d\t",a[i][j]);
printf("\n");
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(a[i][j]!=0)
{
b[cnt][0]=i+1;
b[cnt][1]=j+1;
b[cnt][2]=a[i][j];
cnt++;
}
}
}
printf("Sparse matrix is:\n");
printf("Row\tcolumn\tnumber\n");
for(i=0;i<cnt;i++)
{
for(j=0;j<3;j++)
printf("%d\t",b[i][j]);
printf("\n");
}
}
