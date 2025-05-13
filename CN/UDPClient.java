import java.net.*;
import java.util.Scanner;

public class UDPClient {
    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket();
        InetAddress serverIP = InetAddress.getByName("localhost");

        Scanner sc = new Scanner(System.in);
        byte[] send;
        byte[] receive = new byte[1024];

        while (true) {
            System.out.print("Client: ");
            String msg = sc.nextLine();
            send = msg.getBytes();

            DatagramPacket sendPacket = new DatagramPacket(send, send.length, serverIP, 9876);
            socket.send(sendPacket);

            DatagramPacket receivePacket = new DatagramPacket(receive, receive.length);
            socket.receive(receivePacket);

            String serverReply = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("Server: " + serverReply);
        }
    }
}
