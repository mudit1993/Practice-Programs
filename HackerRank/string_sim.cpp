#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const unsigned hp=10007;
unsigned hsh[100100],hpow[100100];
unsigned geth(int a,int b)
{
	return (hsh[b]-hsh[a])*hpow[100001-b];
}
char str[100100];

int main()
{
	hpow[0]=1;
	for(int i=1;i<100100;i++)
		hpow[i]=hpow[i-1]*hp;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		int l=strlen(str);
		hsh[0]=0;
		for(int j=1;j<=l;j++)
			{hsh[j]=hsh[j-1]+str[j-1]*hpow[j-1];
			printf("%u %u\n",hsh[j-1],hpow[j-1]);
			}
		long long ans=0;
		for(int j=0;j<l;j++)
		{
			int low=0,high=l-j+1,mid;
			while(low+1<high)
			{
				int mid=(low+high)/2;
				unsigned a=geth(0,mid);
				unsigned b=geth(j,j+mid);
				if(a==b)
					low=mid;
				else
					high=mid;
			}
			ans+=low;
		}
		cout<<ans<<endl;
	}
}
