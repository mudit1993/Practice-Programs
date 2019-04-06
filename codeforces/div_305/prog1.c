#include<stdio.h>
#include<string.h>
int main()
{
char a[1000];
int k,len,i,endpt,j,no,k1,flag,i1,no1;
scanf("%s",a);
len=strlen(a);
scanf("%d",&k);
if((len%k)!=0)
    printf("NO\n");
else{
        no1=len/k;
        k1=k;
    for(i=0;i<len;)
    {
        no=len/k;
        flag=0;
        endpt=i+no;
        no/=2;
        i1=i;
        //printf("1)i1=%d ,endpt=%d, k1=%d\n",i1,endpt,k1);
        while(no--)
        {
            if(a[i1++]!=a[--endpt])
            {
               flag=1; break;
            }
            //printf("2)i1=%d ,endpt=%d, k1=%d\n",i1,endpt,k1);
        }
        if(flag==1)
        {
            printf("NO\n");
            exit(0);
        }
        else{
        k1--;
        i=i+no1;
        }
    }
    if(k1==0)
        printf("YES\n");
    else
        printf("NO\n");
}
return 0;
}
