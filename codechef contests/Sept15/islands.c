#include<stdio.h>
int main()
{
long long int i,n,t,x[100000],y[100000],minx,miny,maxx,maxy,cntup,cntdown,cntu,cntd;
scanf("%lld",&t);
while(t--){
scanf("%lld",&n);
scanf("%lld%lld",&x[0],&y[0]);
minx=maxx=maxy=miny=0;
for(i=1;i<n;i++)
{
    cntup=cntdown=cntu=cntd=0;
    scanf("%lld%lld",&x[i],&y[i]);
    if(x[minx]>x[i])
        minx=i;
    if(x[maxx]<x[i])
        maxx=i;
    if(y[miny]>y[i])
        miny=i;
    if(y[maxy]<y[i])
        maxy=i;
}
//printf("minx %lld miny %lld maxx %lld maxy %lld\n",x[minx],y[miny],x[maxx],y[maxy]);
if(x[minx]==x[maxx])
{
    printf("1\n%d SW\n",miny+1);
}
else{
        if(y[miny]==y[minx] && x[miny]<=x[minx])
            minx=miny;
        if(y[maxy]==y[maxx] && x[maxy]>=x[maxx])
            maxx=maxy;
        for(i=0;i<n;i++)
        {
        if(y[i]>y[minx])
            cntup++;
        else if(y[i]<y[minx])
            cntdown++;
        if(y[i]>y[maxx])
            cntu++;
        else if(y[i]<y[maxx])
            cntd++;
        }
     if(y[minx]==y[maxx])
     {
        if(cntup>0 && cntdown>0)
            printf("2\n%lld SE\n%lld NW\n",minx+1,maxx+1);
        else if (cntup==0)
            printf("1\n%lld SW\n",maxx+1);
        else if(cntdown==0)
            printf("1\n%lld NW\n",maxx+1);
        else
            printf("1\n%lld NW\n",maxx+1);
     }
    else if(y[minx]>y[maxx])
    {
        //if()
        printf("2\n%lld SE\n%lld NW\n",minx+1,maxx+1);
    }
    else if(y[minx]<y[maxx])
    {
        printf("2\n%lld NE\n%lld SW\n",minx+1,maxx+1);
    }
}
}
return 0;
}
