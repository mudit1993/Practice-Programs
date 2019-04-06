import java.io.*;
public class prog10
{
	public static void main(String arg[])throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int no,c=0,i=0,j=0;
		no=Integer.parseInt(br.readLine());
		String s;
		int a[][]=new int[no][no];
		while(true)
		{
		s=br.readLine();
		if(s.equals("-1")) break;
		else
		{
			if(s.charAt(0)=='Q')
			System.out.println(c);
			else
			{
				if(c==0)
				{
				a[0][0]=s.charAt(1);
				a[0][1]=s.chatAt(2);
				
				c++;
				}
				else
				{
				i=0;j=0;
				while(s.charAt(1)!=a[i][j] )
				}
			}
		}
		}
	}
}