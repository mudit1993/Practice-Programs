#include<stdio.h>
typedef long long int ll;
ll a[20001];
void merge(ll low,ll mid,ll high)
{
ll i=low,j=mid+1,k=low,q;
ll b[high];
while(i<=mid && j<=high)
{
if(a[i]<a[j])
{
b[k]=a[i];
i++;
}
else {
b[k]=a[j];
j++;
}
k++;
}
if(i>mid)
{
for(;j<=high;)
{
b[k++]=a[j++];
}
}
else
for(;i<=mid;)
b[k++]=a[i++];
for(q=low;q<=high;q++)
{
a[q]=b[q];
}
}
void mergesort(ll p,ll r)
{
if(p<r)
{
ll q=(p+r)/2;
mergesort(p,q);
mergesort(q+1,r);
merge(p,q,r);
}
}

int main()
{
    ll t,n,m,i,chains;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        for(i=0;i<m;i++)
            scanf("%lld",&a[i]);
        mergesort(0,m-1);
        chains=0;
        m--;
        for(i=0;m>0;i++)
        {
            if(a[i]>=m)
            {
                chains+=m;
                break;
            }
            else if(a[i]<m)
            {
                chains+=a[i];
                m-=(a[i]+1);
            }
        }
        printf("%lld\n",chains);
    }
    return 0;
}
