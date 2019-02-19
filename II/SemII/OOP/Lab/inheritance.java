class original{

	public int variable;

	public void display(int a){
		variable = a;
		System.out.printf("The values is: %d\n", variable);
	}
}

class SubClass extends original{
	public void display(int a){
		System.out.printf("Method overwritten: %d\n", a);
	}
}

class Calls{
	public static void main(String args[]){
		SubClass s = new SubClass();
		s.display(6);
	}
}