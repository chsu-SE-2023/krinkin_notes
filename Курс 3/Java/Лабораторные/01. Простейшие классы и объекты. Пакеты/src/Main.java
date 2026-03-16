import java.util.Scanner;

import types.BookShelfUI;

public class Main {

    public static void main(String[]args) {

        BookShelfUI shelf = new BookShelfUI();
        Scanner scanner = new Scanner(System.in);

        int command;
        while (true) {
            shelf.outMainMenu();
            command = Integer.parseInt(scanner.next());

            if (command == 6) break;
            switch (command) {
                case 1: shelf.inputBook(); break;
                case 2: shelf.loadFromFile(); break;
                case 3: shelf.outByAuthor(); break;
                case 4: shelf.outByPublisher(); break;
                case 5: shelf.outAfterYear(); break;
            }
        }
    }
}