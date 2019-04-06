import java.io.*;
public class prog7
{
	public static void main(String arg[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int T,n;
		T=Integer.parseInt(br.readLine());
		while(T!=0)
		{
			n=Integer.parseInt(br.readLine());
			if(n%4==0)
			System.out.println("No");
			else
			System.out.println("Yes");
		T--;
		}
		
	
	
	}
	
	
}