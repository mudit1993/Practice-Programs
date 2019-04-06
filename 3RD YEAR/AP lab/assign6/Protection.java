package P1;
public class Protection
{
int i=5;
public int j=6;
private int k=7;
protected int l=8;
public Protection()
{
System.out.println("Constructor of Protection");
System.out.println("Public var:"+j);
System.out.println("Default var:"+i);
System.out.println("Protected var:"+l);
System.out.println("private var:"+k);
}
}