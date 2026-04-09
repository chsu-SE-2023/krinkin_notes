package chsu.oakrinkin.components;

import com.vaadin.flow.component.textfield.TextField;

public class Sign extends TextField {
    public Sign() {
        super.setAllowedCharPattern("[+-]");
        super.setMaxLength(1);
        super.setValue("+");
        super.getStyle().set("max-width", "2rem");
    }
}
