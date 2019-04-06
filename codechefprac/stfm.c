#include<stdio.h>
long long int a[10000001],sum,m,f,maxx;
int fact(int x){
int i;
if(x>maxx)
{
for(i=maxx+1;i<=x;i++)
    a[i]=(a[i-1]*i)%m;
maxx=x;
}
return a[x];
}
int main()
{
    long long int n,l,i,pos,temp;
    scanf("%lld%lld",&n,&m);
    a[0]=a[1]=1;
    sum=0;
    maxx=1;
    pos=2;
    for(l=0;l<n;l++)
    {
        scanf("%lld",&f);
        if(f<m){
            sum=(sum+(fact(f+1)-1))%m;
        }
        else{
             sum=(sum+(((m*fact(m-1))-1)%m))%m;
        }
            if(f%2){
                temp = (f+1)/2;
                temp= ((((f%m)*(f%m))%m)*(temp%m))%m;
            }
            else{
                temp = f/2;
                temp= ((((temp%m)*(f%m))%m)*((f+1)%m))%m;
            }
            sum=(sum+temp)%m;
    }
    printf("%lld\n",sum);
return 0;
}
