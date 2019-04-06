#include<stdio.h>
int main()
{
int i,a[1001],n,no;
scanf("%d",&n);
for(i=0;i<1001;i++)
    a[i]=0;
for(i=0;i<n;i++)
{
    scanf("%d",&no);
    a[no]++;
}
printf("%d\n",n);
for(i=0;i<1001;i++)
{
    if(a[i]==0) continue;
    else
    {
        n-=a[i];
        if(n==0) break;
        printf("%d\n",n);
    }
}
return 0;
}
