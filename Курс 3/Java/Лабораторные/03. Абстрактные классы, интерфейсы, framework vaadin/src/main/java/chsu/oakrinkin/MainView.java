package chsu.oakrinkin;

import chsu.oakrinkin.components.LinearField;
import chsu.oakrinkin.components.SquareField;
import com.vaadin.flow.component.dependency.StyleSheet;
import com.vaadin.flow.component.html.Div;
import com.vaadin.flow.component.html.H1;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import com.vaadin.flow.router.Route;

@Route
@StyleSheet("styles.css")
public class MainView extends VerticalLayout {

    public MainView() {

        Div mainDiv = new Div(
            new H1("Лабораторная работа №3"),
            new SquareField(),
            new LinearField()
        );
        mainDiv.setClassName("center");
        add(mainDiv);
        this.setPadding(false);
    }
}
