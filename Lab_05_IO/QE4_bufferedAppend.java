import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class QE4_bufferedAppend {
    public static void main(String[] args) {

        String source = "mytextfile.txt";
        String target = "output.txt";

        try (
            BufferedReader br = new BufferedReader(new FileReader(source));
            BufferedWriter bw = new BufferedWriter(new FileWriter(target, true))
        ) {
            String line;

            while ((line = br.readLine()) != null) {
                bw.write(line);
                bw.newLine();
            }

            System.out.println("Content appended successfully.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
