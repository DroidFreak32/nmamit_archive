package lab7.JDBCMods;

import java.sql.*;
public class JDBCMods
{

    public static void main(String[] args) throws Exception
    {
        Connection link = null;
        Statement statement = null;
        ResultSet results = null;

        Class.forName("com.mysql.jdbc.Driver");
        //Step 2...
        link=DriverManager.getConnection("jdbc:mysql://127.0.0.1/exam","root","password");//step2

        //Step 3...
        statement = link.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,
                ResultSet.CONCUR_UPDATABLE);
        String select = "SELECT * FROM Accounts";
        results = statement.executeQuery(select);
        //First the update...
        results.absolute(2);//(Move to row 2 of ResultSet.)
        results.updateFloat("balance", 42.55f);
        results.updateRow();
        //Now the insertion...
        results.moveToInsertRow();
        results.updateInt("acctNum", 999999);
        results.updateString("fname", "Harrison");
        results.updateString("lname","Christine Dawn");
        results.updateFloat("balance", 2500f);
        results.insertRow();
        //Finally, the deletion...
        results.absolute(3); //Move to row 3.
        results.deleteRow();
        //End of step 6.
        //Step 7...
        link.close();
    }

}