import java.io.*;
interface display
{
public void disp();
}
class test1 implements display
{
public void disp()
{
System.out.println("First program on interface");
}
}
public class prog1
{
public static void main(String arg[])
{
test1 obj=new test1();
obj.disp();
}
}