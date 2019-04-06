import java.util.*;
class prog1
{
public static void main(String arg[])throws Exception
{
int arr[]=new int[10];
int i,sum=0;
Scanner s=new Scanner(System.in);
System.out.println("Enter 10 elements");
for(i=0;i<10;i++)
{
arr[i]=s.nextInt();
sum+=arr[i];
}
System.out.println("Sum is:"+sum);
}
}

