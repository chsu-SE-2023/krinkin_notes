package chsu.oakrinkin.components;

import chsu.oakrinkin.types.DataReader;
import chsu.oakrinkin.types.Product;
import com.vaadin.flow.component.grid.Grid;
import com.vaadin.flow.component.grid.HeaderRow;
import com.vaadin.flow.component.html.Div;

import java.util.List;

public class DataGrid extends Div {

    Grid<Product> grid = new Grid<>(Product.class, false);
    DataReader reader;
    PageSwitch pageSwitch;

    public DataGrid(DataReader reader, PageSwitch pageSwitch) {
        super();
        this.setClassName("table-div");
        this.reader = reader;
        this.pageSwitch = pageSwitch;
        if (!this.reader.isEmpty()) {
            List<Product> lst = this.reader.getList(this.pageSwitch.getCurrentPage());
            grid.addColumn(Product::getName).setHeader("Наименование").setAutoWidth(true);
            grid.addColumn(Product::getCount).setHeader("Количество").setAutoWidth(true);
            grid.addColumn(Product::getCost).setHeader("Цена").setAutoWidth(true);
            grid.setItems(lst);
            grid.setAllRowsVisible(true);
            this.add(grid);
        }
    }

    public void rebuild() {
        List<Product> lst = this.reader.getList(this.pageSwitch.getCurrentPage());
        grid.setItems(lst);
    }
}
