package chsu.krinkin.types;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class CustomerWindow extends JFrame {

    private Label state = new Label("Отключен");

    public CustomerWindow() throws HeadlessException {
        super();
        this.setTitle("Абонент");
        this.setSize(250, 350);
        this.setLayout(null);
        this.setResizable(false);

        Label number = new Label(genNumber());
        number.setAlignment(Label.CENTER);
        number.setFont(new Font("Arial", Font.PLAIN, 20));
        number.setBounds(15, 50, 200, 30);
        this.add(number);

        Button call = new Button("Вызов");
        call.setBounds(40, 270, 50, 30);
        this.add(call);

        Button hangout = new Button("Сбросить");
        hangout.setBounds(100, 270, 100, 30);
        this.add(hangout);

        state.setAlignment(Label.CENTER);
        state.setBounds(65, 100, 100, 30);
        this.add(state);

        this.setVisible(true);
    }

    private String genNumber() {
        Random r = new Random();
        return "+7" +
                String.format("%03d", r.nextInt(1000)) +
                String.format("%03d", r.nextInt(1000)) +
                String.format("%02d", r.nextInt(100)) +
                String.format("%02d", r.nextInt(100));
    }
}
