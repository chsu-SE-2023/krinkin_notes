import types.Workpiece;

import java.util.*;
import java.util.stream.Collectors;

public class Main {

    private static void func1() {
        // Создание
        Vector<Double> type1 = new Vector<>();
        // Добавление
        type1.add(6.3); type1.add(10.1); type1.add(0.4);
        type1.add(5.3); type1.add(7.2); type1.add(10.7);
        type1.add(8.2); type1.add(3.2); type1.add(5.6);
        type1.add(1.3); type1.add(5.3); type1.add(3.4);
        // Вывод
        System.out.print("Vector<Double> после создания - ");
        System.out.println(type1);
        // Замена
        type1.remove(1);
        type1.insertElementAt(2.5, 2);
        // Вывод итератором
        System.out.print("Vector<Double> по итератору - [");
        type1.iterator().forEachRemaining(x -> System.out.print(x+", "));
        System.out.print("]\n");
        // Создание
        TreeMap<Integer, Double> type2 = new TreeMap<>();
        // Добавление
        type2.put(1, 4.2); type2.put(2, 3.8); type2.put(3, .4);
        type2.put(4, 10.6); type2.put(5, 10.4); type2.put(6, 8.6);
        // Удаление после и добавление в первый
        type1.removeIf(x -> type1.indexOf(x) > 3);
        type1.addAll(type2.sequencedValues());
        // Вывод
        System.out.print("Vector<Double> изменённый - ");
        System.out.println(type1);
        System.out.print("TreeMap<Integer, Double> - ");
        System.out.println(type2);
    }

    private static void func2() {
        // Создание
        Vector<Workpiece> type1 = new Vector<>();
        // Добавление
        type1.add(new Workpiece("Свеча", "candle", 3));
        type1.add(new Workpiece("Ремень", "belt", 6));
        type1.add(new Workpiece("Кружка", "cup", 4));
        type1.add(new Workpiece("Кардхолдер", "cardholder", 9));
        type1.add(new Workpiece("Фоторамка", "photo_border", 2));
        // Вывод
        System.out.print("Vector<Workpiece> после создания - ");
        System.out.println(type1);
        // Замена
        type1.remove(1);
        type1.insertElementAt(new Workpiece("Тарелка", "plate", 5), 2);
        // Вывод итератором
        System.out.print("Vector<Workpiece> по итератору - [");
        type1.iterator().forEachRemaining(x -> System.out.print(x+", "));
        System.out.print("]\n");
        // Создание
        TreeMap<Integer, Workpiece> type2 = new TreeMap<>();
        // Добавление
        type2.put(1, new Workpiece("Мыло", "soap", 1));
        type2.put(2, new Workpiece("Ваза", "vase", 4));
        type2.put(3, new Workpiece("Статуэтка", "statue", 11));
        // Удаление после и добавление в первый
        type1.removeIf(x -> type1.indexOf(x) > 1);
        type1.addAll(type2.sequencedValues());
        // Вывод
        System.out.print("Vector<Workpiece> изменённый - ");
        System.out.println(type1);
        System.out.print("TreeMap<Integer, Workpiece> - ");
        System.out.println(type2);
    }

    private static void func3() {
        // Создание
        Vector<Workpiece> type1 = new Vector<>();
        // Добавление
        type1.add(new Workpiece("Свеча", "candle", 3));
        type1.add(new Workpiece("Ремень", "belt", 6));
        type1.add(new Workpiece("Кружка", "cup", 4));
        type1.add(new Workpiece("Кардхолдер", "cardholder", 9));
        type1.add(new Workpiece("Фоторамка", "photo_border", 2));
        // Сортировка
        type1.sort(Comparator.comparingInt(Workpiece::getCount));
        // Вывод
        System.out.print("Vector<Workpiece> отсортированный - ");
        System.out.println(type1);
        // Поиск по условию
        System.out.println("Workpiece первый найденный - "+
            type1.stream()
                .filter(x -> x.getCount() > 5)
                .findFirst());
        // Перемещение по условию
        TreeMap<Integer, Workpiece> type2 = new TreeMap<>();
        type2.putAll(type1.stream()
            .filter(x -> x.getCount() > 3)
            .collect(Collectors.toMap(type1::indexOf, e -> e))
        );
        // Вывод
        System.out.print("TreeMap<Integer, Workpiece> перемещённый - ");
        System.out.println(type2);
        // Сортировка по убыванию и вывод
        type1.sort(Comparator.comparingInt(Workpiece::getCount).reversed());
        System.out.print("Vector<Workpiece> отсортированный - ");
        System.out.println(type1);
        System.out.print("TreeMap<Integer, Workpiece> отсортированный - ");
        System.out.println(
            type2.sequencedValues().stream()
                .sorted(Comparator.comparingInt(Workpiece::getCount).reversed()).toList()
        );
        // Третий контейнер
        ArrayList<Workpiece> type3 = new ArrayList<>();
        type3.addAll(type1);
        type3.addAll(type2.sequencedValues());
        // Вывод
        System.out.print("ArrayList<Workpiece> - ");
        System.out.println(type3);
    }

    public static void main(String[] args) {
        System.out.println("Программа 1:");
        func1();
        System.out.println("Программа 2:");
        func2();
        System.out.println("Программа 3:");
        func3();
    }
}