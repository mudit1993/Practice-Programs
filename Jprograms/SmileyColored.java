/*
        Draw Smiley In Applet Example
        This Java example shows how to to draw smiley in an applet window using
        drawString Java Applet class.
*/
 
 
import java.awt.*;
import java.applet.*;
 
public class SmileyColored extends Applet{
       
        public void paint(Graphics p){
               
             //set green color
             //p.setColor(Color.green);
//display a rectangle to contain drawing
             //p.fillRect(40,40,200,200);
              //set red color
              p.setColor(Color.red);
              //face
              p.fillOval(90, 70, 80, 80);
              //set black color
              p.setColor(Color.black);
              //eyes
              p.fillOval(110, 95, 5, 5);
              p.fillOval(145, 95, 5, 5);
              //nose
              p.drawLine(130, 95, 130, 115);
              //set yellow color
              p.setColor(Color.yellow);
              //mouth
              p.fillArc(113, 115, 35, 20, 0, -180);
        }
}