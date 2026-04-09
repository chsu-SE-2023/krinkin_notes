package chsu.oakrinkin.components;

import chsu.oakrinkin.types.Linear;
import chsu.oakrinkin.types.Root;
import com.vaadin.flow.component.Text;
import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.orderedlayout.HorizontalLayout;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;

import java.util.Objects;

public class LinearField extends VerticalLayout {
    public LinearField() {
        add("Линейное уравнение");

        NumInput a = new NumInput("a");
        Spacer x = new Spacer("x");
        Sign sign1 = new Sign();
        NumInput b = new NumInput("b");
        Spacer spacer = new Spacer("=");
        NumInput equals = new NumInput("Равно");
        equals.getStyle().set("min-width", "4.2rem");

        add(new HorizontalLayout(a, x, sign1, b, spacer, equals));

        Button solve = new Button("Решить");
        Text resText = new Text("");
        HorizontalLayout result = new HorizontalLayout(solve, resText);

        solve.addClickListener(
                e -> {
                    Root root = new Linear(
                            a.getValue(),
                            Objects.equals(sign1.getValue(), "-") ? b.getValue() * -1 : b.getValue(),
                            equals.getValue()
                    );
                    resText.setText("Результат: " + root);
                }
        );
        add(result);

        this.setClassName("math-div");
    }
}
