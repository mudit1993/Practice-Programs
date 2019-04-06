#include<stdio.h>

long long int q,w[100000];
int ww[10001][10001];

int weightSum(unsigned int l,unsigned int r,unsigned int w1)
{
    int i,j;
    long long  int n=r-l+1;
    for (i=1; i<= w1; i++)
     {
       for (j=1; j<= n; j++)
       {
         ww[i][j] = ww[i][j-1];
         if (i >= w[l+j-1])
           ww[i][j] = ww[i][j] || ww[i - w[l+j-1]][j-1];
       }
     }
     return ww[w1][n];
}

int main()
{
    long long int i,tmp,n,op,l,r,w1;
    scanf("%lld%lld",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&w[i]);
    }
    //ww[0][0]=true;
    for(i=0;i<=10001;i++)
    {
        ww[i][0]=0;
        ww[0][i]=1;
    }
    ww[1][0]=0;
    while(q--)
    {
        scanf("%lld",&op);
        if(op==1)
        {
            scanf("%lld%lld",&l,&r);
            w[l]=r;
        }
        else if(op==2)
        {
            scanf("%lld%lld",&l,&r);
            while(l<r)
           {
               tmp=w[l];
               w[l]=w[r];
               w[r]=tmp;
               l++;r--;
           }
        }
        else {
            scanf("%lld%lld%lld",&l,&r,&w1);;
            if (weightSum(l,r,w1) == 1)
                printf("Yes\n");
            else
                printf("No\n");;
        }

           }

return 0;
}
