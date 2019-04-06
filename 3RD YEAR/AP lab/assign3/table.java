import java.io.*;
class table
{

public static void main(String arg[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
String c="";
int i,no;
do{
System.out.println("Enter a Number");
no=Integer.parseInt(br.readLine());
for(i=1;i<=12;i++)
{
System.out.println(no+" x "+i+" = "+(i*no));
}
System.out.println("Continue??(y/n)");
c=br.readLine();
}while(c.equals("y"));
}
}

