import java.io.*;
import java.net.*;
public class Client {
public static void main(String arg[]){
	try{
String host = arg[0];
int port = Integer.parseInt(arg[1]);

System.out.println("Your Host-name is: "+ host + "\nPort in use:"+port+"\n");
Socket sock = new Socket(host,port); // socket(String hostname,int port)  constructor is called
System.out.println("You are connected to :"+ sock.getRemoteSocketAddress());
DataOutputStream out = new DataOutputStream(sock.getOutputStream());
out.writeUTF("Sending a Message from "+ sock.getLocalSocketAddress()+"----Hey there!----");
DataInputStream in = new DataInputStream(sock.getInputStream());
System.out.println("Received message from the Server: \" "+in.readUTF()+ "\"");
sock.close(); //closing the socket
	}catch(Exception e){
	e.printStackTrace();
	}
}
}