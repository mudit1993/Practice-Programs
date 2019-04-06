#include<stdio.h>
int main()
{
long cnt,t,k,n,sw,cnt1,j=0,m,i;
scanf("%d",&t);
long c[t];
while(j!=t)
{cnt=0;
scanf("%d%d",&n,&k);
long b[n+1];
for(i=0;i<n;i++)
scanf("%d",&b[i]);
while(k!=0)
{cnt1=0;
    for(i=0;i<n-1;i++)
    {
        if(b[i]<b[i+1]) continue;
       if(b[i]>b[i+1])
       {
           cnt1++;//check ascending
            sw=b[i];
            b[i]=b[i+1];
            b[i+1]=sw;
            k--;
        }
        if(k==0) break;
        else continue;
    }
    if(cnt1==0 && k!=0)
    {
        if(k%2==0) goto x;
        else {
            sw=b[0];
            b[0]=b[1];
            b[1]=sw;
            goto x;
        }
    }
}
x: for(m=0;m<n;m++)
{
    if(b[m]<b[m+1])
        //continue;
   //else { for(i=m;i<n;i++)
    //if(b[m]>b[i])
        cnt++;//}
}
printf("Case %d: %d\n",j+1,cnt);
j++;
}
return 0;
}
