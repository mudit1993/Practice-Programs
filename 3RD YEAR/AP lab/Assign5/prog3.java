import java.io.*;
interface display3
{
public void disp();
}
interface display4 extends display3
{
public void disp1();
}
class test3 implements display4
{
public void disp()
{
System.out.println("I am a Base interface");
}
public void disp1()
{
System.out.println("I am a child interface");
}
}
class prog3
{
public static void main(String arg[])
{
test3 obj=new test3();
obj.disp();
obj.disp1();
}
}