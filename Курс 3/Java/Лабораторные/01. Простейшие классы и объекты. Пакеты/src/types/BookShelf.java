package types;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.function.Predicate;

public class BookShelf {

    private final ArrayList<Book> books = new ArrayList<>();

    public void add(Book book){ books.add(book); }

    public BookShelf getByCriteria(Predicate<Book> condition) {
        BookShelf list = new BookShelf();
        for (Book book : books)
            if (condition.test(book))
                list.add(book);
        return list;
    }

    public BookShelf getByAuthor(String author) {
        return getByCriteria(book -> book.getAuthor().equals(author.strip()));
    }
    
    public BookShelf getByPublisher(String publisher) {
        return getByCriteria(book -> book.getPublisher().equals(publisher.strip()));
    }

    public BookShelf getAfterYear(int year) {
        return getByCriteria(book -> book.getYear() > year);
    }

    public void loadFromFile(String filename) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filename.strip()));
        for (Object line : reader.lines().toArray()) {
            if (line instanceof String) {
                String[] book = ((String) line).split(",");
                books.add(new Book(
                    book[0],
                    book[1],
                    book[2],
                    Integer.parseInt(book[3]),
                    Integer.parseInt(book[4])
                ));
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder buffer = new StringBuilder();
        for (Book book : books) {
            buffer.append(book);
            buffer.append('\n');
        }
        if (buffer.toString().isEmpty()) return "Книг нет!";
        buffer.deleteCharAt(buffer.lastIndexOf("\n"));
        return buffer.toString();
    }
}
