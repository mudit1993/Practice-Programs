#include<stdio.h>
main()
{
int i,j,n,no;
printf("Enter no. of elements\n");
scanf("%d",&n);
int arr[n];
printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
for(i=0;i<n;i++)
{
    no=i;
    for(j=i;j<n;j++)
    {
    if(arr[j]<arr[no])
     {no=j;
     }

    }
    if(no!=i)
    {arr[i]=arr[i]+arr[no];
        arr[no]=arr[i]-arr[no];
        arr[i]=arr[i]-arr[no];}
}
printf("Sorted elements\n");
for(i=0;i<n;i++)
    printf("%d ",arr[i]);

}

