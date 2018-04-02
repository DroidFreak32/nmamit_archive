package PA_08;

class MyThread extends Thread {
    private String temp, leftmarker, rightmarker;

    public MyThread(String t, String l, String r) {
        temp = t;
        leftmarker = l;
        rightmarker = r;
    }

    // Remove "synchronized" to see difference
    synchronized public static void display(String temp, String leftmarker, String rightmarker) {
        System.out.print(leftmarker);
        try {
            Thread.sleep(100);
        } catch (Exception e) {
            System.out.println("Exception Ocuured " + e);
        }
        System.out.print(temp);
        System.out.println(rightmarker);
    }

    public void run() {
        display(temp, leftmarker, rightmarker);
    }
}

public class SynchronizedThread {
    public static void main(String args[]) {
        MyThread t1 = new MyThread("NMAMIT", "\"", "\"");
        MyThread t2 = new MyThread("Nitte", "[", "]");
        MyThread t3 = new MyThread("Autonomous Institue",
                "(", ")");
        MyThread t4 = new MyThread("Karkala", "{", "}");
        try {
            t1.start();
            t2.start();
            t3.start();
            t4.start();
        } catch (Exception e) {
            System.out.println("Exception Ocuured ");
        }
    }
}