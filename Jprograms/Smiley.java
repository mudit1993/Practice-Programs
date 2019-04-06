/*
        Draw Smiley In Applet Example
        This Java example shows how to to draw smiley in an applet window using
        drawString Java Applet class.
*/
 
 
import java.awt.*;
import java.applet.*;
 
public class Smiley extends Applet{
       
        public void paint(Graphics g){
               
                //set blue color for drawing
              g.setColor(Color.blue);
              //display rectangle to display drawing
              //g.drawRect(40, 40, 200, 200);
            //face
              g.drawOval(90, 70, 80, 80);
             //eyes
              g.drawOval(110, 95, 5, 5);
              g.drawOval(145, 95, 5, 5);
             //nose
              g.drawLine(130,95,130,115);
             //mouth
              g.drawArc(113,115,35,20,0,-180);
        }
}