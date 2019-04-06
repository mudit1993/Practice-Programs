<%-- 
    Document   : index
    Created on : 17 Jul, 2014, 7:39:00 PM
    Author     : WASIM ANWAR
--%>

<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.PreparedStatement"%>
<%@page import="java.sql.Connection"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <script src="swissarmy.js" type="text/javascript"></script>
	<script src="slideshow.js" type="text/javascript"></script>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" href="allstyle.css">
    </head>
    <body>
        <header>
        <img src="images\aaaay.jpg" id=bg>
            <div class="wrapper">
                <div class="container">
                    <img src="images\header.jpg" height="217" width="1000">
                       <header class="mainHeader">
                        <nav>
                            <ul>
                                <li><a href="#">Home</a></li><li>
                                <a href="#">Men</a></li><li>
                                <a href="#">Women</a></li><li>
                                <a href="#">Brand</a></li><li> 
                                <a href="#">Account</a></li><li>
                                <a href="#">Contact</a></li><li>
                                <a href="#">Feedback</a></li>
                            </ul>
                        </nav>
                       </header>
                   <%
           
          
           String a =(String)session.getAttribute("uid");
           if(a!=null)
              {
               try{
             {
            Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
            Connection con=DriverManager.getConnection("jdbc:odbc:Footloose");
            PreparedStatement smt= con.prepareStatement("select * from users where uid=?");
            smt.setString(1,a);
            ResultSet rs=smt.executeQuery();
            rs.next();
            String w=rs.getString(3);
            String e=rs.getString(4);
            String r=rs.getString(5);
            out.println("Name:"+w);
            out.println("Uid:"+a);            
            out.println("Address:"+e);
            out.println("Gender:"+r);
            con.close();
             }
                         }
        catch(Exception e)
        {System.out.println(e);}}
           else
           {%>
           <div class="login">
               <table style=" width: 800; height: 500">
                   <tr>
                       
                       <td style="box-shadow: 0px 0px 40px black;background-color: white;height: 500">
                           <table style="box-shadow: 0px 0px 40px black;background-color: white;height: 400">
                               <form action="login" method="post">
                               <tr colspan="2"><td>Login</td></tr>
                               <tr>
                                   <td>Enter UserId</td>
                                   <td><input type="text" name="uid"></td>
                               </tr>
                               <tr>
                                   <td>Enter Password</td>
                                   <td><input type="text" name="pwd"></td>
                               </tr>
                               <tr><td><a href="register.jsp">New User,Register here!<td/>
                               <td align="left"><input type="Submit" value="Enter"></td>
                                </tr>
                               </form>
                           </table>
                       </td>
                       <td style="height: 500;width: 710">
                       </td>
                      
                   </tr>
               </table>
           </div>
               <%   }
                        
           
        %>
          <footer class="footer">
            <p>
                
              
                
            </p>
        </footer>
                </div>
            </div>
        </header>
       
       
    </body>
</html>
