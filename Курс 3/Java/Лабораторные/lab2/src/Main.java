import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        // Создание
        Vector<Double> type1 = new Vector<>();
        // Добавление
        type1.add(1.0);
        type1.add(2.0);
        type1.add(3.0);
        // Вывод
        System.out.println(type1);
        // Замена
        type1.remove(1);
        type1.insertElementAt(2.5, 1);
        // Вывод итератором
        type1.iterator().forEachRemaining(x -> System.out.print(x+" "));


    }
}