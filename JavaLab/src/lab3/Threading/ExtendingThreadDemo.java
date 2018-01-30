package lab3.Threading;

public class ExtendingThreadDemo {
	public static void main(String[] args){
		ExtendingThread obj = new ExtendingThread();
		obj.start();
		try{
			for (int i=0; i< 5; i++){
				System.out.println("Main Value: "+i);
				Thread.sleep(400);
			}
			obj.join();
			System.out.println("Main Thread end");
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
	}
}
