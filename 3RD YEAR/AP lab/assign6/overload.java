import java.io.*;
class overload
{
public void swap(int a,int b)
{
int c=a;
a=b;
b=c;
System.out.println("a="+a+"\nb="+b);
} 
public void swap(double a,double b)
{
double c=a;
a=b;
b=c;
System.out.println("a="+a+"\nb="+b);
}
public void swap(char a,char b)
{
char c=a;
a=b;
b=c;
System.out.println("a="+a+"\nb="+b);
}
public static void main(String arg[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int r,s;
double x,y;
char a,b;
overload s1=new overload();
System.out.println("Enter 2 integers a,b");
r=Integer.parseInt(br.readLine());
s=Integer.parseInt(br.readLine());
s1.swap(r,s);
System.out.println("Enter 2 float values a,b");
x=Double.parseDouble(br.readLine());
y=Double.parseDouble(br.readLine());
s1.swap(x,y);
System.out.println("Enter 2 characters a,b");
a=(char)br.read();
b=(char)br.read();
s1.swap(a,b);
}
}