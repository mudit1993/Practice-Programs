#include<stdio.h>
#include<math.h>
int a[2][100000];
void merge(int low,int mid,int high,int pos,int pos1)
{
int i=low,j=mid+1,k=low,q;
int b[high],c[high];
while(i<=mid && j<=high)
{
if(a[pos][i]<a[pos][j])
{
b[k]=a[pos][i];
c[k]=a[pos1][i];
i++;
}
else {
b[k]=a[pos][j];
c[k]=a[pos1][j];
j++;
}
k++;
}
if(i>mid)
{
for(;j<=high;)
{
b[k]=a[pos][j];
c[k]=a[pos1][j];
k++;
j++;
}
}
else
for(;i<=mid;)
{
    b[k]=a[pos][i];
    c[k]=a[pos1][i];
    i++;k++;
}
for(q=low;q<=high;q++)
{
a[pos][q]=b[q];
a[pos1][q]=c[q];
}
}
void mergesort(int p,int r,int pos,int pos1)
{
if(p<r)
{
int q=(p+r)/2;
mergesort(p,q,pos,pos1);
mergesort(q+1,r,pos,pos1);
merge(p,q,r,pos,pos1);
}
}


int main()
{
int t,n,i,j,m,x,y,maxx,cnt;
scanf("%d",&t);
while(t--)
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        maxx=0;
        for(j=0;j<m;j++)
        {
            scanf("%d%d",&x,&y);
            if(maxx<abs(x))
                maxx=abs(x);
        }
        a[0][i]=i;
        a[1][i]=maxx;
    }
/*      for(i=0;i<n;i++)
    {
   printf("%d,%d",a[0][i],a[1][i]);
    }
    printf("before sort1\n");
  */
    mergesort(0,n-1,1,0);
  /*  printf("after sort1\n");
     for(i=0;i<n;i++)
    {
     printf("%d,%d",a[0][i],a[1][i]);
    }
    */
    for(i=0;i<n;i++)
    {
        a[1][i]=i;
    }
   /* printf("After assignment\n");
    for(i=0;i<n;i++)
    {
     printf("%d,%d",a[0][i],a[1][i]);
    }
    */
    mergesort(0,n-1,0,1);
   /*printf("After sort2\n");
    for(i=0;i<n;i++)
    {
     printf("%d,%d",a[0][i],a[1][i]);
    }
    */for(i=0;i<n;i++)
    {
        printf("%d ",a[1][i]);
    }
    printf("\n");
}
return 0;
}
