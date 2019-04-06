#include<stdio.h>
#include<math.h>
/*int value(int a,int b)
{
    int i=0;
    int sum=0;
    while(a!=0 || b!=0)
    {
        if(a==b){sum=a;break;}
        if((a%2)+(b%2)==1)
        {
            sum+=pow(2,i);//(a%2)+(b%2);
        }
            a/=2;b/=2;
            i++;
        }

        return sum;
}*/
void main()
{
    int n,k,i,j,t,maxx,b[2048];
    scanf("%d",&t);
    for(i=0;i<2048;i++) b[i]=0;
   // printf("%d  ",value(1,2));
    while(t)
    {maxx=0;
        scanf("%d%d",&n,&k);
        int a[n];//,b[2048];
       // for(i=0;i<2048;i++) b[i]=0;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            { //printf("%d  ",value(a[i],a[j]));

                b[a[i]^a[j]]=t;
              //  printf("%d  ",value(a[i],b[j]));
            }
        }
       /* for(i=0;i<2048;i++)
        {
            for(j=0;j<n;j++)
            { //printf("%d  ",value(a[i],a[j]));
                //if(b[j]==t && b[i]==t)
                if(b[i]==t)
                b[value(i,a[j])]=t;
              //  printf("%d  ",value(a[i],b[j]));
            }
        }*/
        for(i=0;i<2048;i++)
        {
           // printf(" %d ",b[i]);
            if(value(k,i)>maxx && b[i]==t)
            {
                maxx=value(k,i);
                //printf("\n%d  ",value(k,i));
            }
        }
        t--;
        printf("%d\n",maxx);
        }

}


