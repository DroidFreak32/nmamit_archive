package PA_05;

import PA_05.studentpackage.Student;

import java.util.Scanner;

public class StudentSorted {

    public static void main(String args[]) {
        int n;
        System.out.println("enter the no of students");
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        Student ob[] = new Student[n];
        try {
            for (int i = 0; i < n; i++) {
                ob[i] = new Student();
                ob[i].read();
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e.toString());
        }
        Student temp;                   // Like sorting array, instead of having a temp variable, we have a temp object

        // Bubble sort
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (ob[j].roll > ob[j + 1].roll) {
                    temp = ob[j];
                    ob[j] = ob[j + 1];
                    ob[j + 1] = temp;
                }
            }
        }
        System.out.println("sorted list is");
        for (int i = 0; i < n; i++) {
            ob[i].display();
        }
    }
} 