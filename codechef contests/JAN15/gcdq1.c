#include<stdio.h>
int scan(int *no)
{
        int n=0;
        register int ch=getchar();
        for(;ch>47&&ch<58;ch=getchar())
        {
                n=(n<<1)+(n<<3)+ch-48;
        }
        *no=n;
}

int main()
{
int t,n,q,a[100002],i,l,j,r,minn,flag;
scan(&t);
while(t--)
{
    flag=0;
scan(&n);
scan(&q);
for(i=1;i<=n;i++)
    scan(&a[i]);
while(q--)
{
    flag=0;
    minn=100001;
    scan(&l);
    scan(&r);
    for(i=1;i<=n;i++)
    {
        if(i==l) {i=r;continue;}
        else
        {
            if(a[i]<minn)
            minn=a[i];
        }
    }
   // printf("%d",minn);
    for(i=1;i<=n;i++)
    {
        if(i==l) {i=r;continue;}
        else
        {
            if(a[i]%minn!=0) {flag=1;break;}
        }
    }
   // printf("minn-%d",minn);
    if(flag==1){
            for(j=minn/2;j>=2;j--)
            {
                flag=0;
                for(i=1;i<=n;i++)
                {
                    if(i==l) {i=r;continue;}
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
