package chsu.oakrinkin.types;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Random;

import static java.nio.file.StandardOpenOption.*;

public class BinaryFile {

    Path path;

    public BinaryFile(Path path) {
        this.path = path;
    }

    public void generateFile(int size) {
        try (OutputStream out = new BufferedOutputStream(Files.newOutputStream(this.path, CREATE, WRITE))) {
            for (int i = 0; i < size; i++) {
                Random random = new Random();
                int number = random.nextInt(10000);
                out.write(number);
            }
        } catch (IOException x) {
            System.err.println(x);
        }
    }

    public void readFile() {
        try (InputStream in = Files.newInputStream(this.path);
             BufferedReader reader = new BufferedReader(new InputStreamReader(in))) {
            int number = -1;
            while ((number = reader.read()) != -1) {
                System.out.println(number);
            }
        } catch (IOException x) {
            System.err.println(x);
        }
    }
}
