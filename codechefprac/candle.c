#include<stdio.h>
int main()
{
int t,a[10],i,pos,min;
scanf("%d",&t);
while(t--)
{min=9;
for(i=0;i<10;i++)
    scanf("%d",&a[i]);
for(i=1;i<10;i++)
{
if(a[i]<min)
  {
        min=a[i];
        pos=i;
  }
}
if(a[0]<min){
printf("1");
}
else{
a[pos]-=1;
//if(a[1]==0 && a[0]==0) pos=0;
printf("%d",pos);}
min=9;
for(i=0;i<10;i++)
{
if(a[i]<min)
  {
        min=a[i];
        pos=i;
  }
}
while(a[pos]>=0)
{
printf("%d",pos);
a[pos]-=1;
}
printf("\n");
}
return 0;
}
//case to consider--  2 4 3 3 3 3 3 3 3 3 3..
