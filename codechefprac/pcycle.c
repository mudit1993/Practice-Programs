#include<stdio.h>
int main()
{
    int n,i,j,a[1001],b[1001],pos,cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
      {
            scanf("%d",&a[i]);
            b[i]=0;

            }
            for(i=1;i<=n;i++)
        {
       // printf("hyea");
       if(b[i]!=0) continue;
        j=pos=i;
        cnt++;
        while(a[j]!=pos)
        {
          //  printf("%d ",a[j]);
            j=a[j];
            b[j]=1;
        }
        //printf("%d\n",pos);
    }
    printf("%d\n",cnt);
    for(i=1;i<=n;i++) b[i]=0;
    for(i=1;i<=n;i++)
    {
       // printf("hyea");
       if(b[i]!=0) continue;
        j=pos=i;
        printf("%d ",pos);
        while(a[j]!=pos)
        {
            printf("%d ",a[j]);
            j=a[j];
            b[j]=1;
        }
        printf("%d\n",pos);
    }
return 0;
}
