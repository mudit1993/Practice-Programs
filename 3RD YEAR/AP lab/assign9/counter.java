import java.awt.*;
import javax.swing.*;
public class counter extends JApplet
{
int st=0;
int stop=0;
int des=0;
int init=0;
public void init()
{
init++;
}
public void start()
{
st++;
}
public void stop()
{stop++;
}
public void destroy()
{
des++;
System.out.println("Init:"+init);
System.out.println("Stop:"+stop);
System.out.println("Start:"+st);
System.out.println("Destroy:"+des);
}
}
