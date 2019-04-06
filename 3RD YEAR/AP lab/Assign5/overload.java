import java.io.*;
class overload
{
public static void add(float a,float b)
{
System.out.println("Sum is(float,float):"+(a+b));
}
public static void add(float a,int b)
{
System.out.println("Sum is(float,int):"+(a+b));
}
public static void add(int a,int b)
{
System.out.println("Sum is(int,int):"+(a+b));
}
public static void add(int a,float b)
{
System.out.println("Sum is:(int,float)"+(a+b));
}
public static void main(String arg[])
{add(5.3f,2.8f);
add(4.5f,2);
add(8,45);
add(5,2.7f);
}
}