 #include<stdio.h>
 int max,min,arr[100];
void findmax_min(int a[],int l,int h)
{
int max1,min1;
if(l==h)
{
max=min=a[l]; 
}
else if(l==(h-1))
{
if(a[l]<a[h])
{
min=a[l];
max=a[h];
}
else
{
min=a[h];
max=a[l];
}
}
else
{
int m=(l+h)/2;
findmax_min(a,l,m);
min1=min;
max1=max;
findmax_min(a,m+1,h);
if(max1>max)
max=max1;
if(min1<min)
min=min1;
}
}
main()
{
int n,i;
printf("Enter no. of elements\n");
scanf("%d",&n);

printf("Enter %d elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
max=min=arr[0];
findmax_min(arr,0,n-1);
printf("max is: %d\nMin is: %d\n",max,min);
}
