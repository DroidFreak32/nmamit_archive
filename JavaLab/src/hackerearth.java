import java.util.Scanner;

class InvalidSpeedException extends Exception {

    public InvalidSpeedException(String message){
        super(message);
    }

}
public class hackerearth {


    short t;
    int n,k,m,nextRefill, count[];
    int c[];
    Scanner reader = new Scanner(System.in);

    public static void main(String[] args) {
        hackerearth o = new hackerearth();

        try {
            o.start();
        } catch (InvalidSpeedException e) {
            System.out.println(e.toString());
            e.printStackTrace();
        }

    }

    private void start() throws InvalidSpeedException {
        if( reader.hasNextShort() )
        { t = reader.nextShort();
            if (t < 1)
                return;
        }
        count = new int[t+1];
        for (int i = 0; i <= t; i++) {
            int refill = 0;
            if( reader.hasNextInt() ){
                n = reader.nextInt();
                if (n < 1)
                    return;}
            if( reader.hasNextInt() ){
                k = reader.nextInt();
                if (k < 1)
                    return;
            }
            if( reader.hasNextInt() ){
                m = reader.nextInt();
                if (m < 0 || m > n)
                    return;}
            c = new int[m];
            for (int j = 0; j < m; j++) {
                if( reader.hasNextInt() ){
                    c[j] = reader.nextInt();
                    if (c[j] <1 || c[j] > n)
                        return ;
                }
            }
            nextRefill = k;
            for (int j = 0; j < n; j++) {
                if ((j+1) == nextRefill) {
                    refill++;
                    nextRefill = j+k+1;
                }
                else if (checkpoint(j+1)) {
                    refill++;
                    nextRefill = j+1+k;
                }
            }
            count[i] = refill;

        }
        for (int i = 0; i <= t; i++) {
            System.out.println(count[i]);

        }
//        throw new InvalidSpeedException("The exception  count t n k m  "+t+" "+n+" "+k+" "+m+" ");
    }
    private boolean checkpoint(int j) {
        for (int i = 0; i < c.length; i++) {
            if (c[i] == j) {
                return true;
            }


        }
        return false;
    }
}
