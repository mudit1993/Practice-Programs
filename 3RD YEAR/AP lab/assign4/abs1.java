import java.io.*;
abstract class shape
{
public abstract void area();
public final void disp()
{
System.out.println("Function with the body!");
}
public final void disp1()
{
System.out.println("This is a final method");
}
}
class Rectangle extends shape
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
float l,b;
void inp()throws IOException
{
System.out.println("Enter sides of the rectangle");
l=Float.parseFloat(br.readLine());
b=Float.parseFloat(br.readLine());
}
public void area()
{
System.out.println("Area of the rectangle is:"+(l*b));
}
}
class Circle extends shape
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
float r;
void inp()throws IOException
{
System.out.println("Enter radius of a circle");
r=Float.parseFloat(br.readLine());
}
public void area()
{
System.out.println("Area of the circle is:"+(3.14*r*r));
}
}
class Square extends shape
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
float s;
void inp()throws IOException
{
System.out.println("Enter sides of the Square");
s=Float.parseFloat(br.readLine());
}
public void area()
{
System.out.println("Area of the square is:"+(s*s));
}
}
public class abs1
{
public static void main(String arg[])throws IOException
{
Square obj1=new Square();
obj1.inp();
obj1.area();
Circle obj2=new Circle();
obj2.inp();
obj2.area();
Rectangle obj3=new Rectangle();
obj3.inp();
obj3.area();
System.out.println("Taking reference of shape class");
shape s=obj1;
s.disp();
s.area();
System.out.println("Using Square class object");
obj1.disp();
s.disp1();
final int i=10;
//i++; as is final
System.out.println(i);
}
}