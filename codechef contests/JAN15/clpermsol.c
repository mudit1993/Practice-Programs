#include<stdio.h>

void merge(unsigned long long int arr[],int min,int mid,int max)
{
  unsigned long long int tmp[100000];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}

void part(unsigned long long int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}

unsigned long long int sumn(unsigned long long int a)
{
    unsigned long long int x,y;
    if(a%2==0)
    {
        x=a+1;
        a/=2;
        return(a*x);
    }
    else
    {
        x=(a+1)/2;
        return(a*x);
    }
}
int main()
{
    int t,i,j;
    unsigned long long int n,k,x[100000],sum,ul;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu",&n,&k);
        if(k==0)
        {
            if(n%2==0)
            {
                if((n/2)%2==0)
                {
                    printf("Chef\n");
                    continue;
                }
                else
                {
                    printf("Mom\n");
                    continue;
                }
            }
            else
            {
                if(((n+1)/2)%2==0)
                {
                    printf("Chef\n");
                    continue;
                }
                else
                {
                    printf("Mom\n");
                    continue;
                }
            }
        }
        for(i=0;i<k;i++)
        {
            scanf("%llu",&x[i]);
        }
        part(x,0,k-1);
        if(x[0]==1)
        {
            printf("Chef\n");
            continue;
        }
        else if(x[0]==2)
        {
            printf("Mom\n");
            continue;
        }
        sum=0;
        ul=x[0];
        for(i=0;i<k;i++)
        {
            sum=sum+x[i];
            ul=sumn(x[i])-sum;
            if(x[i]>ul)
            {
                break;
            }
        }
        if(i<k)
        {
            if(x[i]%2==0)
            {
                printf("Mom\n");
                continue;
            }
            else
            {
                printf("Chef\n");
                continue;
            }
        }
        else
        {
            ul=sumn(n)-sum+1;
            if(ul%2==0)
            {
                printf("Mom\n");
                continue;
            }
            else
            {
                printf("Chef\n");
                continue;
            }
        }
    }
    return(0);
}
