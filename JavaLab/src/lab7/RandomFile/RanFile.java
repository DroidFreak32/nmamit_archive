package lab7.RandomFile;
import java.io.*;
import java.util.*;

public class RanFile
{
    private static final int REC_SIZE = 42;
    private static final int NAME_SIZE = 15;
    private static RandomAccessFile ranAccts;

    public static void main(String[] args) throws IOException
    {
        ranAccts = new RandomAccessFile("accounts.dat", "rw");

        writeRecord(1000,"Rohit",50000); //Method defined below.
        writeRecord(1001,"Virat",60000);
        writeRecord(1002,"Dhoni",70000);
        showRecords(); //Method defined below.
    }

    public static void writeRecord(long accnum,String name,float balance) throws IOException
    {
        //First find starting byte for current record...
        //long filePos = (acctNum-1) * REC_SIZE;
        long filePos = ranAccts.length();
        //Position file pointer...
        ranAccts.seek(filePos);
        //Now write the four (fixed-size) fields.
        //Note that a definition must be provided
        //for method writeString...
        ranAccts.writeLong(accnum);
        writeString(name, NAME_SIZE);
        ranAccts.writeFloat(balance);
    }
    public static void writeString(String text, int fixedSize) throws IOException
    {
        int size = text.length();
        if (size<=fixedSize)
        {
            ranAccts.writeChars(text);
            //Now 'pad out' the field with spaces...
            for (int i=size; i<fixedSize; i++)
                ranAccts.writeChar(' ');
        }
        else //String is too long!
            ranAccts.writeChars(text.substring(0,fixedSize));
        //Write to file the first fixedSize characters of
        //string text, starting at byte zero.
    }
    public static void showRecords() throws IOException
    {
        long numRecords = ranAccts.length()/REC_SIZE;
        ranAccts.seek(0); //Go to start of file.
        for (int i=0; i<numRecords; i++)
        {
            long acctNum = ranAccts.readLong();
            String name = readString(NAME_SIZE);
            float balance = ranAccts.readFloat();
            System.out.printf("" + acctNum + " " + name +  " " + "%.2f %n",balance);
        }
    }
    public static String readString(int fixedSize) throws IOException
    {
        String value = ""; //Set up empty string.
        for (int i=0; i<fixedSize; i++)
            //Read character and concatenate it onto value...
            value+=ranAccts.readChar();
        return value;
    }
}