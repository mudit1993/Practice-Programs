#include<stdio.h>
int main()
{
int n,i,j,q,r1,c1,r2,c2,c,i1,j1,ct=0;
scanf("%d",&n);
int a[n][n];
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
scanf("%d",&q);
while(q!=0)
{
    ct=c=0;
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
for(i1=r1-1;i1<r2;i1++)
{
    for(j1=c1-1;j1<c2;j1++)
    {
        for(i=i1;i<r2;i++)
        {
            for(j=j1;j<c2;j++)
            {
                if(a[i1][j1]==a[i][j])
                    c++;
            }

        }
        if(c==1)
        ct++;
        c=0;
    }
}
printf("%d\n",ct);
ct=0;
q--;
}


}
