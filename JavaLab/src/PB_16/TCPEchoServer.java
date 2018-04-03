package PB_16;

import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class TCPEchoServer {
    private static final int PORT = 1235;
    private static ServerSocket servSock;

    public static void main(String[] args) throws Exception {
        System.out.println("Opening port...\n");

        servSock = new ServerSocket(PORT); //Step 1.
        System.out.println(servSock.getLocalSocketAddress());

        do {
            handleClient();
        } while (true);
    }

    private static void handleClient() throws Exception {
        Socket link = null; //Step 2.

        link = servSock.accept(); //Step 2.
        Scanner input = new Scanner(link.getInputStream());//Step 3.
        PrintWriter output = new PrintWriter(link.getOutputStream(), true); //Step 3.
        int numMessages = 0;
        String msg = "TEST";
        String message = input.nextLine(); //Step 4.
        Scanner reader = new Scanner(System.in);
        msg = reader.nextLine();
        while (!message.equals("***CLOSE***")) {
            System.out.println("Message received.: " + message);
            numMessages++;
            msg = reader.nextLine();
            output.println("Message " + numMessages + ": " + msg); //Step 4.
            message = input.nextLine();
        }
        output.println(numMessages + " messages received.");//Step 4.

        link.close(); //Step 5.
    }

}