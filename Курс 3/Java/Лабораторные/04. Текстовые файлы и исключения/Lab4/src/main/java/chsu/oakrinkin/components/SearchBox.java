package chsu.oakrinkin.components;

import com.vaadin.flow.component.ClickEvent;
import com.vaadin.flow.component.ComponentEventListener;
import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.html.Div;
import com.vaadin.flow.component.textfield.TextField;

public class SearchBox extends Div {

    private final Button search = new Button("Найти");
    private final TextField textField;

    public SearchBox(String label) {
        super();
        textField = new TextField(label);
        this.add(textField);
        this.add(search);
        this.getStyle().set("display", "grid");
        this.getStyle().set("grid-template-columns", "auto auto");
        this.getStyle().set("align-items", "end");
        this.getStyle().set("grid-gap", "1rem");
    }

    public void addSearchButtonListener(ComponentEventListener<ClickEvent<Button>> listener) {
        search.addClickListener(listener);
    }

    public String getSearchQuery() {
        return textField.getValue();
    }
}
