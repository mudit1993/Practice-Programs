#include<stdio.h>
int main()
{
int T,i=0,k=1;
scanf("%d",&T);
if(T>=1 && T<=1000)
{
int N[T],B[T];
while(i<T)
{
scanf("%d%d",&N[i],&B[i]);
i++;
}
i=0;
while(i<T)
{
k=1;
while(((k*(k+1))/2)<=B[i])
{
if(((k*(k+1))/2)==B[i])
{
k=-1;
break;
}
k++;
}
if(k==-1)
printf("%d\n",((N[i]*(N[i]+1))/2)-1);
else
printf("%d\n",(N[i]*(N[i]+1))/2);
i++;
}
}
}
