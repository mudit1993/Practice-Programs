import java.awt.*;
import javax.swing.*;
import java.applet.*;

public class form extends JApplet
{
JTextField t1,t2,t3,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19;
JLabel l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17;
JTextArea t4;
ButtonGroup  bg1,bg2;
JButton b1;
JRadioButton r1,r2,r3,r4;
public void init()
{setVisible(true);
//getContentPane().setBackground(Color.magenta);
//setTitle("My Resume");
t5=new JTextField(2);
t6=new JTextField(2);
t7=new JTextField(4);
t1=new JTextField(20);
t2=new JTextField(25);
t3=new JTextField(15);
t8=new JTextField(5);
t9=new JTextField(5);
t10=new JTextField(5);
t11=new JTextField(5);
t16=new JTextField(5);
t12=new JTextField(5);
t13=new JTextField(5);
t14=new JTextField(5);
t15=new JTextField(5);
t17=new JTextField(5);
t18=new JTextField(5);
t19=new JTextField(5);
t4=new JTextArea(3,10);
l1=new JLabel("Name:");
l2=new JLabel("Phn No.:");
l3=new JLabel("Email:");
l4=new JLabel("Address:");
l5=new JLabel("DOB:");
l6=new JLabel("Sex:");
l7=new JLabel("Degree:");
l8=new JLabel("HSC:");
l9=new JLabel("Schooling");
l10=new JLabel("Skills possessed:");
l11=new JLabel("Preferred Workplace:");
l12=new JLabel("Institution");
l13=new JLabel("Year of Pass");
l14=new JLabel("Age");
l15=new JLabel("Speciality");
l16=new JLabel("Marital Status");
l17=new JLabel("RESUME");
b1=new JButton("Submit");
r1=new JRadioButton("Male");
r2=new JRadioButton("Female");
r3=new JRadioButton("Married");
r4=new JRadioButton("Single");
bg1=new ButtonGroup();
bg1.add(r1);bg1.add(r2);
bg2=new ButtonGroup();
bg2.add(r3);bg2.add(r4);
					setLayout(new GridLayout(13,1));
JPanel p=new JPanel();p.add(l17); add(p);
p=new JPanel();p.add(l1);p.add(t1);p.add(l3);p.add(t3); add(p);
p=new JPanel();p.add(l4);p.add(t4);p.add(l2);p.add(t2); add(p);
p=new JPanel();p.add(l5);p.add(t5);p.add(t6);p.add(t7); add(p);
p=new JPanel();p.add(l6);p.add(r1);p.add(r2);p.add(l16);p.add(r3);p.add(r4); add(p);
p=new JPanel();p.add(l12);p.add(l13);p.add(l14);p.add(l15); add(p);
p=new JPanel();p.add(l7);p.add(t8);p.add(t9);p.add(t10);p.add(t11); add(p);
p=new JPanel();p.add(l8);p.add(t12);p.add(t13);p.add(t14);p.add(t15); add(p);
p=new JPanel();p.add(l9);p.add(t16);p.add(t17);p.add(t18);p.add(t19); add(p);
setVisible(true);

}
}
