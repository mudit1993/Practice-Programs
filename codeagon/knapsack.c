#include<stdio.h>
int main()
{
int n,m,i,sum=0;
scanf("%d%d",&n,&m);
for(i=n;i>=1;i--){
if(m-i>=0)
{
    sum++;
    m-=i;
}
}
if(m==0)
printf("%d\n",sum);
else
    printf("-1\n");
return 0;
}
