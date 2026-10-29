package chsu.oakrinkin;

import chsu.oakrinkin.types.Spiral;

import javax.swing.*;
import java.awt.*;

import static javax.swing.JFrame.EXIT_ON_CLOSE;

public class Main {

    public static void main(String[] args) {
        JFrame window = new JFrame("Lab1");
        window.setSize(210, 230);
        window.setBackground(Color.WHITE);
        window.setDefaultCloseOperation(EXIT_ON_CLOSE);
        window.setResizable(false);
        window.setLayout(null);
        window.setVisible(true);

        Button unsynced = new Button("Без синхронизации");
        unsynced.addActionListener((e) -> unsyncedWindow());
        unsynced.setBounds(10, 10, 170, 50);
        window.add(unsynced);

        Button synced = new Button("Синхронизация");
        synced.addActionListener((e) -> syncedWindow());
        synced.setBounds(10, 70, 170, 50);
        window.add(synced);

        Button windows = new Button("Отдельными окнами");
        windows.addActionListener((e) -> syncedWindows());
        windows.setBounds(10, 130, 170, 50);
        window.add(windows);
    }

    private static void unsyncedWindow() {
        Canvas canvas = newCanvasWindow("Lab1: Без синхронизации");

        Spiral spiral1 = new Spiral(canvas.getGraphics(), Color.RED);
        spiral1.setSteps(10000);
        spiral1.setParams(10, 0.25);
        spiral1.setAngleStep(1);
        spiral1.setAnchor(200, 200);
        spiral1.start();

        Spiral spiral2 = new Spiral(spiral1);
        spiral2.setColor(Color.GREEN);
        spiral2.setAnchor(400, 400);
        spiral2.start();

        Spiral spiral3 = new Spiral(spiral1);
        spiral3.setColor(Color.BLUE);
        spiral3.setAnchor(600, 600);
        spiral3.start();
    }

    private static void syncedWindow() {
        Canvas canvas = newCanvasWindow("Lab1: Синхронизация");

        Spiral spiral1 = new Spiral(canvas.getGraphics(), Color.RED);
        spiral1.setSteps(10000);
        spiral1.setParams(10, 0.25);
        spiral1.setAngleStep(1);
        spiral1.setAnchor(200, 200);
        spiral1.setSync(true); // Синхронизация
        spiral1.start();

        Spiral spiral2 = new Spiral(spiral1);
        spiral2.setColor(Color.GREEN);
        spiral2.setAnchor(400, 400);
        spiral2.start();

        Spiral spiral3 = new Spiral(spiral1);
        spiral3.setColor(Color.BLUE);
        spiral3.setAnchor(600, 600);
        spiral3.start();
    }

    private static void syncedWindows() {
        Canvas canvas1 = newCanvasWindow("Lab1: Отдельными окнами (1)");
        Canvas canvas2 = newCanvasWindow("Lab1: Отдельными окнами (2)");
        Canvas canvas3 = newCanvasWindow("Lab1: Отдельными окнами (3)");

        Spiral spiral1 = new Spiral(canvas1.getGraphics(), Color.RED);
        spiral1.setSteps(10000);
        spiral1.setParams(10, 0.25);
        spiral1.setAngleStep(1);
        spiral1.setAnchor(400, 400);
        spiral1.start();

        Spiral spiral2 = new Spiral(spiral1);
        spiral2.setGraphics(canvas2.getGraphics());
        spiral2.setColor(Color.GREEN);
        spiral2.start();

        Spiral spiral3 = new Spiral(spiral1);
        spiral3.setGraphics(canvas3.getGraphics());
        spiral3.setColor(Color.BLUE);
        spiral3.start();
    }

    private static Canvas newCanvasWindow(String title) {
        JFrame window = new JFrame(title);
        window.setSize(800, 800);
        window.setBackground(Color.WHITE);
        window.setResizable(false);
        window.setVisible(true);

        Canvas canvas = new Canvas();
        canvas.setBackground(Color.WHITE);
        window.add(canvas);
        return canvas;
    }
}
