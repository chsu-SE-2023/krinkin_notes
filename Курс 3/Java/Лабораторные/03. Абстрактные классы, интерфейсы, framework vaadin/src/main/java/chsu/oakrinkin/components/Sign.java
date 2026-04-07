package chsu.oakrinkin.components;

import com.vaadin.flow.component.textfield.TextField;

public class Sign extends TextField {
    public Sign() {
//        super.setLabel("ㅤ");
        super.setClassName("spacer");
        super.setAllowedCharPattern("[+-]");
        super.setMaxLength(1);
        super.setValue("+");
    }
}
