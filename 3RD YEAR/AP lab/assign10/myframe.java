import java.applet.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class myframe extends Applet
{
public void init(){
JFrame f=new JFrame("MY FRAME");
f.setVisible(true);
f.setSize(400,400);
//f.setname()
f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
}