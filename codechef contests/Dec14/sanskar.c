#include<stdio.h>
void main()
{
int t,i,n,k,j,cnt,cnt1;
long maxx,sum;
scanf("%d",&t);
while(t--)
{
    int pos=0;
    cnt1=cnt=0;
    sum=0;
    maxx=0;
scanf("%d%d",&n,&k);
long a[n],b[n];
for(i=0;i<n;i++)
{
    scanf("%ld",&a[i]);
    maxx+=a[i];
    b[i]=1;
}
if(n<k) printf("no\n");
else if(n==k)
{
    for(i=0;i<n;i++)
        if(a[i]!=a[i+1]) break;
    if(i<n-1) printf("no\n");
    else printf("yes\n");
}
else{
        if(maxx%k!=0) printf("no\n");
else{
maxx/=k;
for(i=0;i<n;i++)
    for(j=0;j<n-1-i;j++)
    if(a[j]<a[j+1])
    {
        a[j]=a[j]+a[j+1];
        a[j+1]=a[j]-a[j+1];
        a[j]=a[j]-a[j+1];
    }
                        //  for(i=0;i<n;i++)
                         //    printf("%d ",a[i]);
for(i=0;i<n;i++)
{
    sum=0;
    for(j=i;j<n;j++)
    {
    if(a[j]==maxx && b[j]>0)
    {b[j]=-1;sum=0;cnt1++;}
    else if((a[j]+sum)<=maxx && b[j]>0)
    {
        pos=j;
        b[j]=-1;
        sum+=a[j];
    }
    if(sum==maxx){sum=0;cnt1++;break;}
    }
    if(sum!=0) {b[pos]=1;}
}
//for(i=0;i<n;i++)
//printf("%d ",b[i]);
for(i=0;i<n;i++)
{
    if(b[i]==-1) cnt++;
}
if(cnt==n && cnt1==k) printf("yes\n");
else printf("no\n");
}
}
}
}
