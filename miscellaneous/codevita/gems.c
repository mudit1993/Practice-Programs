#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
int N,D,i=0,sum=0,gem=100,p=0,po=1,D1,c=0;
int arr[7],arr1[7];
scanf("%d%d",&N,&D);
if(N<0 || N>100)
printf("Invalid Input\n");
else if(D>100)
printf("Invalid Input\n");
else{
gem-=N;
sum=N;
while(po<N && gem!=0 && i<7)
{
arr[i]=po;
gem-=po;
sum+=arr[i];
i++;
p++;
po=(int)pow(2,p);
}
arr[i]=N;
i++;
while(i<7)
{
if(i==6)
{
arr[i]=gem;
break;
}
else
{
arr[i]=sum+1;
gem-=arr[i];
sum+=arr[i];
i++;
}
}//while loop over
if(sum>100)
{
sum=0;
gem=100-N;po=1;
while(po<gem && i<5)
{
arr[i]=po;
sum+=arr[i];
i++;
p++;
po=(int)pow(2,p);
}
arr[5]=gem-sum;
if(arr[5]>arr[6])
{
arr[5]=arr[5]+arr[6];
arr[6]=arr[5]-arr[6];
arr[5]=arr[5]-arr[6];
}
}//end of if
else if(sum<100)
{
arr[5]+=(100-sum);
if(arr[5]>arr[6])
{arr[5]=arr[5]+arr[6];
arr[6]=arr[5]-arr[6];
arr[5]=arr[5]-arr[6];
}
}

D1=D;
sum=0;
if(D>arr[6])
{
while(sum!=D)
{
for(i=6;i>=0;i--)
{
if(arr[i]<=D1 && sum<D)
{
sum+=arr[i];
D1-=arr[i];
arr1[c]=arr[i];
c++;
}
}
}
}
else
{
while(sum!=D)
{
for(i=0;i<7;i++)
{
if(arr[i+1]>D1 && sum<D && i!=6)
{
sum+=arr[i];
D1-=arr[i];
arr1[c]=arr[i];
c++;
break;
}
}
}
}
for(i=0;i<7;i++)
printf("%d ",arr[i]);
printf("\n");
for(i=c-1;i>=0;i--)
printf("%d ",arr1[i]);
printf("\n");
}
return 0;
}
