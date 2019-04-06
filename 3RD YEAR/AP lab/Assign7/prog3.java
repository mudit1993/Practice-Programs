import java.io.*;
class A
{
int a=1;
public int b=2;
private int c=3;
protected int d=4;
public void disp()
{
System.out.println("In class A");
System.out.println("a="+a+" b="+b+" c="+c+" d="+d);
}
}//class A
class B extends A
{
int a1=5;
public int b1=6;
private int c1=7;
protected int d1=8;
public void disp()
{
System.out.println("In class B");
System.out.println("a="+a+" b="+b+" d="+d);
System.out.println("a1="+a1+" b1="+b1+" c1="+c1+" d1="+d1);
}
}
class C extends B
{
int a2=9;
public int b2=10;
private int c2=11;
protected int d2=12;
public void disp()
{
System.out.println("In class C");
System.out.println("a="+a+" b="+b+" d="+d);
System.out.println("a1="+a1+" b1="+b1+" d1="+d1);
System.out.println("a2="+a2+" b2="+b2+" c2="+c2+" d2="+d2);
}
}
public class prog3
{
public static void main(String arg[])
{
C obj=new C();
obj.disp();
A obj1=new A();
obj1.disp();
B obj2=new B();
obj2.disp();
}
}