#include<stdio.h>
long long int a[100001],sum,m,f;
inline void func()
{
    int j;
    long long int ff;
if(f<=35)
    {for(j=1;j<=f;j++)
    {
        ff=(j*(a[j]+f))%m;
       sum= (sum+ff)%m;
     //  printf("ff=%lld,sum=%lld\n",ff,sum);
    }
   // printf("\nsee u \n");
    }
    else{
     for(j=1;j<=100000;j++)
    {
        ff=j*(a[j]+f);
        sum= (sum+(ff%m))%m;
    }
   /* for(j=36;j<=f;j++)
    {
        ff=(j*f)%m;
        sum=(sum+ff)%m;
    }*/
    if(f%2==0)
    {
        ff=(((((f/2)*(f+1))%m)-630)*f)%m;
        sum=(sum+ff)%m;
    }
    else
    {
        ff=(((f*((f+1)/2)%m)-630)*f)%m;
        sum=(sum+ff)%m;
    }
    }
}
int main()
{
    long long int n,i;
    scanf("%lld%lld",&n,&m);

    a[0]=a[1]=1;
    for(i=2;i<=10000000 && a[i-1]!=0;i++)
    {
        a[i]=(i*a[i-1])%m;
    }
    //for(i=0;i<=500;i++) printf("%lld=%lld\n",i,a[i]);
    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&f);
        f=f%m;
        func();
    }
    printf("%lld\n",sum);
return 0;
}
