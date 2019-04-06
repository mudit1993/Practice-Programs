#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[300][300];
void rotation(int m,int n,int pos)
{
int i;
int temp = a[pos][pos];
for(i=pos;i<pos+n-1;i++)
    a[pos][i]=a[pos][i+1];
for(i=pos;i<pos+m-1;i++)
    a[i][pos+n-1]=a[i+1][pos+n-1];
for(i=pos+n-1;i>=pos;i--)
    a[pos+m-1][i]=a[pos+m-1][i-1];
for(i=pos+m-1;i>=pos+1;i--)
    a[i][pos]=a[i-1][pos];
a[pos+1][pos]=temp;
}

int main() {

    int i,j,m,n,r,cycle,m1,n1,k=-1;
    scanf("%d%d%d",&m,&n,&r);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
            m1=m;
            n1=n;

    while(m1>0 && n1>0)
    {
    cycle=2*(m1+n1)-4;
    cycle=r%cycle;
    k++;
    for(i=0;i<cycle;i++)
    rotation(m1,n1,k);
    m1-=2;
    n1-=2;
    }
    for(i=0;i<m;i++)
        {for(j=0;j<n;j++)
            {printf("%d ",a[i][j]);}
            printf("\n");
        }
    return 0;
}
