#include <stdio.h>
void main()
{
int arr[10][10];
int no,i,r,c,k=0,j;;
printf("Enter no. of rows and columns respectively \n");
scanf("%d %d",&r,&c);
printf("enter %d elements",r*c);
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
scanf("%d",&arr[i][j]);
}
}
printf("Array is\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
printf("%d\t",arr[i][j]);
printf("\n");
}
printf("Enter a number to be searched\n");
scanf("%d",&no);
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(arr[i][j]==no)
{ printf("Number is found in row %d and column %d\n",i+1,j+1);
k=1;
//break;
}
}
}
if(k==0)
printf("Number not found\n");
}

