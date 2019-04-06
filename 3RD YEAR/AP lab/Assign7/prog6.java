import java.io.*;
class prog6
{
public static void main(String arg[])
{
try{
String c=null;
//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Length is:"+c.length());
}//try
/*catch(IOException e)
{
System.out.println("Exception found");
}*/
catch(NullPointerException ee)
{
System.out.println(ee+"\nString variable is NULL");
}
System.out.println("I am working fine");
}
}