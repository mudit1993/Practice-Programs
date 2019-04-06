import javax.swing.*;
import java.awt.*;
import java.applet.*;
public class scene extends JApplet
{
public void init()
{
}
public void paint(Graphics g)
{
g.drawLine(40,350,300,350);
g.drawLine(40,200,300,200);
g.drawLine(40,350,40,200);
g.drawLine(300,350,300,200);
g.drawLine(110,350,110,200);
g.drawLine(40,200,75,150);
g.drawLine(110,200,75,150);
g.drawLine(75,150,265,150);
g.drawLine(300,200,265,150);
g.drawLine(180,350,180,270);
g.drawLine(230,350,230,270);
g.drawLine(180,270,230,270);
g.drawOval(210,305,10,10);
g.drawOval(60,230,30,70);
g.drawLine(60,265,90,265);
g.drawLine(75,230,75,300);
//hills
g.drawLine(20,130,80,20);
g.drawLine(140,130,80,20);
g.drawLine(140,130,200,20);
g.drawLine(260,130,200,20);
g.drawLine(260,130,320,20);
g.drawLine(380,130,320,20);
//boy
g.drawOval(350,230,40,40);
g.drawLine(370,270,350,290);
g.drawLine(370,270,390,290);
g.drawLine(370,270,370,300);
g.drawLine(370,300,350,320);
g.drawLine(370,300,390,320);
//window
g.setColor(Color.BLUE);
g.setFont(new Font("TimesRoman", Font.ITALIC, 40));
g.drawString("Home Sweet Home",30,400);
}
}