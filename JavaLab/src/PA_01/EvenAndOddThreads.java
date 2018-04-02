package PA_01;

class Even implements Runnable {
    @Override
    public void run() {
        for (int i = 0; i < 50; i += 2) {
            System.out.println("Even Thread: " + i);

        }
    }
}

class Odd implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i < 50; i += 2) {
            System.out.println("Odd Thread: " + i);

        }
    }
}

public class EvenAndOddThreads {
    public static void main(String[] args) {
        Even obj1 = new Even();
        Odd obj2 = new Odd();
        Thread t1 = new Thread(obj1);
        Thread t2 = new Thread(obj2);
        t2.start();
        t1.start();
    }

}
