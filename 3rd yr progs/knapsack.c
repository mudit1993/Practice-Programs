#include<stdio.h>
void main()
{
int wt,flag=0,j,i,t,n;
int wts[20],item[20];
float profit[20],sv[20],max=0.0;
printf("Enter number of items\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter weight and profit for item no. %d",i+1);
item[i]=i+1;
scanf("%d%f",&wts[i],&profit[i]);
profit[i]=(float)profit[i]/wts[i];
sv[i]=0;
}
for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(profit[j]<profit[j+1])
{
t=profit[j];
profit[j]=profit[j+1];
profit[j+1]=t;
t=item[j];
item[j]=item[j+1];
item[j+1]=t;
t=wts[j];
wts[j]=wts[j+1];
wts[j+1]=t;
}
}
}
printf("Enter weight of the knapsack\n");
scanf("%d",&wt);
for(i=0;i<n;i++)
{
while(wt>0 && i<=n)
{
if(wts[i]>wt)
{
flag=1;
break;
}
else
{
sv[i]=1;
wt=wt-wts[i];
}
i++;
}
if(flag==1)
break;
}
if(i<=n)
sv[i]=(float)wt/wts[i];
for(i=0;i<n;i++)
{
printf("Item Number %d- %f\n",item[i],sv[i]);
max+=(profit[i]*sv[i]*wts[i]);
}
printf("Maximum Profit is: %f",max);
}
