import java.io.*;
class prog1
{
public static void main(String arg[])
{
try{
int a,b,c;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter 2 numbers for division");
a=Integer.parseInt(br.readLine());
b=Integer.parseInt(br.readLine());
c=a/b;
System.out.println("Quotient is:"+c);
}//try
catch(IOException e)
{
System.out.println("Exception found");
}
catch(ArithmeticException ee)
{
System.out.println("Arithmetic Exception(divide by zero)");
}
System.out.println("I am working fine");
}
}