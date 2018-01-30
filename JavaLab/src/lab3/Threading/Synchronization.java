package lab3.Threading;

//This program is not synchronized.
class Callme
{
//unsynched
//static void call(String msg) {

//synchronized
synchronized static void call(String msg) {
     System.out.print("[" + msg);
     try {
       Thread.sleep(500);
     } 
     catch(InterruptedException e) {
     System.out.println("Interrupted");
     }
     System.out.println("]");
}
}
class Caller extends Thread 
{
String msg;
//Callme target;
//Thread t;
 public Caller(String s) {
 //target = targ;
  msg = s;
 //t = new Thread(this);
 //t.start();
 }
 public void run() 
 {
   Callme.call(msg);
 }
}
class Synchronization
{
 public static void main(String args[]) {

 Caller ob1 = new Caller("Hello");
 Caller ob2 = new Caller("Synchronized");
 Caller ob3 = new Caller("World");
 ob1.start();
 ob2.start();
 ob3.start();
 // wait for threads to end
         try {
         ob1.join();
         ob2.join();
         ob3.join();
         } catch(InterruptedException e) {
         System.out.println("Interrupted");
         }
 }
}