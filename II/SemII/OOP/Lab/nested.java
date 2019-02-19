class parent{
	int default_variable = 10;
	static class nested{
		int nested_variable = 20;
		void display(){
			System.out.printf("from nested class: %d\n", nested_variable);
		}
	}
}

class driver_class{
	public static void main(String args[]){
		parent.nested pa = new parent.nested();
		pa.display();
	}
}