package lab5.File;

import java.io.*;

public class CopyToNewFile {
	public static void main(String args[]) throws IOException{
		int i;
		FileInputStream fin,fin2;
		FileOutputStream fout;
		try {
			fin = new FileInputStream(args[0]);
			fin2 = new FileInputStream(args[1]);
			fout = new FileOutputStream(args[2]);
		} catch (FileNotFoundException e) {
			System.out.println("File Not Found");
			return;
		} catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Usage: ShowFile File DestFile");
			return;
		}
		do{
			i = fin.read();
			if (i != -1)
				fout.write(i);
		} while( i != -1);
		do{
			i = fin2.read();
			if (i != -1)
				fout.write(i);
		} while( i != -1);
		
		
		fin.close();
		fin2.close();
		fout.close();
	}

}
