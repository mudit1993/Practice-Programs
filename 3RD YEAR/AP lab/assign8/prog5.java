import java.io.*;
class prog5
{
public static void main(String arg[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int f=0;
int no,i;
System.out.println("Enter a number");
no=Integer.parseInt(br.readLine());
for(i=2;i<=no/2;i++)
{
if(no%i==0)
f=1;
}
if(f==0)
System.out.println(no+" is a Prime Number.");
else
System.out.println(no+" is NOT a Prime Number.");
}
}