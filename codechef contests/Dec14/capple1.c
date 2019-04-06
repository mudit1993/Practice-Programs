#include<stdio.h>
int temp,cnt;
/*void heapify(int i,int size)
{
int l=2*i,r=(2*i)+1;
int large=i;int s;

if(a[l]<a[large] && l<=size)
large=l;
if(a[r]<a[large] && r<=size)
large=r;
if(large==i)
{
return;
}
else{
a[large]=a[large]+a[i];
a[i]=a[large]-a[i];
a[large]=a[large]-a[i];
heapify(large,size);
}
}
void build_heap(int size)
{
int i;
for(i=(size/2);i>=1;i--)
heapify(i,size);
//return a[1];
}

/*void heapsort(int a[],int size)
{
    int temp;
    while(size)
    {
        build_heap(a,size);
        temp=a[1];
        a[1]=a[size];
        a[size]=temp;
        size--;
    }
}*/
/*void deletemin(int size)
{

while(size){build_heap(size);
if(a[1]-temp>0 && size!=0) {
        cnt++;
       }
      // printf("%d ",a[1]);
        temp=a[1];
        a[1]=a[size];
 size--;

}
}*/
void main()
{
int i,k,j,flag;
int n,t;
scanf("%d",&t);
while(t--)
{int b[100000];
//for(i=0;i<100000;i++)
  //  b[i]=0;
    cnt=0;k=0;
temp=0;flag=0;
  scanf("%d",&n);
 int a[n];
// b[0]=0;
for(i=0;i<n;i++)
{//flag=0;
    scanf("%d",&a[i]);
    if(b[a[i]]!=t)
    {b[a[i]]=t;k++;}
//for(j=0;j<k;j++)
    //{
      // if(b[j]==a[i])
        //    flag=1;
     //}
     //if(flag==0)
    // {
     //b[k]=a[i];
       // k++;
    // }
}
//heapsort(a,n);
/*for(i=1;i<=n;i++)
{
    if(a[i]<a[i+1]) cnt++;
}
if(cnt==0) cnt=1;*/
    //deletemin(n);
printf("%d\n",k);
}
}
