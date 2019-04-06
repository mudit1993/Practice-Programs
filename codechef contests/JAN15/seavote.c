#include<stdio.h>
int main()
{
    int t,n,sum,i,x,n1;
    scanf("%d",&t);
    while(t--)
    {
        sum=n1=0;
        scanf("%d",&n);
           for(i=0;i<n;i++)
           {
                    scanf("%d",&x);
                    if(x>0) {n1++; sum+=x;}

           }
           if(100-sum>0) printf("NO\n");
           else{
            if(sum-100<n1) printf("YES\n");
            else printf("NO\n");
           }
    }

return 0;
}
