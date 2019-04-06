import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class Ex54 extends JFrame  implements ActionListener{ 
	
	JRadioButton b1,b2,b3;
	
	Ex54(){
		ButtonGroup bg=new ButtonGroup();
		b1=new JRadioButton("Red"); b1.addActionListener(this);//register for action event
		b2=new JRadioButton("Green"); b2.addActionListener(this);
		b3=new JRadioButton("Blue"); b3.addActionListener(this);
	
		bg.add(b1);bg.add(b2);bg.add(b3);
		setLayout(new FlowLayout());
		add(b1);add(b2);add(b3);
		setTitle("Event - Radio Buttons");
		setSize(400,400);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public static void main(String arg[]){
		Ex54 f =new Ex54();
	}

	public void actionPerformed(ActionEvent ae) {
		if(ae.getSource()==b1)
			getContentPane().setBackground(Color.red);
		if(ae.getSource()==b2)
			getContentPane().setBackground(Color.green);
		if(ae.getSource()==b3)
			getContentPane().setBackground(Color.BLUE);
	}
}