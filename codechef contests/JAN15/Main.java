import java.io.*;
import java.util.*;
public class Main
{
public static void main(String arg[])throws IOException,NumberFormatException,Exception
{
//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
Scanner sc=new Scanner(System.in);
int n,m,i,type,y,x,c,d,diff,num,cnt;
//char x;
String s=new String();
n=sc.nextInt();
m=sc.nextInt();
//n=Integer.parseInt(br.readLine());
//m=Integer.parseInt(br.readLine());
//s=br.readLine();
s=sc.next();
while(m!=0)
{
	type=sc.nextInt();
	//type=Integer.parseInt(br.readLine());
	if(type==1)
	{
		//System.out.println("x:length:"+s.length());
		x=sc.nextInt();
		//x=(char)br.read();
		//System.out.println("y:");
		y=sc.nextInt();
		s=s.substring(0,x-1)+y+s.substring(x);
		//System.out.println("String is:"+s);
	}
	else if(type==2)
	{cnt=0;
	c=sc.nextInt();
	d=sc.nextInt();
	diff=d-c+1;
	while(diff!=0)
	{
		for(i=c-1;(i+diff)<=d;i++)
		{
		//System.out.println("substring "+sub+" diff "+diff );
		num=Integer.parseInt(s.substring(i,i+diff));
		//System.out.println("number "+num);
		if(num%3==0) cnt++;
		}
		diff--;
	}
	System.out.println(cnt);
	}
	m--;
	//sc.close();
}
}
}