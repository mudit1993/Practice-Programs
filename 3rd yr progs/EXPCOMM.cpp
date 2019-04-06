#include <stdio.h>

typedef long long LL;

const int N=1000000;
int sieve[N];
int prime[88888];
int plen=0;

void precalc()
{
	int i,j;
	for(i=2;(j=i*i)<N;i++) if(!sieve[i])
		for(;j<N;j+=i) sieve[j]=1;
	for(i=2;i<N;i++) if(!sieve[i])
		prime[plen++]=i;
}

#define MOD 1000000007

int func(LL p,LL pk) // pk*pk/p*(pk*(p+1)-1) % MOD
{
	int res=(pk/p)%MOD;
	pk%=MOD;
	p%=MOD;
	res=LL(res)*pk%MOD*(pk*(p+1)%MOD-1)%MOD;
	if(res<0) res+=MOD;
	return res;
}

int f(LL n)
{
	n--;
	int zero=(n%MOD)*(n%MOD)%MOD;
	int ans=1;
	for(int i=0;i<plen;i++)
	{
		int p=prime[i];
		if(LL(p)*p>n) break;
		if(n%p) continue;
		LL pk=1;
		for(;n%p==0;n/=p) pk*=p;
		ans=LL(ans)*func(p,pk)%MOD;
	}
	if(n>1) ans=LL(ans)*func(n,n)%MOD;
	ans=(ans+zero)%MOD;
	return ans;
}

int main()
{
	precalc();
	int TST;
	scanf("%d",&TST);
	for(int tst=0;tst<TST;tst++)
	{
		LL p;
		scanf("%lld",&p);
		int res=f(p);
		printf("%d\n",res);
	}
	return 0;
}
