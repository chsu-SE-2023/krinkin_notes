package chsu.krinkin;

import chsu.krinkin.types.Customer;

import javax.swing.*;
import java.awt.*;
import java.util.Objects;
import java.util.Random;

public class CustomerWindow extends JFrame {

    private final Label state = new Label();
    private final Customer customer = new Customer(state);
    Button call;
    Button hangout;

    public CustomerWindow() throws HeadlessException {
        super();
        this.setTitle("Абонент");
        this.setSize(250, 350);
        this.setLayout(null);
        this.setResizable(false);

        Label number = new Label(customer.getNumber());
        number.setAlignment(Label.CENTER);
        number.setFont(new Font("Arial", Font.PLAIN, 20));
        number.setBounds(25, 50, 200, 30);
        this.add(number);

        call = new Button("Вызов");
        call.setBounds(95, 270, 70, 30);
        call.addActionListener((e) -> customer.call());
        this.add(call);

        hangout = new Button("Сбросить");
        hangout.setBounds(80, 270, 100, 30);
        hangout.addActionListener((e) -> customer.hang());
        this.add(hangout);

        state.setAlignment(Label.CENTER);
        state.setBounds(50, 100, 150, 30);
        state.addPropertyChangeListener((e) -> updateButton());
        this.add(state);

        customer.setUpdateUIHandler(this::updateButton);
        this.updateButton();

        this.setVisible(true);

        customer.call();
    }

    void updateButton() {
        System.out.println("UPDATED");
        if (Objects.equals(state.getText(), "Вызов завершён")) {
            call.setVisible(true);
            hangout.setVisible(false);
        }
        else {
            call.setVisible(false);
            hangout.setVisible(true);
        }
    }
}
