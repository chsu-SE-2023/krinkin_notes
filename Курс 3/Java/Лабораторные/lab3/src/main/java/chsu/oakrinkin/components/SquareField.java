package chsu.oakrinkin.components;

import chsu.oakrinkin.types.Root;
import chsu.oakrinkin.types.Square;
import com.vaadin.flow.component.Text;
import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.dependency.StyleSheet;
import com.vaadin.flow.component.orderedlayout.HorizontalLayout;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;

import java.util.Objects;

@StyleSheet("styles.css")
public class SquareField extends VerticalLayout {

    public SquareField() {

        add("Квадратное уравнение");

        NumInput a = new NumInput("a");
        Spacer x2 = new Spacer("x²");
        Sign sign1 = new Sign();
        NumInput b = new NumInput("b");
        Spacer x = new Spacer("x");
        Sign sign2 = new Sign();
        NumInput c = new NumInput("c");
        Spacer spacer = new Spacer("=");
        NumInput equals = new NumInput("Равно");
        equals.getStyle().set("min-width", "4.2rem");

        add(new HorizontalLayout(a, x2, sign1, b, x, sign2, c, spacer, equals));

        Button solve = new Button("Решить");
        Text resText = new Text("");
        HorizontalLayout result = new HorizontalLayout(solve, resText);
        solve.addClickListener(
            e -> {
                Root root = new Square(
                        a.getValue(),
                        Objects.equals(sign1.getValue(), "-") ? b.getValue() * -1 : b.getValue(),
                        Objects.equals(sign2.getValue(), "-") ? c.getValue() * -1 : c.getValue(),
                        equals.getValue()
                );
                resText.setText("Результат: " + root);
            }
        );
        add(result);

        this.setClassName("math-div");
    }
}
