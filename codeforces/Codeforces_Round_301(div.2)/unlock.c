#include<stdio.h>
int main()
{
 int n,i,cnt=0,dif1,dif2;
    char a[1001],unlock[1001];
scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",unlock);
    cnt=0;
//printf("%c,%c",a[i],unlock[i]);
for(i=0;i<n;i++)
{
    dif1=a[i]-unlock[i];
   dif2=unlock[i]-a[i];
   if(dif1<0)
    dif1+=10;
   else
    dif2+=10;
   if(dif1<dif2)
    cnt+=dif1;
   else
    cnt+=dif2;
}
printf("%d\n",cnt);
return 0;
}
