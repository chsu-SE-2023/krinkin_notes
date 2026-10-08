package chsu.oakrinkin;

import chsu.oakrinkin.components.DataGrid;
import chsu.oakrinkin.types.DataReader;
import com.vaadin.flow.component.Component;
import com.vaadin.flow.component.html.Div;
import com.vaadin.flow.component.html.H1;
import com.vaadin.flow.component.html.Paragraph;
import com.vaadin.flow.component.orderedlayout.HorizontalLayout;
import com.vaadin.flow.component.tabs.Tab;
import com.vaadin.flow.component.tabs.Tabs;
import com.vaadin.flow.component.upload.Upload;
import com.vaadin.flow.component.upload.receivers.FileBuffer;
import com.vaadin.flow.router.Route;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.HashMap;
import java.util.Map;

@Route
public class MainView extends HorizontalLayout {

    FileBuffer fileBuffer = new FileBuffer();
    Div tab1Div = new Div();
    Div tab2Div = new Div();

    public MainView() {
        Tab t1 = new Tab("Таблица");
        Tab t2 = new Tab("О таблице");
        Tabs tabs = new Tabs(t1, t2);
        tabs.setOrientation(Tabs.Orientation.VERTICAL);
        tabs.setHeight("240px");
        tabs.setWidth("240px");

        Upload fileUpload = new Upload();
        fileUpload.setReceiver(fileBuffer);
        fileUpload.addAllFinishedListener(event -> buildTable());
        fileUpload.setDropAllowed(false);

        Paragraph label = new Paragraph("Таблица не загружена!");

        tab1Div.add(fileUpload);
        tab2Div.add(label);
        this.add(tabs, tab1Div, tab2Div);

        Map<Tab, Component> tabsToComponents = new HashMap<>();
        tabsToComponents.put(t1, tab1Div);
        tabsToComponents.put(t2, tab2Div);
        tabs.addSelectedChangeListener(event -> {
            tabsToComponents.values().forEach(component -> component.setVisible(false));
            tabsToComponents.get(tabs.getSelectedTab()).setVisible(true);
        });
        tabsToComponents.values().forEach(component -> component.setVisible(false));
        tabsToComponents.get(t1).setVisible(true);
    }

    void buildTable() {
        InputStream inputStream = fileBuffer.getInputStream();
        File tmpFile = new File("upload.txt");
        try {
            Files.copy(inputStream, tmpFile.toPath(), StandardCopyOption.REPLACE_EXISTING);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        DataReader reader = new DataReader(tmpFile);
        Div tableDiv = new Div();
        try {
            reader.Read();
            DataGrid gr = new DataGrid(reader.getList());
            H1 label = new H1("Ошибки");
            tableDiv.add(gr.getGrid(), label);
            Map<String, Exception> errMap = reader.getErrorMap();
            errMap.keySet().forEach(str -> {
                tableDiv.add(new Paragraph("* "+str+" - "+errMap.get(str)));
            });
        } catch (Exception ex) {
            Paragraph errMsg = new Paragraph("Произошла ошибка чтения: "+ex);
            tableDiv.add(errMsg);
        }
        tab1Div.add(tableDiv);
    }
}
