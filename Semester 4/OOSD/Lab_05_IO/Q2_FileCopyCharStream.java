import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Q2_FileCopyCharStream {
    public static void main(String[] args) {
        String source = "mytextfile.txt";
        String dest = "destination2.txt";

        try (FileReader fr = new FileReader(source);
             FileWriter fw = new FileWriter(dest)) {

            int charData;
            while ((charData = fr.read()) != -1) {
                fw.write(charData);
            }

            System.out.println("File copied successfully using character streams.");
        } catch (IOException e) {
            System.out.println("Error occurred: " + e.getMessage());
        }
    }
}
