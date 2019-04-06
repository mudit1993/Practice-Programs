<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<%
String firstname	= request.getParameter("FIRSTNAME");
String lastname = request.getParameter("LASTNAME");
String address1 = request.getParameter("ADDRESS");
String address2	= request.getParameter("ADDRESS2");
String address3 = request.getParameter("ADDRESS3");
String city = request.getParameter("CITY");
String province = request.getParameter("PROVINCE");
String memo = request.getParameter("MEMO");

Class.forName("com.mysql.jdbc.Driver");
Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/funeral", "root", "abc123");

ResultSet rs = null;

Statement statement = connection.createStatement();

String sql = ("INSERT INTO memory VALUES ('" + firstname + "','" + lastname + "','" + address1 + "','"+ address2 +"','"+ address3 +"','"+ city +"','"+ postalcode +"','"+ province +"','"+ memo +"') ");
statement.executeUpdate(sql); <!-- if this value is greater than 0, insert is successful, else insertion failed


rs.close();
connection.close();

%>