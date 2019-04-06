#include<stdio.h>
#include<string.h>
double dp[101][101][101];
int get(int n){
	return n*(n-1)/2;
}
double C(int a,int b,int c){
	return 1.0*a*b/(get(a+b+c)-get(c)-get(b)-get(a));
}
int main(){
	int a,b,c,i,j,k;
	int  end=1;
	while(scanf("%d%d%d",&a,&b,&c)==3){
		for(i=0;i<=a;i++)
			for(j=0;j<=b;j++)
				for(k=0;k<=c;k++)
					dp[i][j][k]=0;
		dp[a][b][c]=1;
		double a1=0,a2=0,a3=0;
		for(i=a;i>=0;i--)
			for(j=b;j>=0;j--)
				for(k=c;k>=0;k--){
					 end=1;
					if(i&&j){
						dp[i][j-1][k]+=dp[i][j][k]*C(i,j,k);
						end=0;
					}
					if(j&&k){
						dp[i][j][k-1]+=dp[i][j][k]*C(j,k,i);  // j wins over k
						end=0;
					}
					if(i&&k){
						dp[i-1][j][k]+=dp[i][j][k]*C(i,k,j);//decrement the index that is a loser to the other one  k wins over i
						end=0;
					}
					if(end&&i)a1+=dp[i][j][k];// j=k=0 here a times
					//this is added when 2 out of 3 is zero and the one left contains the prob. of survival
					if(end&&j)a2+=dp[i][j][k];//i=k=0 here b times
					if(end&&k)a3+=dp[i][j][k];//i=j=0 here c times
				}
		printf("%.10lf %.10lf %.10lf\n",a1,a2,a3);
	}
}
