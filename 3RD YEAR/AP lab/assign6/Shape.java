import java.io.*;
class Shape
{
public void area(int a)
{
System.out.println("Area of a Circle is:"+(3.14*a*a));
} 
public void area(int a,int b)
{
System.out.println("Area of a Triangle is:"+(0.5*a*b));
}
public void area(int a,int b,int c)
{
System.out.println("Area of Rectangle is:"+(a*b));
}
public static void main(String arg[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int r,s;
Shape s1=new Shape();
System.out.println("Enter radius");
r=Integer.parseInt(br.readLine());
s1.area(r);
System.out.println("Enter Base and height of triangle");
r=Integer.parseInt(br.readLine());
s=Integer.parseInt(br.readLine());
s1.area(r,s);
System.out.println("Enter Sides of rectangle");
r=Integer.parseInt(br.readLine());
s=Integer.parseInt(br.readLine());
s1.area(r,s,1);
}
}