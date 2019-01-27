class factorial{

	public static int fact(int a){
		if(a == 0){
			return 1;
		}else{
			return (a) * fact(a-1);
		}
	}

	public static void main(String[] args){
		int a = 5;
		int out = fact(a);
		System.out.println(out + " is the factorial of " + a);
	}
}