#include<stdio.h>
void main()
{
long int t,i,n,k,j,cnt,cnt1,cnt2;
long long int maxx,sum;
scanf("%d",&t);
while(t--)
{
    // pos=0;
    cnt1=cnt=cnt2=0;
    sum=0;
    maxx=0;
scanf("%ld%ld",&n,&k);
long long int a[n],b[n];
for(i=0;i<n;i++)
{
    scanf("%lld",&a[i]);
    maxx+=a[i];
    b[i]=0;
}
if(n<k) printf("no\n");
else if(n==k)
{
    for(i=0;i<n;i++)
        if(a[i]!=a[i+1]) break;
    if(i<n-1) printf("no\n");
    else printf("yes\n");
}
//else if(maxx==0) printf("no\n");
else{
        if(maxx%k!=0) printf("no\n");
else{
        cnt2=maxx%k;
maxx/=k;
for(i=0;i<n;i++)
    for(j=0;j<n-1-i;j++)
    if(a[j]<a[j+1])
    {
        a[j]=a[j]+a[j+1];
        a[j+1]=a[j]-a[j+1];
        a[j]=a[j]-a[j+1];
    }

        if(a[0]>maxx)printf("no\n");//  for(i=0;i<n;i++
        else{                 //    printf("%d ",a[i]);
for(i=0;i<k;i++)
{
    sum=0;
    for(j=0;j<n;j++)
    {
    //if(a[j]==maxx && b[j]>0)
    //{b[j]=-1;sum=0;cnt1++;}
     if((a[j]+sum)<=maxx && !b[j] && a[j]>=0)
    {
        //pos=j;
        //b[j]=-1;
        sum+=a[j];
        //a[j]=-1-i;
    }
    if(sum==maxx){//sum=0;
    //printf("%d ",sum);
    sum=0;
            cnt1++;
        for(j=0;j<n && sum<=maxx;j++)
        {
        if((a[j]+sum)<=maxx &&!b[j] && a[j]>=0)
        {
            b[j]=1;
        //pos=j;
        //b[j]=-1;
        sum+=a[j];
        a[j]=-i-1;
        }
            }
            break;
    }
    }
   // for(i=0;i<n;i++)
     //   printf("%d ",b[i]);
   //if(sum!=0) {b[pos]=1;}
}
//for(i=0;i<n;i++)
//printf("%d ",a[i]);
for(i=0;i<n;i++)
{
    if(b[i]==1) cnt++;
}
//printf("cnt-%d  cnt1-%d  cnt2-%d",cnt,cnt1,cnt2);
if(cnt==n && cnt1==k && cnt2==0) printf("yes\n");
else printf("no\n");
}
}
}
}
}
