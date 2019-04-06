#include<stdio.h>
/*void heapify(int *a,int i,int size)
{
int l=2*i,r=(2*i)+1;
int large=i;int s;

if(a[l]>a[large] && l<=size)
large=l;
if(a[r]>a[large] && r<=size)
large=r;
if(large==i)
{
return;
}
else{
a[large]=a[large]+a[i];
a[i]=a[large]-a[i];
a[large]=a[large]-a[i];
heapify(a,large,size);
}
}*/
int main()
{
int i,t,n,j=0,sum,k,no;
scanf("%d",&t);
int c[t];
while(j!=t)
{sum=0;
scanf("%d",&n);
int b[n];
for(i=0;i<n;i++)
scanf("%d",&b[i]);
for(i=0;i<3;i++)
{
    no=i;
    for(k=i;k<n;k++)
    {
    if(b[k]>b[no])
     {no=k;
     }

    }
    if(no!=i)
    {b[i]=b[i]+b[no];
        b[no]=b[i]-b[no];
        b[i]=b[i]-b[no];}
sum+=b[i];
}
printf("Case %d: %d\n",j+1,sum);
//c[j]=sum;
j++;
}
//for(j=0;j<t;j++)
  //  printf("Case %d: %d\n",j+1,c[j]);
return 0;
}
