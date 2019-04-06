#include<stdio.h>
void main()
{
int i,k,j;
int n,t;
int a[100000];
for(i=0;i<100000;i++) a[i]=0;
scanf("%d",&t);
while(t)
{
    k=0;
      scanf("%d",&n);
 //int a[n];
for(i=0;i<n;i++)
{
    scanf("%d",&j);
    if(a[j]==t) continue;
    else
    {a[j]=t;k++;}
}
//for(i=0;i<100000;i++)
  //{
    //  if(a[i]==t) k++;
  //}
   /* if(b[a[i]]!=t)
    {b[a[i]]=t;
    k++;}*/
t--;
printf("%d\n",k);
}
}
