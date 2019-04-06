//saurav anand :)
#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k,temp;
	printf("enter the no of process:-");
	scanf("%d",&n);
	char p[n][10],e,tempt[10];
	int bt[n],art[n];
	float s=0,s1=0,t=0;
	for(i=0;i<n;i++)
	{
		printf("enter the process name and burst time :-");
		scanf("%s%d",p[i],&bt[i]);
		printf("want to enter the arrival time Y/N:-");
		scanf("%c",&e);
		scanf("%c",&e);
		if(e=='Y'||e=='y')
		{
			printf("arrival time : ");
			scanf("%d",&art[i]);
		}
		else
			art[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((art[i]>art[j])||((art[i]==art[j])&&(bt[i]>bt[j])))
			{
				temp=art[i];
				art[i]=art[j];
				art[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				strcpy(tempt,p[i]);
				strcpy(p[i],p[j]);
				strcpy(p[j],tempt);
			}
		}
	}
	printf("PROCESS BURST TIME  ARRIVAL TIME   WAITING TIME   RESPONSE TIME   TURN AROUND TIME\n");
	for(i=0;i<n;i++)
	{
		printf(" %s\t%d\t\t%d\t%f\t%f\t%f\n",p[i],bt[i],art[i],s-art[i],s-art[i],s-art[i]+bt[i]);
		t=t+s-art[i]+bt[i];
		s1=s1+(s-art[i]);
		s=s+bt[i];
		for(j=i+1;(j<n)&&(art[j]<=s);j++)
		{
			for(k=j+1;(k<n)&&(art[k]<=s);k++)
			{
				if(bt[j]>bt[k])
				{
					temp=art[j];
					art[j]=art[k];
					art[k]=temp;
					temp=bt[j];
					bt[j]=bt[k];
					bt[k]=temp;
					strcpy(tempt,p[j]);
					strcpy(p[j],p[k]);
					strcpy(p[k],tempt);
				}
			}
		}
	}
	printf("total turn around time = %f\n",t);
	printf("average turn around time = %f\n",t/n);
	printf("total waiting time = %f\n",s1);
	printf("average waiting time = %f\n",s1/n);
	return(0);
}
