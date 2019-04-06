#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
char a[100][100];
int n,i,j;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%s",a[i]);
}
for(i=1;i<n-1;i++)
{
   for(j=1;j<n-1;j++)
   {
       if(a[i-1][j]<a[i][j] && a[i][j-1]<a[i][j] && a[i+1][j]<a[i][j]&& a[i][j+1]<a[i][j])
        a[i][j]='X';
   }
}
for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
    printf("%c",a[i][j]);
  printf("\n");
}
return 0;
}
