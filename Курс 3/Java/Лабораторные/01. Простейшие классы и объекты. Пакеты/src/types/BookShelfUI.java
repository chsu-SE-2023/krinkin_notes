package types;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class BookShelfUI {

    private final ArrayList<Book> books = new ArrayList<>();
    private final Scanner scanner = new Scanner(System.in);
    public static String CLEAR_CLS = "\033[H\033[2J";

    public void inputBook() {
        Book newBook = new Book();
        System.out.print("Автор: ");
        newBook.setAuthor(scanner.nextLine().strip());

        System.out.print("Название: ");
        newBook.setTitle(scanner.nextLine().strip());

        System.out.print("Издатель: ");
        newBook.setPublisher(scanner.nextLine().strip());

        System.out.print("Год: ");
        newBook.setYear(Integer.parseInt(scanner.nextLine().strip()));

        System.out.print("Страниц: ");
        newBook.setPagesCount(Integer.parseInt(scanner.nextLine().strip()));

        books.add(newBook);
        System.out.println(newBook);
    }

    public void outMainMenu() {
        System.out.print(CLEAR_CLS);
        System.out.flush();
        System.out.print(
            """
            1. Добавить книгу
            2. Добавить книги из .csv
            3. Вывести список книг заданного автора
            4. Вывести список книг, выпущенных заданным издательством
            5. Вывести список книг, выпущенных после заданного года
            6. Выход
            Введите команду:\s
            """
        );
    }

    public void outByAuthor() {
        System.out.print("Автор: ");
        String author = scanner.nextLine().strip();
        for (Book book : books)
            if (book.getAuthor().equals(author))
                System.out.println(book);
    }

    public void outByPublisher() {
        System.out.print("Издатель: ");
        String publisher = scanner.nextLine().strip();
        for (Book book : books)
            if (book.getPublisher().equals(publisher))
                System.out.println(book);
    }

    public void outAfterYear() {
        System.out.print("Год: ");
        int year = Integer.parseInt(scanner.nextLine());
        for (Book book : books)
            if (book.getYear() > year)
                System.out.println(book);
    }

    public void loadFromFile() {
        System.out.print("Имя файла: ");
        try (BufferedReader reader = new BufferedReader(new FileReader(scanner.nextLine()))) {
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
        } catch (FileNotFoundException e) {
            System.out.println("Файл не найден");
        } catch (IOException e) {
            System.out.println("Не удалось открыть файл: "+e.getMessage());
        }
    }
}
