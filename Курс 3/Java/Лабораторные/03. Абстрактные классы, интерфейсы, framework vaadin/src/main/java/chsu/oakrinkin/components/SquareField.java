package chsu.oakrinkin.components;

import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.dependency.StyleSheet;
import com.vaadin.flow.component.orderedlayout.HorizontalLayout;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;

@StyleSheet("styles.css")
public class SquareField extends VerticalLayout {

    public SquareField() {

        add("Крадратичное уравнение");

        NumInput a = new NumInput("a");
        Spacer x2 = new Spacer("x²");
        Sign sign1 = new Sign();
        NumInput b = new NumInput("b");
        Spacer x = new Spacer("x");
        Sign sign2 = new Sign();
        NumInput c = new NumInput("c");
        Spacer res = new Spacer("=");
        NumInput equals = new NumInput("Равно");

        add(new HorizontalLayout(a, x2, sign1, b, x, sign2, c, res, equals));

        Button solve = new Button("Решить");
        HorizontalLayout result = new HorizontalLayout(solve);
        solve.addClickListener(
            e -> result.add("Результат: "+compute(
                    a.getValue(),
                    b.getValue(),
                    c.getValue(),
                    equals.getValue()
            ))
        );
        add(result);

        this.setClassName("math-div");
    }

    private double compute(double a, double b, double c, double res) {
        double D = b*b - 4*a*c;
        double x1 = (-b+Math.sqrt(D))/2*a;
        double x2 = (-b-Math.sqrt(D))/2*a;
        return x1;
    }
}
