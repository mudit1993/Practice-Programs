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
