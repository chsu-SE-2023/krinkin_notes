package chsu.oakrinkin.types;

import javax.naming.SizeLimitExceededException;
import java.io.*;
import java.nio.file.Files;
import java.util.*;

public class DataReader {

    private final File file;
    int pageSize = 20;
    List<Product> dataList = new ArrayList<>();
    Map<String, Exception> errorMap = new HashMap<>();

    /// Метод, парсяций одну строку
    /// @param line строка
    /// @throws InvalidFormatException не валидный формат строки
    private void ParseLine(String line) throws InvalidFormatException {
        try {
            String[] columns = line.split(",");
            if (columns.length != 3) throw new InvalidFormatException("File should contain 3 columns!");
            if (columns[0].strip().length() > 20) throw new SizeLimitExceededException("Max column length exceeded!");
            String name = columns[0].strip();
            int count = Integer.parseInt(columns[1].strip());
            double cost = Double.parseDouble(columns[2].strip());
            dataList.add(new Product(name, count, cost));
        } catch (InvalidFormatException ex) {
            throw ex;
        } catch (Exception ex) {
            errorMap.put(line, ex);
        }
    }

    public DataReader(File file) {
        this.file = file;
    }

    /// Чтение файла с диска через FileReader
    /// @throws IOException да
    /// @throws InvalidFormatException да
    public void Read() throws IOException, InvalidFormatException {
        try (FileReader reader = new FileReader(file)) { // <---- Тут кстати
            BufferedReader buffer = new BufferedReader(reader);

            String line;
            while ((line = buffer.readLine()) != null) {
                ParseLine(line);
            }
        }
    }

    /// Чтение файла через Files.lines
    /// @throws IOException снова да
    /// @throws InvalidFormatException снова да
    public void ReadLines() throws IOException, InvalidFormatException {
        try (java.util.stream.Stream<String> lines = Files.lines(this.file.toPath())) { // <---- Тут кстати
            java.util.Iterator<String> iterator = lines.iterator();
            while (iterator.hasNext()) {
                ParseLine(iterator.next());
            }
        }
    }

    /// Получение подсписка значений
    /// @param page страница
    /// @return посписок значений
    public List<Product> getList(int page) {
        if (dataList.size() < pageSize) return dataList;
        else if (pageSize*(page-1) > dataList.size()) return new ArrayList<>();
        else if (pageSize*page > dataList.size()) return dataList.subList(pageSize*(page-1), dataList.size());
        else return dataList.subList(pageSize*(page-1), pageSize*page);
    }

    public List<Product> search(String query) {
        List<Product> lst = new ArrayList<>();
        dataList.stream()
                .filter(x -> Objects.equals(x.getName(), query))
                .forEach(lst::add);
        return lst;
    }

    public double getTotalCost() {
        double total = 0;
        for (Product p : dataList) {
            total += p.getCost();
        }
        return total;
    }

    public Product getMostCheap() {
        double minCost = Double.MAX_VALUE;
        Product cheapest = null;
        for (Product p : dataList) {
            if (p.getCost() < minCost) {
                minCost = p.getCost();
                cheapest = p;
            }
        }
        return cheapest;
    }

    public Map<String, Exception> getErrorMap() {
        return errorMap;
    }

    public int getPagesCount() {
        return (int) Math.ceil((double) dataList.size() / pageSize);
    }

    public boolean isEmpty() {
        return dataList.isEmpty();
    }
}
