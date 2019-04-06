#include<stdio.h>
void main()
{
int t,n,cnt,i;
scanf("%d",&t);
int a[]={2048,1024,512,256,128,64,32,16,8,4,2,1};
while(t--)
{
    cnt=0;
scanf("%d",&n);
for(i=0;i<12;i++)
 {
       while(n>=a[i])
       {
           n-=a[i];
           cnt++;
       }
 }
 printf("%d\n",cnt);
}
}

