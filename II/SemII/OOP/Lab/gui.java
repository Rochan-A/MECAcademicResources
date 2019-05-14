import java.awt.*;
import java.awt.event.*;

class A extends Frame{

	A(){

		setLayout(new FlowLayout());
		this.setLayout(null);

		Label uname = new Label("Username:");
		TextField u_t = new TextField(20);
		Label password = new Label("Password:");
		TextField p_t = new TextField(20);

		p_t.setEchoChar('#');

		Button login = new Button("Login");
		Button cancel = new Button("Cancel");

		this.add(uname);
		this.add(u_t);
		this.add(password);
		this.add(p_t);
		this.add(login);
		this.add(cancel);

		uname.setBounds(70,90,90,60);
		u_t.setBounds(70,130,90,60);
		password.setBounds(200,100,90,20);
		p_t.setBounds(200,140,90,20);
		login.setBounds(100,260,70,40);
		cancel.setBounds(180,260,70,40);
	}

	public static void main(String args[])
	{
		A ml=new A();
		ml.setVisible(true);
		ml.setSize(400,400);
		ml.setTitle("my login window");
	}
}