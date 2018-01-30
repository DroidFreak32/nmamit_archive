package lab3.Threading;
//Create a second thread by extending Thread
class NewThread extends Thread 
{
private String name;
NewThread(String name) 
{// Create a new, second thread
  super(name);
  this.name = name;
  System.out.println("Child thread: " + this);
 //start(); // Start the thread
}
//This is the entry point for the second thread.
 public void run() 
 {
     try 
     {
         for(int i = 5; i > 0; i--) 
         {
             System.out.println(name + i);
             Thread.sleep(1000);
         }
     } 
     catch (InterruptedException e) 
     {
       System.out.println("Child interrupted.");
     }
     System.out.println("Exiting child thread." + name);
 }
}

class IsAliveAndJoin 
{
public static void main(String args[]) throws Exception
{
   Thread t1 = new NewThread("child thread One"); // create a new thread
   t1.start(); 
   //Thread t2 = new NewThread("child thread two"); // create a new thread
   //t2.start();
   //Thread t2 = new NewThread(); // create a new thread
   //t2.start();
   System.out.println("Is child thread one alive?:" + t1.isAlive());
   //t1.join();
   //t2.join();
   
    try {
         for(int i = 5; i > 0; i--) 
         {
         System.out.println("Main Thread: " + i);
         Thread.sleep(500);
         }
     } 
     catch (InterruptedException e) {
     System.out.println("Main thread interrupted.");
     }
   t1.join(); 
   System.out.println("Is child thread one alive?:" + t1.isAlive());
   System.out.println("Main thread exiting.");
 }
}
