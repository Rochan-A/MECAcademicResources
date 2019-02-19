import java.util.Scanner;

class Employee{
	int temp_no;
	String ename;
	int sal;

	Employee(){
		System.out.println("Enter the Employee name:");
		ename = System.console().readLine();

		System.out.println("Enter the Employee number:");
		temp_no = Integer.parseInt(System.console().readLine());;

		System.out.println("Enter the Employee salary:");
		sal = Integer.parseInt(System.console().readLine());;
	}

	void putdata(){
		System.out.println("Enter the Employee name:");
		this.ename = System.console().readLine();

		System.out.println("Enter the Employee number:");
		this.temp_no = Integer.parseInt(System.console().readLine());

		System.out.println("Enter the Employee salary:");
		this.sal = Integer.parseInt(System.console().readLine());
	}
}

class Allowance extends Employee{

	double hra = 0.16;
	double da = 0.36;
	double fa = 0.03;

	Allowance(){
		super();
	}

	void dispallowance(){
		System.out.printf("Allowance: %f %f %f\n", sal*hra, sal*da, sal*fa);
	}
}

class deductions extends Allowance{

	double pf = 0.12;
	double pt = 0.01;

	deductions(){
		super();
	}

	void dispdeductions(){
		System.out.printf("Deductions: %f %f\n", sal*pf, sal*pt);
	}
}

class netsal extends deductions{
	double gross;

	netsal(){
		super();
	}

	void display(){
		System.out.println(10);
	}
}

class caller extends netsal{

	caller(){
		super();
	}
	public static void main(String args[]){

		caller c = new caller();
		c.putdata();
		c.dispallowance();
		c.dispdeductions();
		c.display();
	}
}