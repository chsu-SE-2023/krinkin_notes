package chsu.oakrinkin.components;

import com.vaadin.flow.component.html.Div;
import com.vaadin.flow.component.html.H3;
import com.vaadin.flow.component.html.Paragraph;

import java.util.Map;

public class Errors extends Div {
    public Errors(Map<String, Exception> errMap) {
        this.setClassName("err-div");
        if (!errMap.isEmpty()) {
            H3 label = new H3("Ошибки");
            label.getStyle().set("margin-top", "20px");
            this.add(label);
            errMap.keySet().forEach(str ->
                    this.add(
                            new Paragraph("• "+str+" - "+errMap.get(str))
                    )
            );
        }
    }
}
