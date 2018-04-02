package PA_05.studentpackage;

import java.util.Scanner;

public class Student {
    public String name;
    public int roll;

    public void read() {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter a name");
        name = sc.nextLine();
        System.out.println("enter the roll");
        roll = sc.nextInt();
    }

    public void display() {
        System.out.println("name:" + name + " rollno:" + roll);
    }
}