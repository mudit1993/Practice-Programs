#include <stdio.h>
#include <string.h>
int main(void) {
	char a[100000];
	scanf("%s",a);
	int i,flag1=0,flag2=0,flag=0,j,k1=0,k=0;
	int f[100000];
	int f1[100000];
	int l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(a[i]=='A'&& a[i+1]=='B')
		{
			f[k]=i;
			k++;
		}
		if(a[i]=='B'&& a[i+1]=='A')
		{
			f1[k1]=i;
			k1++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<k1;j++)
		{
			if(abs(f[i]-f1[j])>1)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
	printf("YES");
	else
	printf("NO");

	return 0;
}
