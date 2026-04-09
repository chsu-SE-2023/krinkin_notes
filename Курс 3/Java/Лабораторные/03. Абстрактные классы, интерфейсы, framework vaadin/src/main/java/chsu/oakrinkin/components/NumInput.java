package chsu.oakrinkin.components;

import com.vaadin.flow.component.textfield.NumberField;
import com.vaadin.flow.data.value.ValueChangeMode;

public class NumInput extends NumberField {

    public NumInput(String label) {
        super.setPlaceholder(label);

        super.setValueChangeMode(ValueChangeMode.EAGER);
        super.addValueChangeListener(event -> {
            String valueStr = String.valueOf(event.getValue() != null ? event.getValue() : "");
            int length = Math.max(valueStr.length(), 1);
            super.getStyle().set("width", length + "ch");
        });
        super.getStyle().set("min-width", "2rem");
        super.getStyle().set("width", "2rem");
    }
}
