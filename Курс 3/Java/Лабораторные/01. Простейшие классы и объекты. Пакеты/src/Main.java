import java.io.IOException;
import java.util.Scanner;

import types.Book;
import types.BookShelf;

public class Main {

    private static final String CLEAR_CLS = "\033[H\033[2J";

    private static void inputBook(Scanner scanner, BookShelf books) {
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

    private static void outMainMenu() {
        System.out.print(CLEAR_CLS);
        System.out.print('\n');
        System.out.print(
                """
                1. Добавить книгу
                2. Добавить книги из .csv
                3. Вывести список всех книг
                4. Вывести список книг, выпущенных заданным автором
                5. Вывести список книг, выпущенных заданным издательством
                6. Вывести список книг, выпущенных после заданного года
                7. Выход
                Введите команду:\s"""
        );
    }

    private static void outByAuthor(Scanner scanner, BookShelf books) {
        System.out.print("Автор: ");
        String author = scanner.nextLine();
        System.out.println(books.getByAuthor(author));
    }

    private static void outByPublisher(Scanner scanner, BookShelf books) {
        System.out.print("Издатель: ");
        String publisher = scanner.nextLine();
        System.out.println(books.getByPublisher(publisher));
    }

    private static void outAfterYear(Scanner scanner, BookShelf books) {
        System.out.print("Год: ");
        int year = Integer.parseInt(scanner.nextLine());
        System.out.println(books.getAfterYear(year));
    }

    private static void loadFromFile(Scanner scanner, BookShelf books) {
        System.out.print("Имя файла: ");
        try {
            books.loadFromFile(scanner.nextLine());
        } catch (IOException e) {
            System.out.println("Не удалось открыть файл: "+e.getMessage());
            return;
        }
        System.out.println("Успех!");
    }

    public static void main(String[]args) {

        BookShelf shelf = new BookShelf();
        Scanner scanner = new Scanner(System.in);

        int command;
        while (true) {
            outMainMenu();
            command = Integer.parseInt(scanner.nextLine());

            if (command == 7) break;
            switch (command) {
                case 1: inputBook(scanner, shelf); break;
                case 2: loadFromFile(scanner, shelf); break;
                case 3: System.out.println(shelf); break;
                case 4: outByAuthor(scanner, shelf); break;
                case 5: outByPublisher(scanner, shelf); break;
                case 6: outAfterYear(scanner, shelf); break;
            }
        }
    }
}