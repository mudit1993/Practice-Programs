#include<stdio.h>
int a[101];

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
    int t,n,i,max1,max2,flag,maxx,minn;
    long g;
    scanf("%d",&t);
    while(t--)
    {
        flag=max1=max2=0;
           scanf("%d%ld",&n,&g);
             for(i=0;i<n;i++)
                scanf("%d",&a[i]);
                if(g==0) {printf("NO\n");continue;}
            mergesort(0,n-1);
           // max1=a[0];
            //for(i=0;i<n;i++)
           //printf("%d,",a[i]);
           // max1=a[0];
            //max2=a[1];
            //while(max1<g)
            i=0;
            while(i<n && max1<=g && max2<=g && g!=0)
        {
            if(max1==0)
                max1=a[i++];
            if(max2==0 && i<n)
                max2=a[i++];

            if(max1>max2){ maxx=max1;minn=max2;}
            else {maxx=max2;minn=max1;}
            if(maxx>g || g<=0)
               {    flag=1;
                   break;}
            g-=minn;
            max1-=minn;
            max2-=minn;
        }
        if(flag==1 )printf("NO\n");
        else printf("YES\n");

           }
return 0;
}
