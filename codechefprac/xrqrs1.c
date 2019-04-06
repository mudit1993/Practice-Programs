#include<stdio.h>
int b[500001];
int main()
{
    int m,a[500001],n=1,type,x,l,r,i,minn,cnt=0,n1,minn1,j;
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

          if(x<=(r-l+1)/2)
          {//x-=1;

        for(i=1;i<n1;i++)
             printf("%d,",b[i]);
                minn1=b[1];
                b[1]=b[n1-1];
                n1--;

            //for(i=1;i<n1;i++)
             //printf("%d,",b[i]);
              printf("\n");
            }
            //minheapify(1,n1);
        else
        {  x=r-l-x+2;
             while(x--)
                {
               heapify(1,n1);
                minn1=b[1];
                b[1]=b[n1-1];
                n1--;

            for(i=1;i<n1;i++)
            printf("%d,",b[i]);
            printf("\n");
            }
            //maxheapify(1,n1);
            }
            printf("%d\n",minn1);
        }
    }
return 0;
}
