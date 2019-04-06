#include<stdio.h>
#include<math.h>
int main()
{
int n,l,r,x,i,j,maxx,minn;
int a[16];
long int sum=0,cnt=0;
scanf("%d%d%d%d",&n,&l,&r,&x);
for(i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
for(i=0;i<pow(2,n);i++)
    {
        maxx=0,minn=1000001;
        sum=0;

        for(j=0;j<n;j++)
        {
            if((i&1<<j))
            {
                sum+=a[j];
                if(maxx<a[j]){
                    maxx=a[j];
                }
                if(minn>a[j]){
                    minn=a[j];
                }
                //printf("%d ",a[j]);
            }

        }
        if(sum>=l && sum<=r){
            if((maxx-minn)>=x)
            {
                cnt++;
            }
        }

    }

printf("%d\n",cnt);

return 0;
}
