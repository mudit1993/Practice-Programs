#include<stdio.h>
int compare(const void*a,const void*b)
{
	return(*(int*)a-*(int*)b);
}
int scan()
{
	register int c = getchar_unlocked();
	int x=0;
	while(c<48||c>57)c = getchar_unlocked();
	while(c>=48&&c<=57)
	{
		x = (x<<1)+(x<<3)+c-48;
		c = getchar_unlocked();
	}
	return x;
}
int main()
{
	int n, a[1000005], f=0, s=0, i;
	long long int x;
	scanf("%d%lld", &n, &x);
	for(i=0;i<n;i++)a[i]=scan();
	qsort(a,n,sizeof(int),compare);
	//for(i=0;i<n;i++)printf("%d ", a[i]);
	//printf("\n");
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]%2==1)
		{
			if(a[i]/2+1<=x)
			{
				x-=a[i]/2+1;
				a[i]=a[i]/2;
				f++;
			}
			else{flag=1;break;}
		}
		else
		{
			if(a[i]/2<=x)
			{
				x-=a[i]/2;
				a[i]=a[i]/2;
				f++;
			}
			else{flag=1;break;}
		}
	}
	//for(i=0;i<n;i++)printf("%d ", a[i]);
	//printf("\n%lld\n", x);
	//if(flag==0)
	//{
		for(i=0;i<n;i++)
		{
			if(a[i]<=x)
			{
				x-=a[i];
				s++;
			}
			else break;
		}
	//}
	printf("%d %d\n", n-f, s);
	return 0;
}
