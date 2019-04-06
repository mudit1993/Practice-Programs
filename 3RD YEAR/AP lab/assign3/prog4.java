class prog4
{
public static void main(String arg[])
{ int i=0;
int sum=0;
for(i=0;i<5;i++)
{
sum+=Integer.parseInt(arg[i]);
}
System.out.println("Sum of given 5 integers is:"+sum);
}
}