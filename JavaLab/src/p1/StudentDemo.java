import java.io.*;
import java.util.*;

class Student{
    private int s_no,maxMarks,minMarks,avgMarks;
    private String usn,name;
    private int marks[] = new int[3];
    public Student(){}

    public void displayData(){
        System.out.println("USN: "+usn+"\nSerial No: "+s_no
            +"\nName: "+name);
        System.out.println("Marks in 3 subjects:");
        for (int i=0; i < marks.length ; i++ ) {
            System.out.println("Subject "+i+" = "+marks[i]);
        }

        calcMarks();

        System.out.println("Avg Marks: "+avgMarks+"\nMax marks: "
            +maxMarks+"\nMin marks: "+minMarks);
    }

    public void setData(){
        Scanner reader = new Scanner(System.in);
        System.out.println("Enter Serial number");
        s_no = reader.nextInt();
        System.out.println("Enter student USN");
        usn = reader.next();
        System.out.println("Enter student Name");
        name = reader.next();
        System.out.println("Enter marks in 3 subjects");
        for ( int i=0 ; i < marks.length ; i++ ) {
            System.out.println("Subject "+(i+1));
            marks[i]=reader.nextInt();
        }

    }

    public void calcMarks(){

        maxMarks=marks[0];
        minMarks=marks[0];
        for (int i=0; i < marks.length ; i++ ){
            avgMarks += marks[i];
            if (marks[i] >= maxMarks)
                maxMarks=marks[i];
            if (marks[i] <= minMarks)
                minMarks=marks[i];
        }
        avgMarks=avgMarks/marks.length;
    }
}

class StudentDemo{
    public static void main(String[] args) {
        Student obj[] = new Student[3];
        for ( int i = 0 ; i < obj.length ; i++ ) {
            obj[i] = new Student();
            System.out.println("Enter details of student "+(i+1));
            obj[i].setData();
            System.out.println("\n\nStudent "+(i+1)+"\n\n");
            obj[i].displayData();
        }
    }
}