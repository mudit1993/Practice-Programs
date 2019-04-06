#include<stdio.h>
//int arr[20];
void insertsort(int a[],int n)
{
    int i,j,item;
    for(i=1;i<n;i++)
    {
        j=i-1;
        item=a[i];
        while(a[j]>item && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=item;
    }

}
void main()
{
int n,i;
printf("Enter size of the array\n");
scanf("%d",&n);
int arr[n];
printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
insertsort(arr,n);
for(i=0;i<n;i++)
printf("%d ",arr[i]);
}

