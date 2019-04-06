#include <stdio.h>
void main()
{
int arr[1000],no,i,n,k=0;
do{
printf("Enter no. of elements in the array(should be less than 1000)\n");
scanf("%d",&n);
}while(n>1000 || n<1);
printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("Enter a number to be searched\n");
scanf("%d",&no);
for(i=0;i<n;i++)
{
if(arr[i]==no)
{ printf("Number is found in position %d\n",i+1);
k=1;
//break;
}
}
if(k==0)
printf("Number not found\n");
}

