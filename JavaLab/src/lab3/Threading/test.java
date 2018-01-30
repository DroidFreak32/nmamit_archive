package lab3.Threading;
//Create a second thread.
class NwThread implements Runnable 
{
//Thread t;
NwThread() 
{
}
//This is the entry point for the second thread.
public void run() {
try {
 for(int i = 5; i > 0; i--) {
 System.out.println("Child Thread: " + i);
 Thread.sleep(500);
}
} catch (InterruptedException e) {
System.out.println("Child interrupted.");
}
System.out.println("Exiting child thread.");
}
}
class test 
{
  public static void main(String args[]) {
  NwThread tr = new NwThread(); // create a new thread
  Thread t = new Thread(tr,"Demo Thread");
  t.start();
  try {
  for(int i = 5; i > 0; i--) {
  System.out.println("Main Thread: " + i);
  Thread.sleep(1000);
 }
 } catch (InterruptedException e) {
 System.out.println("Main thread interrupted.");
  }
 System.out.println("Main thread exiting.");
 }
}