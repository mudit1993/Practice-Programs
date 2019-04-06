import javax.swing.*;
import java.awt.*;
import java.applet.*;
public class smile extends JApplet
{
public void init(){}
public void paint(Graphics g)
{
g.drawOval(100,100,200,200);//face
g.drawOval(150,150,30,30);//eye
g.drawOval(220,150,30,30);//eye
g.drawArc(150,210,100,60,180,180);//smile
g.drawArc(150,140,30,20,0,180);
g.drawArc(220,140,30,20,0,180);
g.setColor(Color.GREEN);
g.fillOval(230,156,20,20);//eye
g.setColor(Color.BLUE);
g.fillOval(160,156,20,20);//eye
g.setColor(Color.YELLOW);

g.setFont(new Font("TimesRoman", Font.ITALIC, 40));
g.drawString("Smile",30,400);
}
}