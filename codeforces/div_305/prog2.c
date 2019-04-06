#include<stdio.h>
int main()
{
int a[500][500],q,n,m,i,j,cnt[500];
scanf("%d%d%d",&n,&m,&q);
for(i=0;i<n;i++)
{   cnt[i]=0;
    for(j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]==1)
            cnt[i]+=1;
    }
   // printf("cnt[i]=%d",cnt[i]);
}
while(q--)
{
    scanf("%d%d",&i,&j);
if(a[i-1][j-1]==1)
{
    cnt[i-1]-=1;
    a[i-1][j-1]=0;
    printf("%d\n",cnt[i-1]);
}
else
{
    cnt[i-1]+=1;
    a[i-1][j-1]=1;
    printf("%d\n",cnt[i-1]);
}
}


return 0;
}
