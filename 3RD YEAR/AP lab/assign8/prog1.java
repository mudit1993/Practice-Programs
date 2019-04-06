import java.io.*;
class MyException extends Exception
{
public MyException()
{
}
public MyException(String a)
{super(a);}
public static void main(String arg[])throws Exception
{
int i=Integer.parseInt(arg[0]);
if(i<0 || i>100)
{
MyException obj=new MyException("Invalid Marks(not in range 0-100)");
throw obj;
}
else
System.out.println("Marks is:"+i);
}
}