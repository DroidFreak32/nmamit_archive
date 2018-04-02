package PA_06;

import java.util.Scanner;

class Person {
    String name;
    int age;
    String gender;
}

class Employee extends Person {
    Scanner d = new Scanner(System.in);
    int code;

    void set_e() {

        String s1, s2;
        System.out.println("\nENTER NAME ");
        name = d.nextLine();
        System.out.println("ENTER AGE ");
        s1 = d.nextLine();
        age = Integer.parseInt(s1);
        System.out.println("ENTER GENDER ");
        gender = d.nextLine();
        System.out.println("ENTER CODE ");
        s2 = d.nextLine();
        code = Integer.parseInt(s2);
    }

    void disp_e() {
        System.out.println("NAME :" + this.name);
        System.out.println("AGE :" + this.age);
        System.out.println("GENDER :" + this.gender);
        System.out.println("CODE " + this.code);
    }
}

class Specialist extends Employee {
    Scanner d = new Scanner(System.in);

    void set_s() {
        String s1, s2;
        System.out.println("\nENTER NAME ");
        name = d.nextLine();
        System.out.println("ENTER AGE ");
        s1 = d.nextLine();
        age = Integer.parseInt(s1);
        System.out.println("ENTER GENDER ");
        gender = d.nextLine();
        System.out.println("ENTER CODE ");
        s2 = d.nextLine();
        code = Integer.parseInt(s2);
    }

    void disp_s() {
        System.out.println("NAME :" + this.name);
        System.out.println("AGE :" + this.age);
        System.out.println("GENDER :" + this.gender);
        System.out.println("CODE " + this.code);
    }
}

public class EmployeePersonSpecialistDemo {
    public static void main(String args[]) {
        int i;
        Employee e[] = new Employee[3];
        Specialist s[] = new Specialist[3];
        for (i = 0; i < 3; i++) {
            e[i] = new Employee();
            System.out.println("ENTER EMPLOYEE DETAILS\n");
            e[i].set_e();
        }
        for (i = 0; i < 3; i++) {
            s[i] = new Specialist();
            System.out.println("ENTER SPECIALIST DETAILS\n")
            ;
            s[i].set_s();
        }
        for (i = 0; i < 3; i++) {
            System.out.println("");
            System.out.println("\n EMPLOYEE " + (i + 1) + " DETAILS\n");
            e[i].disp_e();
        }
        for (i = 0; i < 3; i++) {
            System.out.println("");
            System.out.println("SPECIALIST " + (i + 1) + " DETAILS\n");
            s[i].disp_s();
        }
    }
}