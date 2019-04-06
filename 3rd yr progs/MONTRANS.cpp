#include <stdio.h>

int main()
{
	int TST;
	scanf("%d",&TST);
	for(int tst=0;tst<TST;tst++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int mink=0;
		int maxm=100*a+b;
		for(int k=1;k<10000;k++)
		{
			int m=100*a+b;
			if(m<c) break;
			m-=c;
			a=m%100;
			b=m/100;
			if(maxm<100*a+b)
			{
				maxm=100*a+b;
				mink=k;
			}
		}
		printf("%d\n",mink);
	}
	return 0;
}
