#include<stdio.h>
void main()
{
int n,i,j;
printf("Enter size of a square matrix\n");
scanf("%d",&n);
int a[n][n];
for(i=0;i<n;i++)
{
printf("Enter %d elements\n",n);
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}//taking input
j=i=0;
int row,j1=0;
while(a[i][j]==1 || (i!=n && j!=n))
{
if(a[i][j]==0)
{
if(j1<j)
{row=i;
j1=j;
} 
i++;
}
else {
j++;
if(j==n)
{
row=i; break;
}
}
}
printf("Row- %d \nNumber of 1's- %d\n",row+1,j);
}

