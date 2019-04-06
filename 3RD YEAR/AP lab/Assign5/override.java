import java.io.*;
class A
{
public void disp()
{
System.out.println("Base Class -A");
}
}
class B extends A
{
public void disp()
{
super.disp();
System.out.println("Child Class -B");
}
}
class override
{
public static void main(String arg[])
{
B obj=new B();
obj.disp();
}
}