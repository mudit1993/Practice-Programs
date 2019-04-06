import java.io.*;
class student 
{
String name,address,subject,branch,roll;
int age;
float cgpa;
char g;

student()
{
name="Mudit";
address="KP-6";
subject="Computer Science";
branch="CSE";
age=20;
cgpa=8.74f;
g='M';
roll="1205269";
}
void display()
{
System.out.println("Name:"+name);
System.out.println("Address:"+address);
System.out.println("Subject:"+subject);
System.out.println("branch:"+branch);
System.out.println("CGPA:"+cgpa);
System.out.println("Age:"+age);
System.out.println("Gender:"+g);
System.out.println("Roll No."+roll);
}
public static void main(String arg[])
{
student s=new student();
s.display();
}
}