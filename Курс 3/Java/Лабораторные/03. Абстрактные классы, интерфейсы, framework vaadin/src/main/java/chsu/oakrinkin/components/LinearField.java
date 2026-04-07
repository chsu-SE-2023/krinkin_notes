package chsu.oakrinkin.components;

import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.orderedlayout.HorizontalLayout;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;

public class LinearField extends VerticalLayout {
    public LinearField() {
        add("Линейное уравнение");

        NumInput a = new NumInput("a");
        Spacer x = new Spacer("x");
        Sign sign1 = new Sign();
        NumInput b = new NumInput("b");
        Spacer res = new Spacer("=");
        NumInput equals = new NumInput("Равно");

        add(new HorizontalLayout(a, x, sign1, b, res, equals));

        Button solve = new Button("Решить");
        HorizontalLayout result = new HorizontalLayout(solve);

        solve.addClickListener(
                e -> {
                    result.add("Результат: "+compute(
                            a.getValue(),
                            b.getValue(),
                            equals.getValue()
                    ));
                }
        );
        add(result);

        this.setClassName("math-div");
    }

    private double compute(double a, double b, double res) {
        return (res - b)/a;
    }
}
