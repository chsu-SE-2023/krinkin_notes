package chsu.krinkin.types;

import java.awt.Label;
import java.util.Random;
import java.util.function.Consumer;
import java.util.function.Function;

public class Customer implements Runnable {

    Thread call;
    String number = genNumber();
    Label stateLabel;
    Runnable uiUpdater;

    public Customer(Label state) {
        this.stateLabel = state;
    }

    @Override
    public void run() {
        int sec = 0;
        while (true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            sec++;
            this.stateLabel.setText("Звонок: "+sec+" сек");
        }
    }

    public void call() {
        call = new Thread(this);
        this.stateLabel.setText("Ожидание...");
        this.uiUpdater.run();
        call.start();
    }

    public void hang() {
        call.interrupt();
        this.stateLabel.setText("Вызов завершён");
        this.uiUpdater.run();
    }

    public void setUpdateUIHandler(Runnable func) {
        this.uiUpdater = func;
    }

    private String genNumber() {
        Random r = new Random();
        return "+7" +
                String.format("%03d", r.nextInt(1000)) +
                String.format("%03d", r.nextInt(1000)) +
                String.format("%02d", r.nextInt(100)) +
                String.format("%02d", r.nextInt(100));
    }

    public String getNumber() {
        return this.number;
    }
}
