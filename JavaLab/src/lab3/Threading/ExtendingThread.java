package lab3.Threading;
// NEVER CALL RUN() 
public class ExtendingThread extends Thread{
	public void run(){
		try{
			for (int i=0; i< 5; i++){
				System.out.println("Value: "+i);
				Thread.sleep(1000);
			}
			System.out.println("Sub Thread end");
		}
		catch(InterruptedException e){
			System.out.println(e);
		}
	}
}
