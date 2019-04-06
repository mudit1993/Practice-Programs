package P1;
public class SamePackage
{
public SamePackage()
{
Protection p=new Protection();
System.out.println("Constructor of SamePackage");
System.out.println("Public var:"+p.j);
//System.out.println("Default var:"+i);
System.out.println("Protected var:"+p.l);
//System.out.println("private var:"+k);
}
}
