package chsu.oakrinkin;

import chsu.oakrinkin.types.Spiral;

import javax.swing.*;
import java.awt.*;

import static javax.swing.JFrame.EXIT_ON_CLOSE;

public class Main {

    public static void main(String[] args) {
        JFrame window = new JFrame("Lab1");
        window.setSize(800, 800);

        Canvas canvas = new Canvas();
        canvas.setBackground(Color.WHITE);
        canvas.setVisible(true);
        window.add(canvas);

        new Spiral(canvas).run();

        window.setBackground(Color.WHITE);
        window.setResizable(false);
        window.setDefaultCloseOperation(EXIT_ON_CLOSE);
        window.setVisible(true);
    }
}
