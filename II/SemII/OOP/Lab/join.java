class MyThread extends Thread{
	String s;

	MyThread(String a){
		s = a;
	}

	public void run(){
		System.out.println("New Thread");
		int i;
		for(i = 0; i < 20; i++){
			System.out.println(s);
		}
	}
}

class join{
	public static void main(String args[]){
		MyThread mt = new MyThread("hellos");
		System.out.println("Main Thread");
		mt.start();
		try{
			System.out.println(mt.isAlive());
			mt.join();
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println(mt.isAlive());
	}
}