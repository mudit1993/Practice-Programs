#include<stdio.h>
#include<math.h>
int main()
{
long int t,i,n,k,j,cnt,cnt1;
long long int maxx,sum;
scanf("%d",&t);
while(t--)
{
    sum=0;
    cnt=cnt1=0;
    maxx=0;
scanf("%ld%ld",&n,&k);
long long int a[n],b[n];
for(i=0;i<n;i++)
{
    scanf("%lld",&a[i]);
    maxx+=a[i];
    b[i]=0;
}
if(n<k){ printf("no\n");continue;}
if(maxx==0) {printf("yes\n");continue;}
if(maxx%k!=0){ printf("no\n");continue;}
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
 if(a[0]>maxx){printf("no\n");continue;}                        //    printf("%d ",a[i]);
for(i=0;i<pow(2,n);i++)
{
    sum=0;
    for(j=0;j<n;j++)
    {
    if(i&(1<<j) && b[j]==0)
        sum+=a[j];
    }
    if(sum==maxx)
    {
        cnt1++;
        for(j=0;j<n;j++)
    {
    if(i&(1<<j) && b[j]==0)
        b[j]=1;
    }
    }
}
for(i=0;i<n;i++)
printf("%d ",b[i]);
//for(i=0;i<n;i++)
//{
  //  if(b[i]==1) cnt++;
//}
if(cnt1==k) printf("yes\n");
else printf("no\n");
}
return 0;
}
