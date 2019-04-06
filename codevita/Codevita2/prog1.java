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
		int tot=0;
		int cost=0;
			int tot1=0;
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
				ch[count]=((cnt-i)-((int)c1-96));
				count++;
				i=cnt;
			}
			
			for(i=0;i<count;i++)
			{
			//System.out.print(ch[i]+"  ");
				tot+=Math.abs(ch[i]);
				tot1+=ch[i];
			}
			cost+=(tot-(Math.abs(tot1)))/2;
    // System.out.print(tot1);
			if(tot1>0)
			cost+=(tot1*3);
			else 
			cost+=(Math.abs(tot1)*2);
			System.out.println(Math.abs(cost));
			T--;
		}
	}	
}