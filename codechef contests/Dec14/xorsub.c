#include<stdio.h>
#include<math.h>
void main()
{
    int n,k,i,j,t,pos,k1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int a[n],b[10];
        for(i=0;i<10;i++) b[i]=0;
        i=0;
        k1=k;
        while(k!=0)
            {
                b[i]=k%2;;
                k/=2;
                if(b[i]==1) pos=i;
                //printf("%d ",b[i]);
        i++;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        for(j=0;a[i]!=0;j++)
        {
            if(b[j]+(a[i]%2)==1)
                b[j]=1;
               // else b[j]=0;
                a[i]/=2;

        }
        }
        for(i=0;i<10;i++)
    {
        printf("%d ",b[i]);
        if(b[i]==1)
        k+=pow(2,i);
    }
    printf("%d\n",k);
    }

}
