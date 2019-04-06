import java.io.*;
import java.net.*;
public class server extends Thread{ 
private ServerSocket serversocket;
public server(int port)throws IOException{
	serversocket = new ServerSocket(port);
	serversocket.setSoTimeout(20000);
}

public void run(){
	while(true){
	try{
			System.out.println("Waiting for the Client at port: "+ serversocket.getLocalPort()+"....");//runs first
			Socket serv = serversocket.accept();  // accepting the request from the client  ===  writeUTF();
			System.out.println("Just Connected to the client+ "+ serv.getRemoteSocketAddress());
			DataInputStream in = new DataInputStream(serv.getInputStream());
			System.out.println("Received message from the Client: \" "+in.readUTF()+ "\"");
			DataOutputStream out = new DataOutputStream(serv.getOutputStream());
			out.writeUTF("Sending a Message from Server:"+ serv.getLocalSocketAddress()+"==== Got the message!Thank you.BYEBYE! ====");
			serv.close();
				
	}catch(Exception ee){
	ee.printStackTrace();
	break;
	}
	}
}


public static void main(String arg[]){
try{
	Thread thrd = new server(Integer.parseInt(arg[0]));
	thrd.start();
}catch(Exception e){
	e.printStackTrace();
}
}
}