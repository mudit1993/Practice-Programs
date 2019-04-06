#include<stdio.h>
int main()
{
long long int i,n,t,x[100000],y[100000],minx,miny,maxx,maxy,cntup,cntdown,cntu,cntd;
scanf("%lld",&t);
while(t--){
scanf("%lld",&n);
scanf("%lld%lld",&x[0],&y[0]);
minx=maxx=maxy=miny=0;
if(n==1) {printf("1\n1 NE\n");continue;}
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
if(x[minx]==x[maxx])
{
    printf("1\n%d SW\n",maxy+1);
}
else{

        for(i=0;i<n;i++)
        {
            if((y[miny]==y[i] && x[minx]==x[i])||(y[maxy]==y[i] && x[minx]==x[i]))
                minx=i;
            if((y[maxy]==y[i] && x[maxx]==x[i])||(y[miny]==y[i] && x[maxx]==x[i]))
                maxx=i;
        }
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
    else{
        if(cntup>=cntu && cntdown<=cntd)
        {
            if(cntdown==0)
                printf("1\n%lld NE\n",minx+1);
            else if(cntu==0)
                printf("1\n%lld SW\n",maxx+1);
            else
            printf("2\n%lld NE\n%lld SW\n",minx+1,maxx+1);
        }
        else if(cntup<cntu && cntdown >= cntd)
        {
            if(cntup==0)
              printf("1\n%lld SE\n",minx+1);
            else if(cntd==0)
                printf("1\n%lld NW\n",maxx+1);
            else
              printf("2\n%lld SE\n%lld NW\n",minx+1,maxx+1);
        }
    }
}
}
return 0;
}
