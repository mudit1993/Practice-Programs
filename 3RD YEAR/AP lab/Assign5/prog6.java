import java.io.*;
interface inter
{
public void disp();
}
class test2 implements inter
{
public void disp()
{
System.out.println("Interface function");
}
public void displ()
{
System.out.println("class's function");
}
}
class prog6
{
public static void main(String arg[])
{
test2 obj=new test2();
obj.disp();
obj.displ();
inter ob=new test2();
ob.disp();
ob=obj;
ob.displ();

}
}