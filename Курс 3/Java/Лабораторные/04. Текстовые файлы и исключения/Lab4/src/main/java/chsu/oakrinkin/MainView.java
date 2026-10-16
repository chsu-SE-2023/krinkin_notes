package chsu.oakrinkin;

import chsu.oakrinkin.components.*;
import chsu.oakrinkin.types.DataReader;
import chsu.oakrinkin.types.Product;
import com.vaadin.flow.component.Component;
import com.vaadin.flow.component.Unit;
import com.vaadin.flow.component.dependency.StyleSheet;
import com.vaadin.flow.component.html.Div;
import com.vaadin.flow.component.html.H3;
import com.vaadin.flow.component.html.Paragraph;
import com.vaadin.flow.component.orderedlayout.HorizontalLayout;
import com.vaadin.flow.component.tabs.Tab;
import com.vaadin.flow.component.tabs.Tabs;
import com.vaadin.flow.component.textfield.TextField;
import com.vaadin.flow.component.upload.receivers.FileBuffer;
import com.vaadin.flow.router.Route;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;

@Route
public class MainView extends HorizontalLayout {

    FileBuffer frFileBuffer = new FileBuffer();
    FileBuffer linesFileBuffer = new FileBuffer();
    Div tab1Div = new Div();
    Div tab1LeftDiv = new Div();
    Div tab1RightDiv = new Div();
    Div tab2Div = new Div();
    Div tab2LeftDiv = new Div();
    Div tab2RightDiv = new Div();
    PageSwitch pageSwitchTab1 = null;
    PageSwitch pageSwitchTab2 = null;
    Map<String, Exception> errMap = new HashMap<>();

    public MainView() {
        Tab t1 = new Tab("Чтение через FileReader");
        Tab t2 = new Tab("Чтение через Files.lines()");
        Tabs tabs = new Tabs(t1, t2);
        tabs.setOrientation(Tabs.Orientation.VERTICAL);
        tabs.setHeight("240px");
        tabs.setWidth("240px");

        FileUpload uploadFR = new FileUpload(frFileBuffer);
        uploadFR.addAllFinishedListener(event -> uploadHandler(1));

        FileUpload uploadLines = new FileUpload(linesFileBuffer);
        uploadLines.addAllFinishedListener(event -> uploadHandler(2));

        uploadFR.setAcceptedFileTypes("text/plain", ".txt");
        uploadLines.setAcceptedFileTypes("text/plain", ".txt");

        tab1Div.add(tab1LeftDiv, tab1RightDiv);
        tab2Div.add(tab2LeftDiv, tab2RightDiv);
        tab1Div.getStyle().set("display", "grid");
        tab1Div.getStyle().set("grid-template-columns", "auto auto");
        tab1Div.getStyle().set("grid-gap", "3rem");
        tab2Div.getStyle().set("display", "grid");
        tab2Div.getStyle().set("grid-template-columns", "auto auto");
        tab2Div.getStyle().set("grid-gap", "3rem");

        H3 labelTab1 = new H3("Лабораторная работа №4");
        labelTab1.getStyle().set("margin", "1rem 0");
        H3 labelTab2 = new H3("Лабораторная работа №4");
        labelTab2.getStyle().set("margin", "1rem 0");

        tab1LeftDiv.add(labelTab1, uploadFR);
        tab2LeftDiv.add(labelTab2, uploadLines);
        tab1LeftDiv.setMaxWidth(700, Unit.PIXELS);
        tab2LeftDiv.setMaxWidth(700, Unit.PIXELS);
        tab1LeftDiv.setMinWidth(400, Unit.PIXELS);
        tab2LeftDiv.setMinWidth(400, Unit.PIXELS);
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

    Div getTabDiv(int tab, boolean left) {
        if (tab == 1 && left) return tab1LeftDiv;
        else if (tab == 1) return tab1RightDiv;
        else if (tab == 2 && left) return tab2LeftDiv;
        else if (tab == 2) return tab2RightDiv;
        return null;
    }

    PageSwitch getPageSwitch(int tab) {
        if (tab == 1) return pageSwitchTab1;
        if (tab == 2) return pageSwitchTab2;
        return null;
    }

    /// Пересоздание компонента на странице
    /// @param comp компонент
    /// @param tab вкладка
    void addComponent(Component comp, int tab) {
        Div tabDiv = getTabDiv(tab, true);
        if (comp.hasClassName("stats-div")) tabDiv = getTabDiv(tab, false);
        removeComponent(comp.getClassName(), tab);
        tabDiv.add(comp);
    }

    /// Удаление компонента со страницы
    /// @param className класс компонента
    /// @param tab вкладка
    void removeComponent(String className, int tab) {
        Div tabDiv = getTabDiv(tab, true);
        if (Objects.equals(className, "stats-div")) tabDiv = getTabDiv(tab, false);
        tabDiv.getChildren()
                .filter(x -> x.hasClassName(className))
                .forEach(tabDiv::remove);
    }

    /// Обработчик нажатия кнопки "Загрузить"
    /// @param tab вкладка
    void uploadHandler(int tab) {
        InputStream inputStream;
        Div tabDiv = getTabDiv(tab, true);

        PageSwitch pageSwitch = getPageSwitch(tab);

        if (pageSwitch != null)
            tabDiv.remove(pageSwitch);

        // Приём файла на диск
        if (tab == 2) inputStream = linesFileBuffer.getInputStream();
        else inputStream = frFileBuffer.getInputStream();
        File tmpFile = new File("tmp.txt");
        try {
            Files.copy(inputStream, tmpFile.toPath(), StandardCopyOption.REPLACE_EXISTING);
        } catch (IOException ex) {
            errMap.put("Entire file", ex);
        }

        // Чтение файла и вызов отрисовки
        DataReader reader = new DataReader(tmpFile);
        try {
            if (tab == 2) reader.ReadLines();
            else reader.Read();

            errMap.putAll(reader.getErrorMap());
            pageSwitch = new PageSwitch(reader.getPagesCount());
            pageSwitch.setClassName("page-switch");
        } catch (Exception ex) {
            errMap.put("Entire file", ex);
        } finally {
            DataGrid dataGrid = new DataGrid(reader, pageSwitch);
            removeComponent("page-switch", tab);
            if (pageSwitch != null) pageSwitch.addPageSwitchListener(e -> dataGrid.rebuild());
            if (pageSwitch != null) addComponent(pageSwitch, tab);
            addComponent(dataGrid, tab);
            addComponent(new Stats(reader), tab);
            addComponent(new Errors(errMap), tab);
            errMap.clear();
        }
    }
}
