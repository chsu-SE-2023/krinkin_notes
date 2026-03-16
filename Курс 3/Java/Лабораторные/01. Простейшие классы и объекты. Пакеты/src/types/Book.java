package types;

public class Book {

    private String author = "Неизвестный";
    private String title = "Без названия";
    private String publisher = "самиздат";
    private int year = 0;
    private int pagesCount = 0;

    public Book() {}

    public Book(String author, String title, String publisher, int year, int pagesCount) {
        this.author = author;
        this.title = title;
        this.publisher = publisher;
        this.year = year;
        this.pagesCount = pagesCount;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getPagesCount() {
        return pagesCount;
    }

    public void setPagesCount(int pagesCount) {
        this.pagesCount = pagesCount;
    }

    @java.lang.Override
    public java.lang.String toString() {
        return String.format(
                "%s %s [Текст] / %s - Изд: %s, %d, - %d с.",
                getAuthor(),
                getTitle(),
                getAuthor(),
                getPublisher(),
                getYear(),
                getPagesCount()
        );
    }
}
