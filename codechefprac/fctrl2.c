#include<stdio.h>
int main()
{
    int n,test,i,j,cnt,pro,carry,k;
    int a[200];
    scanf("%d",&test);
    while(test)
    {
        cnt=0;
        for(i=1;i<=200;i++) a[i]=0;
        a[0]=1;
        scanf("%d",&n);
        cnt=1;
        for(i=2;i<=n;i++)
        {
            j=0;
            carry=0;
           // pro=0;
           while(a[j]==0) j++;
              //  pro=a[j]*i;
                while(j<cnt)
                {
                       // a[cnt]+=pro;
                        pro=a[j]*i;
                        a[j]=(pro+carry)%10;
                        //pro/=10;
                        carry=(pro+carry)/10;
                        j++;
                        //a[j]=(a[j]*i)+(pro);
                        //carry=
                }
                while(carry!=0)
                {
                    a[cnt++]=carry%10;
                    carry/=10;
                }
                //for(k=cnt-1;k>=0;k--)
               // printf("%d",a[k]);
                //printf("\n");
                }
                for(k=cnt-1;k>=0;k--)
                printf("%d",a[k]);
                printf("\n");
                test--;
    }
return (0);
}
