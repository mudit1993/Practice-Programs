#include<stdio.h>
int a[100];

void merge(int low,int mid,int high)
{
int i=low,j=mid+1,k=low,q;
int b[high];
while(i<=mid && j<=high)
{
if(a[i]>a[j])
{
b[k]=a[i];
i++;
}
else {
b[k]=a[j];
j++;
}
k++;
}
if(i>mid)
{
for(;j<=high;)
{
b[k++]=a[j++];
}
}
else
for(;i<=mid;)
b[k++]=a[i++];
for(q=low;q<=high;q++)
{
a[q]=b[q];
}
}
void mergesort(int p,int r)
{
if(p<r)
{
int q=(p+r)/2;
mergesort(p,q);
mergesort(q+1,r);
merge(p,q,r);
}
}


int main()
{
    int t,n,g,i,max1,max2,flag,maxx,minn;
    scanf("%d",&t);
    while(t--)
    {
        flag=max1=max2=0;
           scanf("%d%d",&n,&g);
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
            mergesort(0,n-1);
           // max1=a[0];
            //for(i=0;i<n;i++)
           //printf("%d,",a[i]);
           // max1=a[0];
            //max2=a[1];
            //while(max1<g)
            i=0;
            while(i<n && max1<=g && max2<=g)
        {
            if(max1==0)
                max1=a[i++];
            if(max2==0 && i<n)
                max2=a[i++];
               // printf(" top=max1=%d,max2=%d,minn=%d\n",max1,max2,minn);
            //maxx=max1>=max2?max1:max2;
            if(max1>max2){ maxx=max1;minn=max2;}
            else {maxx=max2;minn=max1;}
           //printf("maxx=%d",maxx);
            if(maxx>g)
               {    flag=1;
                   break;}
            //minn=max1>=max2?max2:max1;
            g-=minn;
            max1-=minn;
            max2-=minn;
           // printf(" lastmax1=%d,max2=%d,minn=%d\n",max1,max2,minn);
        }
        if(flag==1)printf("NO\n");
        else printf("YES\n");

       // if(flag==1||(flag==0 && i<n-1)||(flag==1 && i<=n-1)){printf("NO\n");}
        //else if(flag==0 && i==n-1) printf("YES\n");
           }
return 0;
}
