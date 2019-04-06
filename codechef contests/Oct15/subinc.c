#include<stdio.h>
int main()
{
long long int t,i,n;
long long int no,prev,sum,cnt;
scanf("%lld",&t);
while(t--)
{
    sum=0;
    scanf("%lld%lld",&n,&prev);
    cnt=1;
    for(i=1;i<n;i++)
    {
        scanf("%lld",&no);
        if(prev<=no)
            cnt++;
        else{
            if(cnt==1)
                sum++;
            else
                sum+=cnt+1;
           cnt=1;
        }
        prev=no;
    }
        if(cnt==1)
                sum++;
            else
                sum+=cnt+1;
    printf("%lld\n",sum);
}
return 0;
}
