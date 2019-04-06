#include<stdio.h>
int main()
{
char c;
int n,i;
float avg=0.0;
printf("Enter no. of processes\n");
scanf("%d",&n);
int bt[n];
int wt[n+1];
wt[0]=0;
for(i=0;i<n;i++)
{
printf("Enter burst time for process %d\n",i+1 );
scanf("%d",&bt[i]);
avg=avg+wt[i];
wt[i+1]=wt[i]+bt[i];
}
printf("Process\tBurst_time\tWaiting time\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t\t%d\n",i+1,bt[i],wt[i]);
}
avg=avg/n;
printf("Average Waiting time is %f\n",avg);
return 0;
}
