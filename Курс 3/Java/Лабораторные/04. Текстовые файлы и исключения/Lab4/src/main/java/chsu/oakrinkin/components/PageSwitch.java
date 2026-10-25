package chsu.oakrinkin.components;

import com.vaadin.flow.component.ClickEvent;
import com.vaadin.flow.component.ComponentEventListener;
import com.vaadin.flow.component.Text;
import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.html.Div;

public class PageSwitch extends Div {
    private int currentPage = 1;
    private final Button left = new Button("<");
    private final Button right = new Button(">");

    public PageSwitch(int pages) {
        super();
        Text label = new Text("Страница 1");

        left.addClickListener(e -> {
            if (currentPage > 1) {
                currentPage--;
                label.setText("Страница "+currentPage);
            }
        });
        right.addClickListener(e -> {
            if (currentPage < pages) {
                currentPage++;
                label.setText("Страница "+currentPage);
            }
        });
        this.add(left, label, right);
    }

    public int getCurrentPage() {
        return currentPage;
    }

    public void addPageSwitchListener(ComponentEventListener<ClickEvent<Button>> listener) {
        left.addClickListener(listener);
        right.addClickListener(listener);
    }
}
