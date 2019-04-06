#include<stdio.h>
int main()
{
    int n,i,mid,beg=0,last,item,f=0;
printf("Enter no. of elements\n");
scanf("%d",&n);
int arr[n];
last=n-1;
printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("Enter item to be searched\n");
scanf("%d",&item);
while(beg<last)
{
    mid=(beg+last)/2;
    if(arr[mid]==item)
    {
        printf("Element found in position %d",mid+1);
        f=1;
        break;
    }
    else if(arr[mid]>item)
    {
        last=mid-1;
    }
    else beg=mid+1;
}
if(f==0)
    printf("Element not found\n");

}
