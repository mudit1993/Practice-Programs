#include<stdio.h>
#include<math.h>
void main()
{
    int n,x,i,k=0,j,sum=0,cnt=0,cnt1=0,cnt2=0,cnt3=0;
    scanf("%d",&n);
    long a[n];
    for(i=0;i<n;i++)
    scanf("%ld",&a[i]);
    for(i=0;i<pow(2,n);i++)
    {
        sum=0;cnt=0;
        for(j=0;j<n;j++)
        {
            if((i&1<<j))
            {
                printf("%d ",a[j]);
                sum+=a[j];
                cnt++;
            }
        }
        printf("\n");
            if(sum==0 && cnt%2==0)
            {cnt/=2;
            cnt3=cnt;sum=0;
            printf("cnt-%d\n",cnt);
            int pos=-1;cnt1=0;
              while(cnt--)
                {sum=0;
             for(k=pos+1;k<n;k++)
            {
                if(i&1<<k &&(a[k]<0)&& sum==0)
               {
                   pos=k;
                      sum=a[k];
                      printf("%d ",a[k]);
               }
                else if(i&1<<k && a[k]==-(sum) && a[k]>0)
                {
                    sum+=a[k];cnt1++;
                     printf("%d\n",a[k]);
                    break;
                }

            }
            }
            if(cnt1==cnt3) cnt2++;
            }
            printf("cnt11--%d\n",cnt2);
    }
    printf("%d\n",(cnt2)%1000000007);
}

