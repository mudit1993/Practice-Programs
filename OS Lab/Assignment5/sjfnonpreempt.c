#include<stdio.h>
int main()
{
int t,j,c,c1=0,n,i,sum=0;
float avg=0.0,avg1=0.0,avg2=0.0;
printf("Enter no. of processes\n");
scanf("%d",&n);
c=n;
int bt[n],wt[n+1],arr[n+1],tat[n],arr1[n+1],res[n+1],pro[n+1],bt1[n+1],pro1[n];
wt[0]=0;
res[0]=0;
for(i=0;i<n;i++)
{
pro[i]=i+1;
printf("Enter burst time for process %d\n",i+1 );
scanf("%d",&bt[i]);
if(bt[i]>sum)
sum=bt[i];
}
for(i=0;i<n;i++)
{
printf("Enter arrival time of process %d\n",i+1);
scanf("%d",&arr[i]);
arr1[i]=arr[i];
if(arr[i]==0 && sum>=bt[i])
{
sum=bt[i];
bt1[0]=bt[i];
j=i;
}
}
pro1[0]=j+1;
arr1[0]=arr[j];
arr[j]=-1;
for(i=0;i<n;i++)
{
for(j=0;j<n-1-i;j++)
{
if(bt[j]>bt[j+1])
{
t=bt[j];
bt[j]=bt[j+1];
bt[j+1]=t;
t=arr[j];
arr[j]=arr[j+1];
arr[j+1]=t;
t=pro[j];
pro[j]=pro[j+1];
pro[j+1]=t;
}
}
}
c1=1;
//c--;
while(c!=0)
{
 for(i=0;i<n;i++)
 {
 if(sum>=arr[i] && arr[i]>=0)
 {
     bt1[c1]=bt[i];
     pro1[c1]=pro[i];
     arr1[c1]=arr[i];
 wt[c1]=sum-arr[i];
 avg+=wt[c1];
 res[c1]=sum;
 arr[i]=-1;
 sum+=bt[i];
 c1++;
  break;
 }
 else continue;
 }
 c--;
}
for(i=0;i<n;i++)
{
tat[i]=wt[i]+bt1[i];
avg2+=tat[i];
avg1+=res[i];
}
printf("Process\t\tBT\t\tWT\t\tAT\t\tRT\t\tTAT\n");
for(i=0;i<n;i++)
{
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pro1[i],bt1[i],wt[i],arr1[i],res[i],tat[i]);
}
avg=avg/n;
printf("Average Waiting time is %f\n",avg);
printf("Average Response Time is %f\n",avg1/n);
printf("Average TurnAround Time is %f\n",avg2/n);
}

