jujujimport java.applet.*;
import java.awt.*;
//import java.awt.event.*;

public class student extends Applet 
{
String n,r,ch;
int marks;
  public void init()
{
try{
n=getParameter("name");
if(n==null) n="Not Found!";
r=getParameter("roll");
if(r==null) r="Not Found!";
marks=Integer.parseInt(getParameter("marks"));
ch=getParameter("grade");
if(ch==null) ch="Not Found!";
}
catch(Exception e)
{System.out.println(e);}
}
 public void paint(Graphics g)
{
setBackground(Color.CYAN);
g.drawString(n,100,100);
g.drawString(r,100,120);
g.drawString(String.valueOf(marks),100,140);
g.drawString(ch,100,160);
}
}