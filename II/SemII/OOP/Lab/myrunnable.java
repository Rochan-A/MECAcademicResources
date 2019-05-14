class MyRunnable implements Runnable{
	String s;

	MyRunnable(String a){
		s = a;
	}

	public void run(){
		System.out.println("New Thread");
		System.out.println(s);
	}
}

class MyRunnable2 implements Runnable{
	String s;

	MyRunnable2(String a){
		s = a;
	}

	public void run(){
		System.out.println("New Thread 2");
		System.out.println(s);
	}
}

class runnablep{
	public static void main(String args[]){
		Thread mt = new Thread(new MyRunnable("Hellos"));
		Thread mt2 = new Thread(new MyRunnable2("Heyoo"));
		System.out.println("Main Thread");
		mt.start();
		mt2.start();
	}
}