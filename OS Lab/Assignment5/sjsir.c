#include<stdio.h>
main()
{
float avg,tot;
int bt[10];
int wt[10];
int endt[10],temp;
int st[100],n,i,j,sum=0;
printf("enter the number of processes:\n");
scanf("%d", &n);
for(i=1; i<=n; i++)
{
printf("enter the burst time of the process: %d", i);
scanf("%d", &bt[i]);
}
printf("sorting done according to burst time");
for(i=1; i<=n; i++)
{
    for(j=i+1; j<=n; j++)
   {
      if(bt[i]>bt[j])
      {
          temp=bt[i];
          bt[i]=bt[j];
          bt[j]=temp;
          }
          }
      if(i==1)
      {
          st[1]=0;
          endt[1]=bt[1];
          wt[1]=0;
          }
          else
          {
              st[i]=endt[i-1];
              endt[i]=st[i]+bt[i];
              wt[i]=st[i];
              }
              }
              printf("\n\n BURST TIME\t START TIME \t END TIME \t WAITING TIME \n\n");
              printf("\n-----------------------------------------------------------------------------------------------------------------------------\n");
              
             for(i=1; i<=n; i++)
             {
           printf("\n%5d%15d%15d%15d", bt[i], st[i], endt[i],wt[i]);
             }
             printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
             for(i=1,tot=0; i<=n; i++)
             tot+=wt[i];
             avg=(float)tot/n;
             printf("\n\n\naverage waiting time=%f", avg);
             for(i=1,tot=0; i<=n; i++)
             tot+=endt[i];
             avg=(float)tot/n;
             printf("\n\naverage turnaround time=%f", avg);
             for(i=1, tot=0; i<=n; i++)
             tot+=st[i];
             avg=(float)tot/n;
             printf("\n\naverage response time =%f\n\n", avg);
             }
             
             
              
