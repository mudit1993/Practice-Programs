#include<stdio.h>
//check for (bring)even(to win)+fibonacci number
int main()
{
int i=0,fib[10000],b=0,c=1,a=0,t,n,min,flag,arr[100];
for(i=0;i<10000;i++) fib[i]=0;
while(a<10000)
{
    a=b+c;
    b=c;
    c=a;
    if(a<10000)
    fib[a]=1;
    }
//for(i=0;i<10;i++) printf("%d)%d,",i,fib[i]);
scanf("%d",&t);
while(t--)
{
   a=b=0,c=1;
    int cnt=0;
    min=10005;
flag=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
      scanf("%d",&arr[i]);
      if(min>arr[i])
        min=arr[i];
      if(fib[arr[i]]==1) flag=1;
}
//printf("min-%d flag=%d",min,flag);
if(flag==1) {printf("Alice 1\n");continue;}
else{while(fib[min]==0 && flag==0)
{
if(cnt%2==0)
{i=0;//printf("hii");
    while(i<min)
    {//printf("hqqi");
        if(fib[min-i]!=1 && fib[i]==1)
        {
        cnt++;//printf("hi22");
         min-=i;
       //  printf("\n%d",min);
         break;
         //printf("hi");
         }
         i++;
        // printf("%d",i);
    }
    if(i>=min) flag=1;
}
else
{//printf("ihi");
i=min;
    while(i>0 && cnt%2!=0)
    {
        if(fib[min-i]!=1 && fib[i]==1)
        {
        cnt++;
         min-=i;
        // printf("\n%d",min);
         break;}
         i--;
    }
}
//if(flag==1) break;
}

printf("Bob %d",cnt+2);
}
}
return 0;
}
