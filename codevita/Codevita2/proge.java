import java.util.*;
class progb
{
public static void main(String arg[])
{
	int T,x,n,i,d1;
    Scanner s=new Scanner(System.in);
	T=s.nextInt();
	while(T!=0)
	{
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
	System.out.print(" "+d[i]);
	}
	for(i=0;i<n;i++)
	{
	d1=s.nextInt();
	tot+=d1;
	}
	
	T--;
	}

}
}	