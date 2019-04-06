import java.io.*;
public class prog1
{
	public static void main(String arg[])throws IOException
	{

		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int i=0,j=0,cnt=0;
		int T;
		T=Integer.parseInt(br.readLine());
		while(T!=0)
		{
			String s=br.readLine();
			String sort="";
			for(i=97;i<=122;i++)
			{
				for(j=0;j<s.length();j++)
				{
					if((int)(s.charAt(j))==i)
					{
						sort=sort+s.charAt(j);
					}
				}
			}
			int ch[]=new int[50];
			cnt=0;
			int count=0;
			char c1;
			for(i=0;i<sort.length();)
			{
				c1=sort.charAt(i);
				while(c1==sort.charAt(cnt))
				{
					cnt+=1;
					if(cnt>=sort.length()) break;
				}
				ch[count]=Math.abs((cnt-i)-((int)c1-96));
				count++;
				i=cnt;
			}
			int tot=0;
			for(i=0;i<=count;i++)
			{
				tot+=ch[i];
			}
			System.out.println(tot);
			T--;
		}
	}	
}