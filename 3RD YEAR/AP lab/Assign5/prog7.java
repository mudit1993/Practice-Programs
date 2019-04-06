import java.io.*;
interface inter
{
public void disp();
}
abstract class A
{
public abstract void displ();
}
class test2 extends A implements inter
{
public void disp()
{
System.out.println("Interface function");
}
public void displ()
{
System.out.println("Abstract class's function");
}
}
class prog7
{
public static void main(String arg[])
{
test2 obj=new test2();
obj.disp();
obj.displ();
}
}