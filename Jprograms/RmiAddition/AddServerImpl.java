import java.rmi.*;
import java.rmi.server.*;
import java.net.*;


public class AddServerImpl extends UnicastRemoteObject implements AddIntf
{
	public AddServerImpl() throws RemoteException
	{
		try
		{
		}
		catch(Exception e1)
		{
			System.out.println("Error : "+e1.getMessage());
		}
	}
	public double AddNum(double d1,double d2)
	{
		return d1+d2;
	}
	public static void main(String t[])
	{
		try
		{
			AddServerImpl o=new AddServerImpl();
			//new AddServerImpl();
			Naming.rebind("ADDSERVER",o);
			System.out.println("Server Started");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}

