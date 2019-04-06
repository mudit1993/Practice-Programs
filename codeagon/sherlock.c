#include<stdio.h>
long long int a[100000],c[100000];

void merge(int low,int mid,int high)
{
int i=low,j=mid+1,k=low,q;
int b[high];
while(i<=mid && j<=high)
{
if(a[i]>a[j])
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
void mergesort(int p,int r)
{
if(p<r)
{
int q=(p+r)/2;
mergesort(p,q);
mergesort(q+1,r);
merge(p,q,r);
}
}

int main()
{
long long int n,m,i,l,r,flag=-1,j,cnt=0,pos;
scanf("%lld%lld",&n,&m);
for(i=0;i<n;i++)
{
    scanf("%lld",&c[i]);
    a[i]=c[i];
}
mergesort(0,n-1);
while(m--)
{
scanf("%lld%lld",&l,&r);
flag=-1;
cnt=0;
l--;r--;
for(i=0;i<n;i++)
{
    for(j=l;j<=r;j++)
    {
        if(c[j]==a[i])
            {flag=i;pos=j;break;}
    }
if(flag==i)
    break;
}
for(j=pos;j<=r;j++)
{
    if(a[flag]==c[j])
        cnt++;
}
printf("%lld\n",cnt);
}
return 0;
}
