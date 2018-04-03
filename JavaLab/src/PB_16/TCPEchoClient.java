package PB_16;

import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class TCPEchoClient {
    private static final int PORT = 1235;
    private static InetAddress host;

    public static void main(String[] args) throws Exception {
        try {
            host = InetAddress.getLocalHost();
        } catch (UnknownHostException uhEx) {
            System.out.println("Host ID not found!");
            System.exit(1);
        }
        accessServer();
    }

    private static void accessServer() throws Exception {
        Socket link = null; //Step 1.

        link = new Socket(host, PORT); //Step 1.
        Scanner input = new Scanner(link.getInputStream()); //Step 2.
        PrintWriter output = new PrintWriter(link.getOutputStream(), true); //Step 2.
        //Set up stream for keyboard entry...
        Scanner userEntry = new Scanner(System.in);
        String message, response;
        do {
            System.out.print("Enter message: ");
            message = userEntry.nextLine();
            output.println(message); //Step 3.
            response = input.nextLine(); //Step 3.
            System.out.println("\nSERVER> " + response);
        } while (!message.equals("***CLOSE***"));

        link.close(); //Step 4.

    }
}