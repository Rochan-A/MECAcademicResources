class prime{

	public static void main(String[] args){
		int a = 34;
		int st = 0;

		for(int i = 2; i < a; i++){
			for(int j = 2; j < i; j++){
				if(i%j == 0){
					st = 1;
					break;
				}
			}
			if(st == 0){
				System.out.println(i + " is a prime number");
			}else{
				System.out.println(i + " is not prime number");
			}
			st = 0;
		}
	}
}