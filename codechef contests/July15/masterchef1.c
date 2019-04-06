#include<stdio.h>
long long int arr[100000],arr2[100000],l[201],r[201],c[201];
int main()
{
int t;
long long int n,k,m,i,sum,l1,r1,c1,maxx,minn,j;
scanf("%d",&t);
while(t--)
{
    sum=0;minn=maxx=0;
    for(i=0;i<201;i++) {l[i]=201;r[i]=0;c[i]=0;}
    scanf("%lld%lld%lld",&n,&k,&m);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i]<0)
        {
            arr2[i]=arr[i];
        }
        else arr2[i]=0;
        sum+=arr[i];
    }
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&l1,&r1,&c1);
        if(l[c1]>l1)
        {l[c1]=l1;
        }
        if(r[c1]<r1){
        r[c1]=r1;}
    }
    for(i=0;i<200;i++)
    {
        if(l1[i]>0)
        {
            for(j=l[i];j<=r[i];j++)
            {
                if(arr1[j])
                {

                }
            }
        }

    }

}
return 0;
}
