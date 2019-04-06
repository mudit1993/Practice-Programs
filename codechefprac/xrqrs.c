#include<stdio.h>
int b[500001];
void heapify(int i,int f)
{
    int lar,r,l;
    l=2*i;
    r=l+1;
    lar=i;
    if(l<=f&&b[l]<b[lar])
        lar=l;
    if(r<=f&&b[r]<b[lar])
        lar=r;
    if(lar==i)
        return;
    else
    {
        r=b[lar];
        b[lar]=b[i];
        b[i]=r;
        heapify(lar,f);
    }
}
void maxheapify(int i,int f)
{
    int lar,r,l;
    l=2*i;
    r=l+1;
    lar=i;
    if(l<=f&&b[l]>b[lar])
        lar=l;
    if(r<=f&&b[r]>b[lar])
        lar=r;
    if(lar==i)
        return;
    else
    {
        r=b[lar];
        b[lar]=b[i];
        b[i]=r;
        heapify(lar,f);
    }
}
/*int delete(int f)
{
    int t;
    t=b[1];
    b[1]=b[f];
    f--;
    //heapify(1,f);
    return(t);
}*/
int main()
{
    int m,a[500001],n=1,type,x,l,r,i,minn,cnt=0,n1,minn1;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&type);
        if(type==0)
        {
            scanf("%d",&x);
            a[n++]=x;

        }
        else if(type==1)
        {
            scanf("%d%d%d",&l,&r,&x);
            minn=a[l];
            for(i=l+1;i<=r;i++)
            {
                if((minn^x)<(a[i]^x))
                minn=a[i];
            }
            printf("%d\n",minn);
            continue;
        }
        else if(type==2)
        {
            scanf("%d",&x);
            n-=x;
            continue;
        }
        else if(type==3)
        {
            scanf("%d%d%d",&l,&r,&x);
            cnt=0;
            for(i=l;i<=r;i++)
            {
                if(a[i]<=x)cnt++;
            }
            printf("%d\n",cnt);
            continue;
        }
        else if(type==4)
        {
            n1=1;
            scanf("%d%d%d",&l,&r,&x);
            for(i=l;i<=r;i++)
            {
                b[n1++]=a[i];
            }
          //  printf("%d\n",n1);
            n1--;
         // if(x<=(r-l+1)/2)
          //{//x-=1;

                    for(i=n1/2;i>0;i--)
                heapify(i,n1);
             //   for(i=1;i<=n1;i++)
           //  printf("%d,",b[i]);
            //  minn=delete(1);
            while(x--)
                {
                minn1=b[1];
                b[1]=b[n1];
                n1--;
                heapify(1,n1);
            //for(i=1;i<n1;i++)
             //printf("%d,",b[i]);
             // printf("\n");
            //}
            //minheapify(1,n1);
        }
        /*else
        {  x=r-l-x+2;

            for(i=n1/2;i>0;i--)
               maxheapify(i,n1);
             //  for(i=1;i<=n1;i++)
           // printf("%d,",b[i]);
             while(x--)
                {
                minn1=b[1];
                b[1]=b[n1];
                n1--;
                maxheapify(1,n1);
           // for(i=1;i<n1;i++)
           // printf("%d,",b[i]);
           // printf("\n");
            }
            //maxheapify(1,n1);
            }*/
            printf("%d\n",minn1);
        }
    }
return 0;
}
