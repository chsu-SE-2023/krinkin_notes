package chsu.oakrinkin;

import chsu.oakrinkin.types.BinaryFile;
import com.vaadin.flow.component.Unit;
import com.vaadin.flow.component.button.Button;
import com.vaadin.flow.component.html.Div;
import com.vaadin.flow.component.html.H2;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import com.vaadin.flow.component.textfield.IntegerField;
import com.vaadin.flow.component.textfield.TextArea;
import com.vaadin.flow.component.textfield.TextField;
import com.vaadin.flow.router.Route;

import java.nio.file.Path;

@Route
public class MainView extends VerticalLayout {

    private final IntegerField countField = new IntegerField();
    private final TextField filename = new TextField();
    private final TextArea textArea = new TextArea();

    public MainView() {
        H2 label = new H2("Лабораторная работа №5");
        add(label);

        Div fileCreate = new Div();
        fileCreate.getStyle().set("display", "grid");
        fileCreate.getStyle().set("grid-template-columns", "auto auto");
        fileCreate.getStyle().set("grid-gap", "0 1rem");

        Button readButton = new Button("Read file",
                event -> readFileHandler());
        fileCreate.add(readButton);

        filename.setPlaceholder("Filename");
        filename.setValue("numbers.bin");
        fileCreate.add(filename);

        Button genButton = new Button("Generate file",
                event -> generateFileHandler());
        fileCreate.add(genButton);

        countField.setStepButtonsVisible(true);
        countField.setLabel("Count");
        countField.setValue(20);
        fileCreate.add(countField);

        add(fileCreate);

        textArea.setWidthFull();
        textArea.setMaxWidth(50, Unit.PERCENTAGE);
        textArea.setLabel("Binary File");
        add(textArea);
    }

    void generateFileHandler() {
        BinaryFile file = new BinaryFile(Path.of(filename.getValue()));
        file.generateFile(countField.getValue());
    }

    void readFileHandler() {
        BinaryFile file = new BinaryFile(Path.of(filename.getValue()));
        file.readFile();
    }
}
