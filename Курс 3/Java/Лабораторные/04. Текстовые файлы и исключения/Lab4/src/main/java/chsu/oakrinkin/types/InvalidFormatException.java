package chsu.oakrinkin.types;

public class InvalidFormatException extends Exception {
    public InvalidFormatException(String message) {
        super(message);
    }

    public InvalidFormatException(String message, Throwable cause) {
        super(message, cause);
    }
}
