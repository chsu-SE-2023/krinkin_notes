package chsu.oakrinkin.components;

import chsu.oakrinkin.types.Product;
import com.vaadin.flow.component.grid.Grid;
import com.vaadin.flow.data.provider.Query;

import java.util.List;

public class DataGrid {
    private final Grid<Product> grid = new Grid<>(Product.class, false);
    public DataGrid(List<Product> lst) {
        grid.addColumn(Product::getName).setHeader("Наименование").setAutoWidth(true);
        grid.addColumn(Product::getCount).setHeader("Количество").setAutoWidth(true);
        grid.addColumn(Product::getCost).setHeader("Цена").setAutoWidth(true);
        grid.setItems(lst);
        grid.setAllRowsVisible(true);
    }

    public Grid<Product> getGrid() {
        return grid;
    }

    public String toString(){
        return Integer.valueOf(grid.getDataProvider().size(new Query<>())).toString();
    }
}
