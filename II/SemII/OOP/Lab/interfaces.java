interface Interface1{
	final int id = 10;
	void display();
}

interface Interface2{
	void putput(int a);
}

class Class3 implements Interface1, Interface2{

	public void display(){
		System.out.println(Interface.id);
	}

	public void putput(int a){
		System.out.println(a);
	}

	public static void main(String arg[]){
		Class3 t = new Class3();
		t.display();
		t.putput(20);
	}
}

/*
abstract class Class1 implements Interface{

	public void display(){
		System.out.println(Interface.id);
	}
}

abstract class Class2 extends Class1 implements Interface{

	public void putput(int a){
		System.out.println(a);
	}
}

class Class3 extends Class2{

	public static void main(String arg[]){
		Class3 t = new Class3();
		t.display();
		t.putput(20);
	}
}
*/