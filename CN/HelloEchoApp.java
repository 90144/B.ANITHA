import java.net.*;
import java.util.Scanner;

public class HelloEchoApp {

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Select mode: [1] Server, [2] Client");
        int choice = scanner.nextInt();
        scanner.nextLine(); // consume newline

        if (choice == 1) {
            runServer();
        } else if (choice == 2) {
            runClient(scanner);
        } else {
            System.out.println("Invalid choice.");
        }

        scanner.close();
    }

    // Server mode
    public static void runServer() throws Exception {
        DatagramSocket socket = new DatagramSocket(9876);
        byte[] buffer = new byte[1024];
        System.out.println("Server is running and waiting for packets...");

        while (true) {
            DatagramPacket requestPacket = new DatagramPacket(buffer, buffer.length);
            socket.receive(requestPacket);

            String received = new String(requestPacket.getData(), 0, requestPacket.getLength());
            InetAddress clientAddress = requestPacket.getAddress();
            int clientPort = requestPacket.getPort();

            String response;
            if (received.equalsIgnoreCase("HELLO")) {
                response = "ALIVE";
                System.out.println("Received HELLO from " + clientAddress);
            } else if (received.startsWith("ECHO")) {
                response = received;
                System.out.println("Received ECHO from " + clientAddress);
            } else {
                response = "UNKNOWN COMMAND";
            }

            byte[] sendData = response.getBytes();
            DatagramPacket responsePacket = new DatagramPacket(sendData, sendData.length, clientAddress, clientPort);
            socket.send(responsePacket);
        }
    }

    // Client mode
    public static void runClient(Scanner scanner) throws Exception {
        DatagramSocket socket = new DatagramSocket();
        InetAddress serverAddress = InetAddress.getByName("localhost");
        int serverPort = 9876;

        while (true) {
            System.out.println("\nChoose command: [1] HELLO, [2] ECHO, [3] Exit");
            int cmd = scanner.nextInt();
            scanner.nextLine(); // consume newline

            String message;
            if (cmd == 1) {
                message = "HELLO";
            } else if (cmd == 2) {
                System.out.print("Enter message to echo: ");
                String msg = scanner.nextLine();
                message = "ECHO " + msg;
            } else {
                System.out.println("Exiting...");
                socket.close();
                return;
            }

            byte[] send = message.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(send, send.length, serverAddress, serverPort);

            long startTime = System.nanoTime();
            socket.send(sendPacket);

            byte[] receive = new byte[1024];
            DatagramPacket receivePacket = new DatagramPacket(receive, receive.length);
            socket.receive(receivePacket);
            long endTime = System.nanoTime();

            String reply = new String(receivePacket.getData(), 0, receivePacket.getLength());
            double rtt = (endTime - startTime) / 1e6;

            System.out.println("Server Response: " + reply);
            if (message.startsWith("ECHO")) {
                System.out.printf("Round Trip Time: %.2f ms%n", rtt);
            }
        }
    }
}
