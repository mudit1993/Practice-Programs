#include<stdio.h>
int main()
{
int a[500][500],q,n,m,i,j,i1,j1,flag,cnt,c[500],maxx;
scanf("%d%d%d",&n,&m,&q);
for(i=0;i<n;i++)
{
    c[i]=0;
    for(j=0;j<m;j++)
    {
        scanf("%d",&a[i][j]);
    }
   // printf("cnt[i]=%d",cnt[i]);
}
cnt=0;
flag=0;

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
            if(c[i]<cnt)
            {c[i]=cnt;}
            cnt=0;
        }
        else if(a[i][j]==1 && flag==1){
        cnt=1;
        flag=0;
        }
    }
    if(cnt>c[i])
        c[i]=cnt;
    // printf("cnt[i]=%d",cnt[i]);
}
//for(i=0;i<n;i++)
  //  printf("%d ",c[i]);
while(q--)
{
    scanf("%d%d",&i1,&j1);
    i1--;j1--;
if(a[i1][j1]==1)
    a[i1][j1]=0;
else
    a[i1][j1]=1;

c[i1]=0;
flag=cnt=0;

for(j=0;j<m;j++)
{
if(a[i1][j]==1 && flag==0)
        {
            cnt++;
        }
        else if(a[i1][j]==0)
        {
            flag=1;
            if(c[i1]<cnt)
            {c[i1]=cnt;}
            cnt=0;
        }
        else if(a[i1][j]==1 && flag==1){
        cnt=1;
        flag=0;
        }
    }
    if(cnt>c[i1])
        c[i1]=cnt;
maxx=0;
for(i=0;i<n;i++)
    if(maxx<c[i])
        maxx=c[i];
printf("%d\n",maxx);
}


return 0;
}
