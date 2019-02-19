class Objects{
	int variable;
	Objects(int a){
		variable = a;
	}
	void display(){
		System.out.printf("Object has value: %d\n", variable);
	}
}

class Array{
	public static void main(String args[]){
		Objects o[] = new Objects[5];
		for(int i = 0; i < 5; i++){
			o[i] = new Objects(i);
		}
		for(int i = 0; i < 5; i++){
			o[i].display();
		}
	}
}