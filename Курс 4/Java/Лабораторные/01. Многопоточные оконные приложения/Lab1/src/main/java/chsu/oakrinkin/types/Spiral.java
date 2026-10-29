package chsu.oakrinkin.types;

import javax.swing.*;
import java.awt.*;

public class Spiral extends JPanel implements Runnable {

    private int steps = 10000;
    private double a = 1, k = 0.25;
    private double d_fi = 0.01;
    private int anchor_x = 400;
    private int anchor_y = 400;
    private Graphics graphics;
    private Color color;
    private boolean sync = false;

    public Spiral(Graphics g, Color col) {
        this.graphics = g;
        this.color = col;
    }

    public Spiral(Spiral spiral) {
        this.steps = spiral.steps;
        this.a = spiral.a;
        this.k = spiral.k;
        this.d_fi = spiral.d_fi;
        this.anchor_x = spiral.anchor_x;
        this.anchor_y = spiral.anchor_y;
        this.graphics = spiral.graphics;
        this.color = spiral.color;
        this.sync = spiral.sync;
    }

    private void drawPoint(Integer x, Integer y) {
        this.graphics.setColor(this.color);
        this.graphics.fillOval(x, y, 4, 4);
    }

    private void drawPointSync(Integer x, Integer y) {
        Graphics g = this.graphics;
        synchronized (g) {
            g.setColor(this.color);
            g.fillOval(x, y, 4, 4);
        }
    }

    public void start() {
        new Thread(this).start();
    }

    @Override
    public void run() {
        for (int i = 0; i < steps; i++) {
            double fi_n = i * d_fi;
            double r_n = a * Math.pow(Math.E, k*fi_n);
            double x_n = r_n * Math.cos(fi_n);
            double y_n = r_n * Math.sin(fi_n);

            if (this.sync) drawPointSync(anchor_x+(int)x_n, anchor_y+(int)y_n);
            else drawPoint(anchor_x+(int)x_n, anchor_y+(int)y_n);

            try {
                Thread.sleep(1);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public void setSteps(int steps) {
        this.steps = steps;
    }

    public void setParams(double a, double k) {
        this.a = a;
        this.k = k;
    }

    public void setAngleStep(double degrees) {
        this.d_fi = degrees*(Math.PI/180);
    }

    public void setAnchor(int x, int y) {
        this.anchor_x = x;
        this.anchor_y = y;
    }

    public void setColor(Color col) {
        this.color = col;
    }

    public void setGraphics(Graphics g) {
        this.graphics = g;
    }

    public void setSync(boolean sync) {
        this.sync = sync;
    }
}