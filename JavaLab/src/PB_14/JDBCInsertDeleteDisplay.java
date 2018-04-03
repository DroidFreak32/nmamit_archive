package PB_14;

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
        String s = "SELECT * FROM sanacc";
        rs = stm.executeQuery(s);
        while (rs.next()) {
            System.out.println(rs.getInt(1) + "\t" + rs.getString(
                    2) + "\t" + rs.getString(3) + "\t" + rs.getFloat(4));
        }
    }

    void insertinfo() throws SQLException {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the account number");
        int accno = s.nextInt();
        System.out.println("Enter surname");
        String sn = s.next();
        System.out.println("Enter firstname");
        String fn = s.next();
        System.out.println("Enter balance");
        float bn = s.nextFloat();
        String sq = "INSERT INTO sanacc VALUES(" + accno + ",'" + sn + "','" + fn + "'," + bn + ")";
        int r = stm.executeUpdate(sq);
        System.out.println(r + " Row updated successfully "
        );
    }

    void createTable() throws SQLException {
        String sq = "create table sanacc( accno integer, surname varchar(15), firstname varchar(15), balance integer )";
        int r = stm.executeUpdate(sq);
        System.out.println("Table created successfully.");
    }

    void closecon() throws SQLException {
        rs.close();
        stm.close();
        con.close();
    }
}

public class JDBCInsertDeleteDisplay {

    public static void main(String[] args) throws SQLException {
        boolean f = true;
        dbdemo d = new dbdemo();
        Scanner s = new Scanner(System.in);
        int ch;
        do {
            System.out.println("1.Create Table\n2.Display\n3.Insert\n4.Exit\nEnter your Choice");
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
                    f = false;
                    break;
                default:
                    System.out.println("Invalid choice.");
            }
        } while (f);
        d.closecon();
    }
}