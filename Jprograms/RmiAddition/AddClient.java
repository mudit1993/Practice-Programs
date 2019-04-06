import java.rmi.*;
import java.net.*;
import java.io.*;

public class AddClient
{
	public static void main(String t[])
	{
		BufferedReader bf;
		String str1=null,str2=null;
		double cd1,cd2,res;

		//Double p;


		String SRVURL="ADDSERVER";
		try
		{
			bf=new BufferedReader(new InputStreamReader(System.in));
			System.out.print("Enter 1st Number :  ");
			str1=bf.readLine();
			System.out.print("Enter 2nd Number :  ");
			str2=bf.readLine();
		}
		catch(IOException e1)
		{
			System.out.println("Error : "+e1);
		}
		try
		{
			AddIntf o=(AddIntf)Naming.lookup(SRVURL);
			cd1=Double.valueOf(str1).doubleValue();
			cd2=Double.valueOf(str2).doubleValue();
			res=o.AddNum(cd1,cd2);
			//res=cd1+cd2;
			System.out.println("Sum Of The Two Numbers : "+res);
		}
		catch(MalformedURLException e2)
		{
			System.out.println("Invalid URL Address"+ e2);
		}
		catch(NotBoundException e3)
		{
			System.out.println("Error (Not Bound ) "+e3);
		}
		catch(RemoteException e4)
		{
			System.out.println("Remote Object Can Not BE Created : "+e4);
		}

	}
}



