package chsu.oakrinkin.components;

import com.vaadin.flow.component.dependency.StyleSheet;
import com.vaadin.flow.component.textfield.IntegerField;
import com.vaadin.flow.component.textfield.TextField;

@StyleSheet("styles.css")
public class NumInput extends IntegerField {

    public NumInput(String label) {
//        super.setLabel(label);
        super.addClassName("num-input");
        super.setPlaceholder(label);
    }
}
