import java.util.*;
class progd
{
public static void main(String arg[])
{
	int n,m,i,j,k,g=1;
	int cnt1=0,cnt2=0;
	Scanner s=new Scanner(System.in);
	n=s.nextInt();
	m=s.nextInt();
	int a[][]=new int[m+1][2];
	for(i=0;i<m;i++)
	{
		a[i][0]=s.nextInt();
		a[i][1]=s.nextInt();
	}
	int b[]=new int[n];
	int c[]=new int[n];
	int fl=0;
	for(i=0;i<m;)
	{
	fl=0;
		for(j=0;j<cnt1;j++)
		{
			if(b[j]==a[i][0]||b[j]==a[i][1])
			{ fl=1;
			if(b[j]==a[i][0])
			c[cnt2++]=a[i][1];
			else
			c[cnt2++]=a[i][0];
			i++;
			}
		}
		for(k=0;k<cnt2;k++)
		{
			if(c[k]==a[i][0]||c[k]==a[i][1])
			{ fl=1;
			if(c[k]==a[i][0])
			b[cnt1++]=a[i][1];
			else
			b[cnt1++]=a[i][0];
			i++;
			}
		}
		if(fl==0)
		{
		b[cnt1++]=a[i][0];
		c[cnt2++]=a[i][1];
		i++;
		}
	}
	int flag=0;
	for(i=0;i<cnt1;i++)
	{
	for(j=0;j<cnt2;j++)
	{
		if(b[i]==c[j])
		{flag=1;break;
		}
	}
	}
	if(flag==0|| m==0||m==1)
	System.out.println("Yes");
	else
	System.out.println("No");
}
}