import java.awt.*;
import javax.swing.*;

class Ex49 extends JFrame {
	
	JLabel a; Choice c; JComboBox x;

	public Ex49() {
		a=new JLabel("Choose color:");
		c=new Choice(); c.add("red");c.add("green");c.add("blue");
		x=new JComboBox(); x.addItem("red"); x.addItem("blue"); x.addItem("green");
		setLayout(new FlowLayout());
		add(a);add(c);add(x);
		setTitle("Combo Box");
		getContentPane().setBackground(Color.magenta);
		setSize(300,300);
		setVisible(true);
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String arg[]) {
		Ex49 f = new Ex49();
	}
}