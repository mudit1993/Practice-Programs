#include<stdio.h>
int main()
{
char c;
int n,i,sum=0;
float avg=0.0;
printf("Enter no. of processes\n");
scanf("%d",&n);
int bt[n];
int wt[n+1];
int arr[n+1];
wt[0]=0;
arr[0]=0;
for(i=0;i<n;i++)
{
printf("Enter burst time for process %d\n",i+1 );
scanf("%d",&bt[i]);
}
for(i=1;i<n;i++)
{
printf("Enter arrival time?('y' or 'n')\n");
scanf("\n%c",&c);
if(c=='y')
{printf("Enter arrival time of process %d\n",i+1);
scanf("%d",&arr[i]);
}
else
arr[i]=0;
sum+=bt[i-1];
wt[i]=sum-arr[i];
if(wt[i]<0)
wt[i]=0;
avg=avg+wt[i];
}
printf("Process\tBurst_time\tWaiting time\tArrival time\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],arr[i]);
}
avg=avg/n;
printf("Average Waiting time is %f\n",avg);
return 0;
}
