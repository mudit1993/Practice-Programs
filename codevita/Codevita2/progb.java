import java.util.*;
class progb
{
public static void main(String arg[])
{
	int T,x,n,cnt1,i,d1,tot=0,j,t,max=0,min=0;
	float t1;
    Scanner s=new Scanner(System.in);
	T=s.nextInt();
	while(T!=0)
	{
	max=min=tot=0;
	x=s.nextInt();
	n=s.nextInt();
	int z[]=new int[x];
	int c[]=new int[x];
	float d[]=new float[x];
	for(i=0;i<x;i++)
	z[i]=s.nextInt();
	for(i=0;i<x;i++)
	{
	c[i]=s.nextInt();
	d[i]=(float)c[i]/z[i];
	//System.out.print(" "+d[i]);
	}
	for(i=0;i<n;i++)
	{
	d1=s.nextInt();
	tot+=d1;
	}
	for(i=0;i<x;i++)
	{
	for(j=0;j<x-1-i;j++)
	{
	if(d[j]>d[j+1])
	{
	t1=d[j];
	d[j]=d[j+1];
	d[j+1]=t1;
	t=z[j];
	z[j]=z[j+1];
	z[j+1]=t;
	t=c[j];
	c[j]=c[j+1];
	c[j+1]=t;
	}
	}
	}
	int quo=0;
	cnt1=1;
	int tot1=tot;
	while(tot1!=0)
	{
	for(i=x-cnt1;i>=0;i--)
	{
	if((tot1/z[i])!=0)
	{
	quo=tot1/z[i];
	max+=(quo*c[i]);
	tot1=tot1-(quo*z[i]);
	}
	}
	if(tot1!=0)
	{tot1=tot;
	cnt1++;
	i=x-cnt1;
	}
	}
	quo=0;
	cnt1=0;
	tot1=tot;
	while(tot1!=0)
	{
	for(i=cnt1;i<x;i++)
	{
	if((tot1/z[i])!=0)
	{
	quo=tot1/z[i];
	min+=(quo*c[i]);
	tot1=tot1-(quo*z[i]);
	}
	}
	if(tot1!=0)
	{tot1=tot;
	cnt1++;
	i=cnt1;
	}
	}
	System.out.println(max-min);
	T--;
	}

}
}	