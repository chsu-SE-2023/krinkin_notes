package chsu.oakrinkin.components;

import com.vaadin.flow.component.dependency.StyleSheet;
import com.vaadin.flow.component.textfield.TextField;

@StyleSheet("styles.css")
public class Spacer extends TextField {
    public Spacer(String label) {
//        super.setLabel("ㅤ");
        super.setClassName("spacer");
        super.setValue(label);
        super.setReadOnly(true);
    }
}
