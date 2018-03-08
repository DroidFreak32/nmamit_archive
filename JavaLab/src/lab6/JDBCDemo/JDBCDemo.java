package lab6.JDBCDemo;

import com.mysql.jdbc.exceptions.jdbc4.MySQLIntegrityConstraintViolationException;

import java.sql.*;
import java.io.*;
import java.util.*;

class JDBCDemo
{
	public static void main(String  args[]) throws SQLException
	{
		Connection link=null;
		Statement stmt = null;
		ResultSet results=null;
		ResultSetMetaData meta = null;
		try
		{
			Class.forName("com.mysql.jdbc.Driver");//step1
			link=DriverManager.getConnection("jdbc:mysql://127.0.0.1/exam","root","password");//step2
		}
		catch(ClassNotFoundException ex)
		{
			System.out.println("unable to load driver");
			System.exit(1);
		}
		stmt=link.createStatement();//step3
		String insert;
		try {
            insert = "INSERT INTO Student VALUES('4NM15CS100','dia')";

            stmt.executeUpdate(insert);
            insert = "INSERT INTO Student VALUES('4NM15CS101','mia')";
            stmt.executeUpdate(insert);
            insert = "INSERT INTO Student VALUES('4NM15CS102','sia')";
            stmt.executeUpdate(insert);
            insert = "INSERT INTO Student VALUES('4NM15CS103','pia')";
            stmt.executeUpdate(insert);
        } catch (MySQLIntegrityConstraintViolationException e){
		    System.out.println("Primary Key Duplication");
        }
		Scanner reader=new Scanner(System.in);
		System.out.println("enter usn");
		String s=reader.next();
		String query="SELECT * FROM Student WHERE USN='"+s+"'";
		results=stmt.executeQuery(query);
		while(results.next()){
			System.out.println("USN="+results.getString("USN"));
			System.out.println("NAME="+results.getString("NAME"));
		}
		meta = results.getMetaData();
		System.out.println("Metadata: \n" +
                "Number of Columns: "+meta.getColumnCount());
        for (int i = 0; i < meta.getColumnCount(); i++) {
            System.out.println("Column "+i+" Name: "+ meta.getColumnName(i+1));
            System.out.println("Column "+i+" Type: "+ meta.getColumnTypeName(i+1));

        }
        query = "UPDATE Student SET NAME='Pia' WHERE USN='4NM15CS103'";
        stmt.executeUpdate(query);
        System.out.println("Updated Table:");
        query = "SELECT * FROM Student";
        results=stmt.executeQuery(query);
        while(results.next()){
            System.out.println("USN="+results.getString("USN"));
            System.out.println("NAME="+results.getString("NAME"));
        }
		link.close();
	}
}
