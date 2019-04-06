import java.io.*;
class prog3
{
public static void main(String arg[])
{
try{
int a,b;
String s=null;
try{BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter 2 number");
a=Integer.parseInt(br.readLine());
b=Integer.parseInt(br.readLine());
System.out.println("Quotient:"+a/b);
}
catch(IOException e11)
{
System.out.println(e11);
}
catch(ArithmeticException e12)
{
System.out.println(e12);
}
catch(Exception e33)
{
System.out.println(e33);
}
System.out.println("Length is:"+s.length());
}//try
catch(ArithmeticException e1)
{
System.out.println(e1);
}
catch(NullPointerException e2)
{
System.out.println(e2);
}
catch(Exception e3)
{
System.out.println(e3);
}
}//main
}//class
