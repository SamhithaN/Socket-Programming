import java.io.*;
import java.net.*;
import java.util.Scanner;

import javax.servlet.Servlet;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
//import javax.servlet.annotation.WebServlet;

//@WebServlet("/source")

public class source implements Servlet {

	public String firstname,lastname,gender,age,address,phone,email,distance,blood,health;

	@Override
	public void destroy() {
		// TODO Auto-generated method stub
		System.out.println("In destroy");
	}

	@Override
	public ServletConfig getServletConfig() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getServletInfo() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void init(ServletConfig arg0) throws ServletException {
		// TODO Auto-generated method stub
		System.out.println("In init");

	}

	@Override
	public void service(ServletRequest request, ServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html"); 
		PrintWriter pw = response.getWriter(); 
		pw.println("<h2>Submission successful</h2>");
		pw.close();
		System.out.println("In service");

		firstname = request.getParameter("fname");

		lastname = request.getParameter("lname");

		gender = request.getParameter("gender");	

		age = request.getParameter("age");

		address = request.getParameter("address");

		phone = request.getParameter("phone");

		email = request.getParameter("email");

		distance = request.getParameter("distance");

		blood = request.getParameter("blood");
		
		health = request.getParameter("health");
		if(!(health == "2"))
			health = request.getParameter("health_text");
		else
			health = "None";
		

		client();
	}

	public void client() throws IOException
	{

		Socket sock = new Socket("127.0.0.1",9635);

		//Receiving data
		Scanner sc1 = new Scanner(sock.getInputStream());
		String temp = sc1.nextLine();
		System.out.println(temp);

		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream())); 
		
		wr.write(firstname);
		wr.flush();	
	 
		wr.write(lastname);
		wr.flush();	
		
		wr.write(gender);
		wr.flush();	
		
		wr.write(age);
		wr.flush();	
		
		wr.write(address);
		wr.flush();	
		
		wr.write(phone);
		wr.flush();	
		
		wr.write(email);
		wr.flush();	
		
		wr.write(distance);
		wr.flush();	
		
		wr.write(blood);
		wr.flush();
		
		wr.write(health);
		wr.flush();

		//Receiving data 2
		Scanner sc2 = new Scanner(sock.getInputStream());
		String temp2 = sc1.nextLine();
		System.out.println(temp2);
	} 
}
