import java.io.*;
import java.math.*;
public class prog2
{
	
	public static void main(String arg[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int i,n,j;
		long m,prod=1;
		
		n=Integer.parseInt(br.readLine());
		long a[][]=new long[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=Long.parseLong(br.readLine());
			}
		}
		m=Long.parseLong(br.readLine());
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=(long)Math.pow(a[i][j],m);
				//BigInteger no=BigInteger.valueOf(a[i][j]);
				//no=no.multiply(BigInteger.valueOf(prod));
				//prod=no.longValue();
				prod=(prod*a[i][j]%1000000007);
			}
		}
		System.out.println(prod);//%1000000007);
	}
}