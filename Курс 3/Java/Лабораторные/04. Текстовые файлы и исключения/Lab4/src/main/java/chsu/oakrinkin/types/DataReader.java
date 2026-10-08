package chsu.oakrinkin.types;

import org.jsoup.helper.ValidationException;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DataReader {

    private final File file;
    List<Product> dataList = new ArrayList<>();
    Map<String, Exception> errorMap = new HashMap<>();

    public DataReader(File file) {
        this.file = file;
    }

    public void Read() throws IOException {
        try (FileReader reader = new FileReader(file);) {
            BufferedReader buffer = new BufferedReader(reader);

            String line;
            while ((line = buffer.readLine()) != null) {
                try {
                    String[] columns = line.split(" ");
                    if (columns.length != 3) throw new ValidationException("File should contain 3 columns!");
                    if (columns[0].strip().length() > 20) throw new ValidationException("Max column length exceeded!");
                    String name = columns[0].strip();
                    int count = Integer.parseInt(columns[1]);
                    double cost = Double.parseDouble(columns[2]);
                    dataList.add(new Product(name, count, cost));
                } catch (Exception ex) {
                    errorMap.put(line, ex);
                }
            }
        }
    }

    public List<Product> getList() {
        return dataList;
    }

    public Map<String, Exception> getErrorMap() {
        return errorMap;
    }
}
