package PB_11;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FileCopy {
    public static void main(String[] args) throws IOException {

        System.out.println("Working Directory where files should be present to run from eclipse = " +
                System.getProperty("user.dir"));
        PrintWriter p1 = new PrintWriter(new File("w.txt"));
        Scanner f1 = new Scanner(new File("a.txt"));
        Scanner f2 = new Scanner(new File("b.txt"));
        while (f1.hasNext()) {
            String s1 = f1.nextLine();
            p1.println(s1);
        }
        while (f2.hasNext()) {
            String s1 = f2.nextLine();
            p1.println(s1);
        }
        f1.close();
        f2.close();
        p1.close();
    }
}