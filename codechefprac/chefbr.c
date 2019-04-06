#include<stdio.h>
#include<math.h>
int main()
{
int n,a[100],i,j,k=0,b[100],s[100],tos=0,cnt=0,l;
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
    if(a[i]<0)
    {
        b[k++]=a[i];
    }
    else{
        for(j=0;j<i;j++)
        {
            if(a[i]==-(a[j]))
                b[k++]=a[i];
        }
    }
}
//for(i=0;i<k;i++)
  //printf("%d ",b[i]);
  for(i=0;i<pow(2,k);i++)
{
    tos=0;
    for(j=0;j<k;j++)
    {
     if(i&1<<j)
     {
        if(tos==0 && b[j]>0){ s[tos++]=b[j];break;}
       else  if(b[j]<0)
            s[tos++]=b[j];
        else if(s[tos-1]+b[j]==0) tos--;
        else break;

     }
    }

    if(tos==0) cnt++;
     // else
     // {
       //     for(l=0;l<tos;l++) printf("%d,",s[l]);
 //printf("\n");
   //   }
}
printf("%d\n",cnt%1000000007);
return 0;
}
