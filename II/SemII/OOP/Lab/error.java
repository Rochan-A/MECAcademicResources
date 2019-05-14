class MyException extends Exception{
	String str1;
	MyException(String str2) {
		str1=str2;
	}
	public String toString(){
		return ("MyException Occurred: "+str1) ;
	}
}

class ExcepTest {

	public static void main(String args[]) {
		int a[] = new int[2];
		try {
			System.out.println("Access element three :" + a[3]);
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("Exception thrown  :" + e);
		}finally {
			a[0] = 6;
			System.out.println("First element value: " + a[0]);
			System.out.println("The finally statement is executed");
		}
		try{
			throw new MyException("This is My error Message");
		}catch(MyException exp){
			System.out.println("Catch Block") ;
			System.out.println(exp) ;
		}
	}
}