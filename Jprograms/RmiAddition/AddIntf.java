
import java.rmi.*;

public interface AddIntf extends Remote
{
	public double AddNum(double d1,double d2) throws RemoteException;
}

