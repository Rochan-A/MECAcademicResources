class original{

	public int variable;

	public void display(int a){
		variable = a;
		System.out.printf("The values is: %d\n", variable);
	}
}

class SubClass extends original{
}

class Calls{
	public static void main(String args[]){
		SubClass s = new SubClass();
		s.display(10);
	}
}