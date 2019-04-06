import java.io.*;
interface display1
{
public int a=5;
public void disp();
}
class test2 implements display1
{
public void disp()
{
a=a+1;//as 'final'
System.out.println("Value is:"+a);
}
}
class prog2
{
public static void main(String arg[])
{
test2 obj=new test2();
obj.disp();
}
}