package chsu.oakrinkin.types;

import javax.swing.*;
import java.awt.*;

public class Spiral implements Runnable {

    private final int steps = 10000;
    private final double d_fi = 0.01;
    private final double a = 10, k = 0.25;

    private final Canvas canvas;
    private Timer timer;
    private int n = 0;
    private double x_n = 0;
    private double y_n = 0;

    public Spiral(Canvas canvas) {
        this.canvas = canvas;
        this.timer = new Timer(1, e -> {
            if (n < steps) {
                double fi_n = n * d_fi;
                double r_n = a * Math.pow(Math.E, k*fi_n);
                x_n = r_n * Math.cos(fi_n);
                y_n = r_n * Math.sin(fi_n);
                canvas.repaint();
                n++;
            } else {
                this.timer.stop();
            }
        });
        this.timer.start();
    }

    private void drawPoint(int x, int y, Color col) {
        canvas.getGraphics().setColor(col);
        canvas.getGraphics().fillOval(x, y, 4, 4);
    }

    @Override
    public void run() {
        drawPoint(200+(int)x_n, 200+(int)y_n, Color.RED);
    }
}