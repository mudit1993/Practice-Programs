import java.applet.*;
import java.awt.*;
import java.net.*;

public class sbar extends Applet 
{
  public void init()
{
}
 public void paint(Graphics g)
{
setBackground(Color.CYAN);
g.drawString("Hello World",100,100);
showStatus("This message is in status bar");
}
}