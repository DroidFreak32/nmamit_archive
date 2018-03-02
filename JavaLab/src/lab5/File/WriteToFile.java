package lab5.File;

import java.io.*;

public class WriteToFile {
	public static void main(String args[]){
		File file = new File(args[0]);
		System.out.println(args[0]);
		try {
			PrintWriter writer = new PrintWriter(file);
			writer.println("Writing into file");
			writer.println("Writing2 into file");
			writer.close();
			writer = new PrintWriter(file);
			writer.println("Writing into file");
			writer.println("Writisng2 into file");
			writer.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
