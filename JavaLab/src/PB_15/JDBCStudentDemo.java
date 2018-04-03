package PB_15;

import java.sql.*;
import java.util.Scanner;

class dbdemo {
    static Connection con;
    static Statement stm;
    static ResultSet rs;

    dbdemo() throws SQLException {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://127.0.0.1/exam", "root", "password");
        } catch (ClassNotFoundException e) {
            System.out.println("Unable to load the driver.")
            ;
        } catch (SQLException e) {
            System.out.println("Connection not established."
            );
        }
        stm = con.createStatement();
    }

    void displayinfo() throws SQLException {
        String s = "SELECT * FROM student";
        rs = stm.executeQuery(s);
        while (rs.next()) {
            System.out.println(rs.getInt(1) + "\t" + rs.getString(2));
        }
    }

    void insertinfo() throws SQLException {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the USN");
        int usn = s.nextInt();
        System.out.println("Enter name");
        String name = s.next();
        String sq = "INSERT INTO student VALUES(" + usn + ",'" + name + "')";
        int r = stm.executeUpdate(sq);
        System.out.println(r + " Row updated successfully "
        );
    }

    void createTable() throws SQLException {
        String sq = "create table student( USN integer, name varchar(15));";
        int r = stm.executeUpdate(sq);
        System.out.println("Table created successfully.");
    }

    void searchtable() throws SQLException {
        System.out.println("Enter the USN");
        Scanner s = new Scanner(System.in);
        int usn = s.nextInt();
        String a = "SELECT * FROM student where USN=" + usn;
        rs = stm.executeQuery(a);
        if(rs.next()) {
            System.out.println("Student name is " + rs.getString(2));
        }
    }

    void closecon() throws SQLException {
        rs.close();
        stm.close();
        con.close();
    }
}

public class JDBCStudentDemo {
    public static void main(String[] args) throws SQLException {
        boolean f = true;
        dbdemo d = new dbdemo();
        Scanner s = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1.Create Table\n2.Display\n3.Insert\n4.Search\n5.Exit\nEnter your Choice");
            ch = s.nextInt();
            switch (ch) {
                case 1:
                    d.createTable();
                    break;
                case 2:
                    d.displayinfo();
                    break;
                case 3:
                    d.insertinfo();
                    break;
                case 4:
                    d.searchtable();
                    break;
                case 5:
                    f = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        } while (f);
        d.closecon();
    }
}