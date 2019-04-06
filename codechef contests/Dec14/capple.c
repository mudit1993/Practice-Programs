#include<stdio.h>
int min,pos;
void findmin(int a[],int l,int h)
{
int max1,min1,pos1;
if(l==h)
{min=a[l];pos=l;}
else if(l==(h-1))
{
if(a[l]<a[h])
{min=a[l];pos=l;}
else if(a[l]==a[h])
{
min=a[h];pos=h;
a[l]=100001;
}
else
{min=a[h];pos=h;}
}
else
{
int m=(l+h)/2;
findmin(a,l,m);
min1=min;pos1=pos;
findmin(a,m+1,h);
if(min1==min)
    a[pos1]=100001;
if(min1<min)
{min=min1;pos=pos1;}
}
}
void main()
{
int t,i,j,n,cnt,temp;
scanf("%d",&t);
while(t--)
{   cnt=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        findmin(arr,0,n-1);
        temp=min;
        arr[pos]=100001;
        cnt=1;
    for(i=0;i<n-1;i++)
    {
        findmin(arr,0,n-1);
     //  printf("%d  ",min);
     if(min==100001) break;
        if(min==temp)
          {
             arr[pos]=100001;
           continue;
          }
        else
            {
                cnt++;
                temp=min;
                arr[pos]=100001;
            }
    }
    printf("%d\n",cnt);
}
}

