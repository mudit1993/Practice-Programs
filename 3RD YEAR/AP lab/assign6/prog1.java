import java.io.*;
class A
{
public void disp()
{
System.out.println("Function of class A");
}
}
class B extends A
{
public void disp()
{
System.out.println("Function of class B");
}
}
class C extends A
{
public void disp()
{
System.out.println("Function of class C");
}
}
class prog1
{
public static void main(String arg[])
{
A ob1=new A();
B ob2=new B();
C ob3=new C();
ob1.disp();
A r;
r=ob2;
r.disp();//instance of class B
r=ob3;
r.disp();//instance of class C
}
}