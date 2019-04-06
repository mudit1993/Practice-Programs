#include<stdio.h>
int main()
{
    int n,x,y,i,cnt=0,maxa=0,maxb=0,j=0,pos,vala=0;
    int a[100000],b[100000];
    scanf("%d%d%d",&n,&x,&y);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    if(x<y)
    {
        j=0;
        while(x!=0&&j!=n)
        {vala=0;
            for(i=0;i<n;i++)
        {
        if(a[i]>vala) {maxb=i;vala=a[i];printf("%d,",cnt);}
        }
        if(a[maxb]>b[maxb]) {cnt+=a[maxb];x--;a[maxb]=b[maxb]=0;}
       // else cnt+=b[maxb];
        j++;
        }
        for(i=0;i<n;i++)
        {
            if(b[i]>0)cnt+=b[i];printf("%d,",cnt);
        }
   }
 else
        {
        j=0;
        while(y!=0&&j!=n)
        {vala=0;
            for(i=0;i<n;i++)
        {
        if(b[i]>vala) {maxb=i;vala=b[i];}
        }
        if(a[maxb]<b[maxb]) {cnt+=b[maxb];y--;a[maxb]=b[maxb]=0;printf("%d,",cnt);}
        //else cnt+=b[maxb];
        j++;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]>0)cnt+=a[i];printf("%d,",cnt);
        }
   }
    printf("%d\n",cnt);
return 0;
}
