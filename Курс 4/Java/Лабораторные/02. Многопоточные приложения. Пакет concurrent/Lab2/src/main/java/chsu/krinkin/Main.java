package chsu.krinkin;

import chsu.krinkin.types.CustomerWindow;

import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {
        JFrame window = new JFrame("Lab2");
        window.setLayout(null);
        window.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        window.setSize(500, 500);
        window.setResizable(false);

        String[][] data = {
                { "Оператор 1", "4031 CSE" },
                { "Оператор 2", "4031 CSE" },
                { "Оператор 3", "4031 CSE" },
                { "Оператор 4", "4031 CSE" },
                { "Оператор 5", "4031 CSE" },
        };
        String[] columnNames = { "Оператор", "Абонент" };
        JTable table = new JTable(data, columnNames);
        JScrollPane sp = new JScrollPane(table);
        sp.setBounds(20, 20, 450, 380);
        window.add(sp);

        Button newC = new Button("Новый абонент");
        newC.setBounds(185, 415, 110, 30);
        newC.addActionListener((e) -> new CustomerWindow());
        window.add(newC);

        window.setVisible(true);
    }
}
