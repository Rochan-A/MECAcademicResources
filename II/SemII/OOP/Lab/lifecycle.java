class MyThread extends Thread{
	String s;

	MyThread(String a){
		s = a;
	}

	public void run(){
		System.out.println("New Thread");
		int i;
		for(i = 0; i < 10; i++){
			System.out.println(s);
		}
	}
}

class life{
	public static void main(String args[]){
		MyThread mt = new MyThread("hellos");
		System.out.println("Main Thread");
		mt.start();
		try{
			Thread.sleep(1000);
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println(mt.getPriority());
		try{
			mt.wait();
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println(mt.getId());
		mt.notifyAll();
	}
}