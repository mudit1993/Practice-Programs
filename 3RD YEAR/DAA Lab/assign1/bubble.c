#include<stdio.h>
main()
{
int i,j,n;
printf("Enter no. of elements\n");
scanf("%d",&n);
int arr[n];
printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++)
    for(j=0;j<n-1-i;j++)
    if(arr[j]<arr[j+1])
    {
        arr[j]=arr[j]+arr[j+1];
        arr[j+1]=arr[j]-arr[j+1];
        arr[j]=arr[j]-arr[j+1];
    }
printf("Sorted elements\n");
for(i=0;i<n;i++)
    printf("%d ",arr[i]);

}

