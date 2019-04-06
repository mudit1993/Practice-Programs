import java.io.*;
class prog2
{
public static void main(String arg[])
{String s=null;
try{
int a[]=new int[3];
int i;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
for(i=0;i<3;i++)
a[i]=Integer.parseInt(br.readLine());
System.out.println("5th Element is:"+a[5]);
}//try
catch(IOException e)
{
System.out.println(e);
}
catch(ArrayIndexOutOfBoundsException e1)
{
System.out.println(e1);
}
catch(Exception e6)
{
System.out.println(e6);
}
try{System.out.println("Length is:"+s.length());
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
