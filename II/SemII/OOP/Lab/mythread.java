class MyThread extends Thread{
	String s;

	MyThread(String a){
		s = a;
	}

	public void run(){
		System.out.println("New Thread");
		System.out.println(s);
	}
}

class MyThread2 extends Thread{
	String s;

	MyThread2(String a){
		s = a;
	}

	public void run(){
		System.out.println("New Thread 2");
		System.out.println(s);
	}
}

class threadp{
	public static void main(String args[]){
		MyThread mt = new MyThread("hellos");
		MyThread2 mt2 = new MyThread2("heyo");
		System.out.println("Main Thread");
		mt.start();
		mt2.start();
	}
}