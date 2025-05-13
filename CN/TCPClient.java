import java.io.*;
import java.net.*;

public class TCPClient {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket("localhost", 1234);

        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

        String userMsg;
        while (true) {
            System.out.print("Client: ");
            userMsg = userInput.readLine();
            out.println(userMsg);
            System.out.println("Server: " + in.readLine());
        }
    }
}
