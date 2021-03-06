#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MX 2015

int grundy[MX][MX];
bool vis[MX+10];

void pre()
{
	for(int j=1;j<MX;j++) grundy[0][j] = 0; // losing
	
	for(int i=1;i<MX;i++)
	{
		memset(vis,false,sizeof(vis));
		int mex = 0;
		for(int j=1;j<=i;j++)
		{
			vis[grundy[i-j][j]] = true;
			while(vis[mex]) mex++;
			grundy[i][j] = mex;
		}
		for(int j=i+1;j<MX;j++) grundy[i][j] = grundy[i][i];
	}
}

int main()
{
	pre();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, k, x, gr = 0;
		scanf("%d %d",&n,&k);
		while(n--)
		{
			scanf("%d",&x);
			gr = gr ^ grundy[x][min(x,k)];
		}
		puts(gr?"Nancy":"Zeta");
	}
	return 0;
}
