package P2;
public class OtherPackage
{
public OtherPackage()
{
P1.Protection p=new P1.Protection();
System.out.println("Constructor of OtherPackage");
System.out.println("Public var:"+p.j);
//System.out.println("Default var:"+i);
//System.out.println("Protected var:"+l);
//System.out.println("private var:"+k);
}
} 