import java.io.*;
class prog7
{
public static void main(String arg[])
{
try{
int a;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter a number");
a=Integer.parseInt(br.readLine());
System.out.println("Number is:"+a);
}//try
catch(IOException e)
{
System.out.println("Exception found");
}
catch(NumberFormatException ee)
{
System.out.println("Not a number");
}
System.out.println("I am working fine");
}
}