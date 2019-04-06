#include<stdio.h>
long long int a[10000001],sum,m,f;
inline void func()
{
    int j;
    long long int ff;
    for(j=1;j<=f && a[j]!=0;j++)
    {
        ff=(j*(a[j]+f))%m;
       sum= (sum+ff)%m;
     //  printf("ff=%lld,sum=%lld\n",ff,sum);
    }
    if(a[j]==0 && j<f)
    {
        ff=(((((f)*(f+1))/2)%m) - ((((j)*(j+1))/2)%m))*f;
        sum=(sum+(ff%m))%m;
    }
    else if(a[j]==0 && j==f)
    {
        ff=(j*f)%m;
        sum=(sum+ff)%m;
    }
   //printf("\nsee u \n");

    /* for(j=1;j<=100000;j++)
    {
        ff=j*(a[j]+f);
        sum= (sum+(ff%m))%m;
    }*/
   /* for(j=36;j<=f;j++)
    {
        ff=(j*f)%m;
        sum=(sum+ff)%m;
    }*/
    /*if(f%2==0)
    {
        ff=(((((f/2)*(f+1))%m)-630)*f)%m;
        sum=(sum+ff)%m;
    }
    else
    {
        ff=(((f*((f+1)/2)%m)-630)*f)%m;
        sum=(sum+ff)%m;
    }*/

}
int main()
{
    long long int n,l,i;
    scanf("%lld%lld",&n,&m);

    a[0]=a[1]=1;
    sum=0;
    for(l=0;l<n;l++)
    {
        scanf("%lld",&f);
        f=f%m;
        if(f==0) {sum=(sum+(m-1))%m;continue;}
         for(i=2;i<=f && a[i-1]!=0;i++)
        {
        a[i]=(i*a[i-1])%m;
        }
       // for(i=0;i<=f;i++) printf("%lld=%lld\n",i,a[i]);
        func();
    }
    printf("%lld\n",sum);
return 0;
}
