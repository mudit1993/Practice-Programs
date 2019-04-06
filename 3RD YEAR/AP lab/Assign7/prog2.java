import java.io.*;
class prog2
{
public static void main(String arg[])
{
try{
int i,a,b,c;
int ar[]=new int[5];
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter 5 numbers");
for( i=0;i<5;i++)
ar[i]=Integer.parseInt(br.readLine());
for(i=0;i<7;i++)
System.out.print(ar[i]+" ");
}//try
catch(IOException e)
{
System.out.println("Exception found");
}
catch(ArrayIndexOutOfBoundsException ee)
{
System.out.println("\nArray size exceeded");
}
System.out.println("I am working fine");
}
}