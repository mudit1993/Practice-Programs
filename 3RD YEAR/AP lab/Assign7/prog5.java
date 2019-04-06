import java.io.*;
class prog5
{
public static void main(String arg[])
{
int i,a,b,c;
int ar[]=new int[5];
try{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter 5 numbers");
for( i=0;i<5;i++)
ar[i]=Integer.parseInt(br.readLine());
for(i=-1;i<7;i++)
System.out.print(ar[i]+" ");
}//try
catch(IOException e)
{
System.out.println("Exception found");
}//catch
catch(ArrayIndexOutOfBoundsException ee)
{
System.out.println("\nArray size exceeded");
}//catch
finally
{
System.out.println("I am in finally block");
for(i=0;i<5;i++)
System.out.print(ar[i]+" ");
}//finally
}
}