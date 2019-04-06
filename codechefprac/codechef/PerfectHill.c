#include<stdio.h>
#include<math.h>
int main()
{
int T,i=0,flag=0;
float no;
do{
scanf("%d",&T);
}while(T>10000 || T<1);
float S[T];
while(i<T)
{
    do{
scanf("%f",&S[i]);
    }while(S[i]>=1000000 || S[i]<1);
i++;
}
i=0;
while(i<T)
{
 flag=0;
long k=S[i]-1;
while(k>sqrt((pow(S[i],2)-pow(k,2))))
{
    no=sqrt((pow(S[i],2)-pow(k,2)));
if((no==(int)no || ((no*2)/(int)(no*2))==1) && ((2*S[i])>(no*2)))
   {
       flag=1;
       //printf("%ld\t%f",k,no);
        printf("PERFECT\n");
      break;
}
else k--;
}
if(flag==0)
    printf("IMPERFECT\n");
i++;
}
}
