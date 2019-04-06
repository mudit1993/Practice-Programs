class prog5
{
public static void main(String arg[])
{
int i,ce=0,co=0;
int odd=0;
int even=0;
for(i=0;i<arg.length;i++)
{
if(Integer.parseInt(arg[i])%2==0)
{
ce++;
even+=Integer.parseInt(arg[i]);
}
else
{
co++;
odd+=Integer.parseInt(arg[i]);
}
}//for
System.out.println("Number of even:"+ce);
System.out.println("Number of odd:"+co);
System.out.println("Sum of even:"+even);
System.out.println("Sum of odd:"+odd);
System.out.println("Grand Total:"+(odd+even));

}
}