package lab3.Threading;

public class ImplementRunnableDemo {
	public static void main(String[] args){
		ImplementRunnable obj = new ImplementRunnable();
		Thread tr = new Thread(obj,"Even");
		tr.start();
		try{
			for (int i = 1; i < 50; i+=2){
				System.out.println("Odd value: "+i);
				Thread.sleep(100);
			}
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println("Main thread ends");
	}
}
