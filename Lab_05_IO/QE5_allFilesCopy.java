import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class QE5_allFilesCopy {

    public static void main(String[] args) {

        String sourceDirPath = "folder_to_copy";
        String destDirPath = "output_folder";

        File sourceDir = new File(sourceDirPath);
        File destDir = new File(destDirPath);

        if (!destDir.exists()) {
            destDir.mkdir();
        }

        File[] files = sourceDir.listFiles();

        if (files == null) {
            System.out.println("Invalid source directory.");
            return;
        }

        byte[] buffer = new byte[4096];

        for (File file : files) {

            if (file.isFile()) {

                File destFile = new File(destDir, file.getName());

                try (FileInputStream fis = new FileInputStream(file);
                     FileOutputStream fos = new FileOutputStream(destFile)) {

                    int bytesRead;
                    while ((bytesRead = fis.read(buffer)) != -1) {
                        fos.write(buffer, 0, bytesRead);
                    }

                    System.out.println("Copied: " + file.getName());

                } catch (IOException e) {
                    System.out.println("Error copying " + file.getName());
                    e.printStackTrace();
                }
            }
        }

        System.out.println("Copy operation completed.");
    }
}
