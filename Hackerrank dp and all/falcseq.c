#include<stdio.h>
long long int a[3002][3002];
int main()
{
int n,i,j;
long long int no,maxx=-1000001,sum=0,prod,prod2;
scanf("%d",&n);
for(i=0;i<n;i++)
   {
       scanf("%lld",&no);
       a[0][i+1]=no;
       a[1][i+1]= 0;
       a[i+1][0]=no;
   }
 /*  for(i=0;i<3001;i++)
   {
       for(j=0;j<3001;j++)
       {
           a[i][j]=-1000001;
       }
   }*/
for(i=2;i<n;i++)
{
    for(j=2;j<=i;j++)
    {
        prod=(a[0][i] * a[j][0])
        prod2 =prod + a[j-1][i+1];
        if(prod>prod2)
            a[i][j]=prod;
        else
            a[i][j]=prod2;
    }

}

return 0;
}
