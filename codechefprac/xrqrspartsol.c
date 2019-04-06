#include<stdio.h>
void heapify(int a[],int i,int f)
{
    int l,r,lar;
    l=2*i;
    r=l+1;
    lar=i;
    if(l<=f&&a[l]<a[lar])
        lar=l;
    if(r<=f&&a[r]<a[lar])
        lar=r;
    if(lar==i)
        return;
    else
    {
        r=a[lar];
        a[lar]=a[i];
        a[i]=r;
        heapify(a,lar,f);
    }
}
int delete(int a[],int f)
{
    int t;
    t=a[1];
    a[1]=a[f];
    f--;
    heapify(a,1,f);
    return(t);
}
int main()
{
    int m,l,r,x,k,i,j,a[100010],b[100010],q,top,ans,f;
    scanf("%d",&m);
    top=0;
    while(m--)
    {
        scanf("%d",&q);
        switch(q)
        {
            case 0:scanf("%d",&x);
                    a[top++]=x;
                    break;
            case 1:scanf("%d%d%d",&l,&r,&x);
                    j=x^a[l-1];
                    ans=a[l-1];
                    for(i=l;i<r;i++)
                    {
                        if((x^a[i])>j)
                        {
                            j=x^a[i];
                            ans=a[i];
                        }
                    }
                    printf("%d\n",ans);
                    break;
            case 2:scanf("%d",&k);
                    top-=k;
                    break;
            case 3:scanf("%d%d%d",&l,&r,&x);
                    ans=0;
                    for(i=l-1;i<r;i++)
                    {
                        if(a[i]<=x)
                            ans++;
                    }
                    printf("%d\n",ans);
                    break;
            case 4:scanf("%d%d%d",&l,&r,&k);
                    f=1;
                    for(i=l-1;i<r;i++)
                    {
                        b[f++]=a[i];
                    }
                    f--;
                    for(i=f/2;i>0;i--)
                    {
                        heapify(b,i,f);
                    }
                    for(i=1;i<=f;i++) printf("%d,",b[i]);
                    for(i=1;i<k;i++)
                    {
                        delete(b,f);
                        f--;
                    }
                    printf("%d\n",delete(b,f));
                    break;
        }
    }
    return(0);
}
