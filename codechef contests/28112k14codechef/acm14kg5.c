#include<stdio.h>
int main()
{
    int t,n,i,k,n1,tot=0,j;
    int cnt,flg;
    scanf("%d",&t);
    int t1=t;
    int arr[t];
    while(t!=0)
    {
        cnt=0;flg=0;tot=0;
        scanf("%d%d",&n,&k);
        n1=n;
        if(n>1){
        for(i=2;i<=k/2;i++)
        {
            for(j=i;j<=k/2;j++)
            {
               if(i*j <=k)
                    cnt++;
               else{ flg=1;break;}
            }

        }
        }

        if(k>1){
       while(n1!=1)
        {
            tot+=cnt;
            cnt++;
            n1--;
        }}
       arr[t]=(tot+k)%1000000007;
     t--;
    }
for(i=t1;i>0;i--)
    printf("%d\n",arr[i]);
    return 0;
}
