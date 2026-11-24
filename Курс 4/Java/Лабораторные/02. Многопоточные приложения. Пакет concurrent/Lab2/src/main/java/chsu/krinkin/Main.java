package chsu.krinkin;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.Arrays;

public class Main {

    private static JTable table = null;

    public static void main(String[] args) {
        JFrame window = new JFrame("Lab2");
        window.setLayout(null);
        window.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        window.setSize(500, 500);
        window.setResizable(false);

        String[] columnNames = { "Оператор", "Абонент" };
        DefaultTableModel data = new DefaultTableModel(columnNames, 0);
        table = new JTable(data);
        JScrollPane sp = new JScrollPane(table);
        sp.setBounds(20, 20, 450, 380);
        changeOperators(5);
        window.add(sp);

        Label countL = new Label("Операторов:");
        countL.setAlignment(Label.RIGHT);
        countL.setBounds(90, 415, 90, 30);
        window.add(countL);

        SpinnerNumberModel model = new SpinnerNumberModel(5, 0, Integer.MAX_VALUE, 1);
        JSpinner count = new JSpinner(model);
        count.setBounds(180, 415, 60, 30);
        count.addChangeListener((e) -> changeOperators((int)count.getValue()));
        window.add(count);

        Button newC = new Button("Новый абонент");
        newC.setBounds(240, 415, 130, 30);
        newC.addActionListener((e) -> new CustomerWindow());
        window.add(newC);

        window.setVisible(true);
    }

    static void changeOperators(int count) {
        DefaultTableModel tm = (DefaultTableModel)table.getModel();
        tm.setRowCount(0);
        for (int i = 0; i < count; i++) {
            tm.addRow(Arrays.asList("Оператор "+(i+1), "Свободен").toArray());
        }
    }
}
