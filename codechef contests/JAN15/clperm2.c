#include<stdio.h>
int k[100000],i,j;
int partition(int l,int h)
{
    int t;
   int pivot;
   pivot=k[l];
   i=l-1;
   j=h+1;
   while(1)
   {
   do{
   j--;
   }while(k[j]>pivot);
      do{
   i++;
   }while(k[i]<pivot);
   if(i<j)
   {
   t=k[i];
   k[i]=k[j];
   k[j]=t;
   }
   else return j;
   }
}
void quicksort(int p,int r)
{
if(p<r)
{
int q=partition(p,r);
quicksort(p,q);
quicksort(q+1,r);
}
}

int main()
{
    int t,kk,sum,m,s,r,a,val,b;
    long long int n;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;s=0;
        scanf("%lld%d",&n,&kk);
          if(kk==0){
                sum=((n*(n+1))/2);
                if(sum%2==0)
                printf("Chef\n");
                else printf("Mom\n");
          continue;}
          //for(m=0;m<=n;m++)
            //arr[m]=0;
        for(m=0;m<kk;m++)
        {
            scanf("%d",&val);
            k[m]=val;
            //arr[val]=1;
            sum+=val;
        }
        quicksort(0,kk-1);
       // for(m=0;m<=n;m++)
        //    printf("%d,",arr[m]);
        if(k[0]==1) printf("Chef\n");
        else if(k[0]==2) printf("Mom\n");
        else{
        for(m=1;m<kk;m++)
        {s=0;b=m-1;
            for(r=(k[m]-1),a=1;r>=1,a!=r;a++,r--)
            { // printf("r=%d\n",k[m]);
                if(r+a==k[m])
               {
                   if(b>=0){ if(r==k[b]){b--;continue;}}
                   s=k[m];break;
              // printf("sum--%d\n",s);
               }
                else if((s+r)==k[m]) {s+=r;break;}
                else continue;
            }
            if(s!=k[m]) break;
        }
        if(m==kk){
            sum=((n*(n+1))/2)-sum;
            if(sum%2==0) printf("Chef\n");
            else printf("Mom\n");
        }
        else{
            if(k[m]%2==0) printf("Mom\n");
            else printf("Chef\n");
        }
        }
    }
return 0;
}
