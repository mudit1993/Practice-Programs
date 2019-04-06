#include<stdio.h>
int main()
{
    int n,x,y,i,cnt=0,maxa=0,maxb=0,j=0,vala=0,valb=0;
    int a[100000],b[100000];
    scanf("%d%d%d",&n,&x,&y);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    while(j!=n)
   {
       vala=valb=maxa=maxb=0;
        for(i=0;i<n;i++)
    {
        if(a[i]>vala) {maxa=i;vala=a[i];}
        if(b[i]>valb) {maxb=i;valb=b[i];}
    }
    if(a[maxa]>b[maxa] && x>0)
    {   if(x>0)
        {cnt+=a[maxa];x--;}
        else if(y>0)
        {
            cnt+=b[maxa];y--;
        }
        a[maxa]=0;
        b[maxa]=0;

    }
    else if(a[maxa]<b[maxa])
    {
        if(y>0)
        {cnt+=b[maxa];y--;}
        else if(x>0){cnt+=a[maxa];x--;}
        a[maxa]=0;
        b[maxa]=0;

    }
    if(b[maxb]>a[maxb])
    {
        //printf("hi");
        if(y>0)
        {cnt+=b[maxb];y--;}
        else if(x>0){cnt+=a[maxb];x--;}
        a[maxb]=0;
        b[maxb]=0;

    }
    else if(b[maxb]<a[maxb])
    {
        if(x>0){
        cnt+=a[maxb];x--;}
        else if(y>0){
        cnt+=b[maxb];y--;}
        a[maxb]=0;
        b[maxb]=0;
    }
    j++;
    //printf("%d %d\n",x,y);
   }
 /* for(i=0;i<n;i++)
   {
     printf("%d,",b[i]);
   }*/
 for(i=0;i<n;i++)
    {
        if(a[i]==b[i] && (x>0||y>0) && a[i]>0 &&b[i]>0) cnt+=a[i];
    }




    printf("%d\n",cnt);
return 0;
}
