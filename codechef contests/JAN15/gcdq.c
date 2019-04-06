#include<stdio.h>
int main()
{
int t,n,q,a[100002],i,l,j,r,minn,flag;
scanf("%d",&t);
while(t--)
{
    flag=0;
scanf("%d%d",&n,&q);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
while(q--)
{
    flag=0;
    minn=100001;
    scanf("%d%d",&l,&r);
    for(i=1;i<=n;i++)
    {
        if(i==l) {i+=(r-l);continue;}
        else
        {
            if(a[i]<minn)
            minn=a[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i==l) {i+=(r-l);continue;}
        else
        {
            if(a[i]%minn!=0) {flag=1;break;}
        }
    }
   // printf("minn-%d",minn);
    if(flag==1){
            for(j=minn/2;j>=2;j-=2)
            {
                flag=0;
                for(i=1;i<=n;i++)
                {
                    if(i==l) {i+=(r-l);continue;}
                    else
                    {
                    if(a[i]%j!=0) {flag=1;break;}
                    }
                }
                if(flag==0){printf("%d\n",j); break;}
            }

    }
    else printf("%d\n",minn);
    if(flag==1) printf("1\n");
//printf("%d\n",minn);
}
}
return 0;
}
