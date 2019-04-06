import java.applet.*;
import java.awt.*;
import java.net.*;

public class path extends Applet 
{
String n,ch;
URL url;
  public void init()
{
try{
url=getCodeBase();
n="Code Base: "+url;
url=getDocumentBase();
ch="Document Base: "+url;
}
catch(Exception e)
{System.out.println(e);}
}
 public void paint(Graphics g)
{
setBackground(Color.CYAN);
g.drawString(n,100,100);
g.drawString(ch,100,160);
}
}