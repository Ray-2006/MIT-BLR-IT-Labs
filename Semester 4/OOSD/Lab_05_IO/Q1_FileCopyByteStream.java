import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class Q1_FileCopyByteStream {
    public static void main(String[] args) {
        String source = "mytextfile.txt";
        String dest = "destination.txt";

        try (FileInputStream fis = new FileInputStream(source);
             FileOutputStream fos = new FileOutputStream(dest)) {

            int byteData;
            while ((byteData = fis.read()) != -1) {
                fos.write(byteData);
            }

            System.out.println("File copied successfully using byte streams.");
        } catch (IOException e) {
            System.out.println("Error occurred: " + e.getMessage());
        }
    }
}
