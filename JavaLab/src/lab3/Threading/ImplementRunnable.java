package lab3.Threading;
//ALWAYS OVERRIDE RUN AS RUNNABLE IS ABSTRACT
public class ImplementRunnable implements Runnable{

	public void run(){
		try{
			for (int i = 0; i < 50; i+=2){
				System.out.println("\t\tEven value: "+i);
				Thread.sleep(100);
			}
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
		System.out.println("Sub thread ends");
	}
	
}
