#include<stdio.h>
int main()
{
int a[500][500],q,n,m,i,j,i1,j1,maxx,flag,cnt;
scanf("%d%d%d",&n,&m,&q);
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
    }
   // printf("cnt[i]=%d",cnt[i]);
}
while(q--)
{
    scanf("%d%d",&i1,&j1);
if(a[i1-1][j1-1]==1)
    a[i1-1][j1-1]=0;
else
    a[i1-1][j1-1]=1;
maxx=cnt=0;
flag=0;
/*for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        printf("%d",a[i][j]);
    }
    printf("\n");
}
printf("maxx=%d",maxx);*/
for(i=0;i<n;i++)
{
    cnt=0;
    flag=0;
    for(j=0;j<m;j++)
    {
        if(a[i][j]==1 && flag==0)
        {
            cnt++;
        }
        else if(a[i][j]==0)
        {
            flag=1;
            if(maxx<cnt)
            {maxx=cnt;}
            cnt=0;
        }
        else if(a[i][j]==1 && flag==1){
        cnt=1;
        flag=0;
        }
    }
    if(cnt>maxx)
        maxx=cnt;
   // printf("cnt[i]=%d",cnt[i]);
}
printf("%d\n",maxx);
}


return 0;
}
