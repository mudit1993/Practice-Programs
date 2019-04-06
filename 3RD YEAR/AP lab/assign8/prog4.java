import java.io.*;
class prog4
{
public static void main(String arg[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int fact=1;
int no,i;
System.out.println("Enter a number");
no=Integer.parseInt(br.readLine());
for(i=1;i<=no;i++)
fact*=i;
System.out.println("Factorial is:"+fact);
}
}