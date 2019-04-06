import java.applet.*;
import java.awt.*;
//import java.awt.event.*;

public class prod extends Applet 
{
String n;
int price, qua,tot;
float pro;
  public void init()
{
try{
n=getParameter("name");
if(n==null) n="Not Found!";
price=Integer.parseInt(getParameter("price"));
qua=Integer.parseInt(getParameter("quantity"));
tot=(price*qua);
pro=(float)0.07*tot;
}
catch(Exception e)
{System.out.println(e);}
}
 public void paint(Graphics g)
{
setBackground(Color.CYAN);
g.drawString("Product Name:"+n,100,100);
g.drawString("Price(Each):"+String.valueOf(price),100,120);
g.drawString("Quantity:"+String.valueOf(qua),100,140);
g.drawString("Total price:"+String.valueOf(tot),100,160);
g.drawString("Total Profit:"+String.valueOf(pro),100,180);
g.drawString("THANK YOU!",100,200);
}
}