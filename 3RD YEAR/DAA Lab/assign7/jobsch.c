#include<stdio.h>
void main()
{
int j,i,t,n,k=1,r,q;
int dl[20],job[20];
int profit[20],sv[20];
printf("Enter number of jobs\n");
scanf("%d",&n);
printf("Enter %d deadlines and their profits\n",n);
for(i=1;i<=n;i++)
{
job[i]=i;
scanf("%d%d",&dl[i],&profit[i]);
sv[i]=0;
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n-i;j++)
{
if(profit[j]<profit[j+1])
{
t=profit[j];
profit[j]=profit[j+1];
profit[j+1]=t;
//t=job[j];
//job[j]=job[j+1];
//job[j+1]=t;
t=dl[j];
dl[j]=dl[j+1];
dl[j+1]=t;
}
}
}

printf("Job\tDeadline\tProfit\n");
for(i=1;i<=n;i++)
printf("%d\t%d\t\t%d\n",job[i],dl[i],profit[i]);
/*printf("Job\n");
for(i=1;i<=n;i++)
printf("%d ",job[i]);
printf("profit\n");
for(i=1;i<=n;i++)
printf("%d ",profit[i]);
*/
sv[1]=1;
sv[0]=0;
dl[0]=0;
for(i=2;i<=n;i++)
{
r=k;
while(dl[sv[r]]>dl[i] && dl[sv[r]]>r)
r--;
if(dl[sv[r]]<=dl[i] && dl[i]>r)
{
for(q=k;q>r;q--)
sv[q+1]=sv[q];
sv[r+1]=i;
k++;
}
}

printf("Sequence of job:\n");
for(i=1;i<=k;i++)
printf("%d ",sv[i]);
}

