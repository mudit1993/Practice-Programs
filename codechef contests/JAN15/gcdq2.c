#include<stdio.h>
#include<time.h>
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
{clock_t tt;
    tt = clock();
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
         if(i>=l && i<=r) {i=r;continue;}
        else
        {
            if(a[i]<minn)
            minn=a[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        if(i>=l && i<=r) {i=r;continue;}
        else
        {
            if(a[i]%minn!=0) {flag=1;break;}
        }
    }
   // printf("minn-%d",minn);
    if(flag==1){
            j=minn/2;
         for(i=1;i<=n;i++)
                {
                    if(i>=l && i<=r) {i=r;continue;}
                    else
                    {
                        if(minn==a[i]) continue;
                        else{
                        for(;j>=2 && i<=n;j--)
                        {
                           if(minn%j==0 && a[i]%j==0) {break;}

                        }

                        }
                    }
                }
        printf("%d\n",j);

    }
    else printf("%d\n",minn);
   // if(flag==1) printf("1\n");
//printf("%d\n",minn);
}
}
 tt = clock() - tt;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("fun() took %f seconds to execute \n", time_taken);
return 0;
}
