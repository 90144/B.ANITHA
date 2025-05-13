import java.net.*;

public class UDPServer {
    public static void main(String[] args) throws Exception {
        DatagramSocket socket = new DatagramSocket(9876);
        byte[] receive = new byte[1024];
        byte[] send;

        System.out.println("UDP Server running...");

        while (true) {
            DatagramPacket packet = new DatagramPacket(receive, receive.length);
            socket.receive(packet);

            String clientMsg = new String(packet.getData(), 0, packet.getLength());
            System.out.println("Client: " + clientMsg);

            String reply = "Echo: " + clientMsg;
            send = reply.getBytes();

            InetAddress clientAddress = packet.getAddress();
            int clientPort = packet.getPort();

            DatagramPacket sendPacket = new DatagramPacket(send, send.length, clientAddress, clientPort);
            socket.send(sendPacket);
        }
    }
}
