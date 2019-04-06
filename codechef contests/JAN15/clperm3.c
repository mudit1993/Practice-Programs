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
    int t,kk,m,a;
    long long int n,s,val;
    scanf("%d",&t);
    while(t--)
    {
       s=0;
        scanf("%lld%d",&n,&kk);
        if(kk>100000) kk=100000;
       // printf("%d",kk);
          if(kk==0){
                s=((n*(n+1))/2);
                if(s%2==0)
                printf("Chef\n");
                else printf("Mom\n");
          continue;}
          //for(m=0;m<=n;m++)
            //arr[m]=0;
        for(m=0;m<kk;m++)
        {
            scanf("%lld",&val);
            k[m]=val;
            //arr[val]=1;
            s+=val;
        }
        quicksort(0,kk-1);
       // for(m=0;m<=n;m++)
        //    printf("%d,",arr[m]);
        if(k[0]==1) printf("Chef\n");
        else if(k[0]==2) printf("Mom\n");
        else{
                s=k[0];
        for(m=1;m<kk;)
        {
            val=(((k[m]-1)*k[m])/2)-s;
            while(m<kk && val>=k[m]){s+=k[m];m++;continue;}
            if(m<kk){
            val=(((k[m]-1)*k[m])/2)-s;
           // else break;
            if(val<k[m]){ break;}
            else { s+=k[m];m++;}
           // printf("hey");
            }
// printf("hey");
        }
        if(m==kk){
            s=((n*(n+1))/2)-s;
            if(s%2==0) printf("Chef\n");
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
