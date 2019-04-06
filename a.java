import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.io.*;
 

public class login extends Frame implements ActionListener
{
	Frame frm;
	Panel pan;
	Label l1,l2;
	TextField t1,t2;
	Button b1;
	
public login()
{
  frm=new Frame("Login");
  pan=new Panel();
  l1=new Label("user_id");
  l2=new Label("password");
  t1=new TextField(20);
  t2=new TextField(20);
  b1=new Button("login");
 

  frm.add(pan);
  frm.setSize(300,300);
  frm.setVisible(true);

  pan.add(l1);
  pan.add(t1);
  pan.add(l2);
  pan.add(t2);
  pan.add(b1);
 
  b1.addActionListener(this);
}

public void actionPerformed(ActionEvent ev)
{
  if(ev.getSource()==b1)
  {
    ResultSet rs;
    try
    {
     Class.forName("oracle.jdbc.driver.OracleDriver");
     Connection con=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:xe","system","system");
     preparedStatement st=con.preparedStatement("select * from login where user_id=? & password=?");

     st.setString(1,t1.getText());
     st.setString(2,t2.getText());
     
     rs=st.executeQuery();


   if(rs.next()==null)
    {
      System.out.println("login fail");

     } 
    
     else
     {
       System.out.println("login succes");
      }
     }//try
     catch(Exception e)
     {
      }
}
}
public static void main(String args[])
{
login log=new login();
}
}