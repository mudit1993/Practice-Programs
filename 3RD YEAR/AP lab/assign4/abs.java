import java.io.*;
abstract class shape
{
public abstract void area();
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
public class abs
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

}
}