#include<stdio.h>
int main()
{
    int cc,n,b[51],i,j,cnt,cnt1,factor,c[15],td;
    scanf("%d",&c);
    while(cc--)
    {
         factor=cnt=cnt1=0;
        int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
             scanf("%d",&b[i]);
        }

        for(j=0;j<15;j++)
        {
            cnt=0;
            for(i=0;i<n;i++)
            {
                if(b[i]%a[j]==0 && b[i]>0)
                {
                    cnt++;
                    b[i]=0;
                }
            }
            if(cnt>0) cnt1++;
        }
        for(i=0;i<n;i++)
          if(b[i]>0) cnt1++;
        printf("%d\n",cnt1);
    }

return 0;
}
