import java.io.*;
class mdp
{

public static void main(String arg[])throws IOException
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int ch,c;
int x,y;
do{
System.out.println("Menu(Press 1,2,3 or 4)");
System.out.println("1)Add 2 numbers");
System.out.println("2)Subtract 2 numbers");
System.out.println("3)Multiply 2 numbers");
System.out.println("4)Divide 2 numbers");
c=Integer.parseInt(br.readLine());
System.out.println("Enter 1st Number");
x=Integer.parseInt(br.readLine());
System.out.println("Enter 2nd Number");
y=Integer.parseInt(br.readLine());
switch(c)
{
case 1: System.out.println("Sum is:"+(x+y));
	break;
case 2: System.out.println("Difference is:"+(x-y));
	break;
case 3: System.out.println("Product is:"+(x*y));
	break;
case 4: System.out.println("Quotient is:"+(x/y));
	break;
default:System.out.println("Enter a valid choice");
}
System.out.println("Do you want to continue?(yes-1,no-0)");
ch=Integer.parseInt(br.readLine());
}while(ch==1);
}
}