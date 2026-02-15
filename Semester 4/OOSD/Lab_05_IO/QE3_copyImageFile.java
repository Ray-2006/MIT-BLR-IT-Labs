import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class QE3_copyImageFile {
    public static void main(String[] args) {
        String sourcePath = "input.jpg";
        String destPath = "output.jpg";

        try (FileInputStream fis = new FileInputStream(sourcePath);
             FileOutputStream fos = new FileOutputStream(destPath)) {

            byte[] buffer = new byte[4096];
            int bytesRead;

            while ((bytesRead = fis.read(buffer)) != -1) {
                fos.write(buffer, 0, bytesRead);
            }

            System.out.println("Image copied successfully.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
