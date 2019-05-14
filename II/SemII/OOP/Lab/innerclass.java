class Outer {
	class Inner {
		public void show() {
			System.out.println("In a nested class method");
		}
	}
}

class Outer2 {
	static class Inner {
		public void show() {
			System.out.println("In a static nested class method");
		}
	}
}

class Main {

	
	public static void main(String[] args) {
		//Outer.Inner in = new Outer().new Inner();
		Outer2.Inner in = new Outer2.Inner();
		in.show();
	}
}
