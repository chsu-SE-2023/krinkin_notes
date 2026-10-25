package chsu.oakrinkin.components;

import chsu.oakrinkin.types.DataReader;
import chsu.oakrinkin.types.Product;
import com.vaadin.flow.component.html.Div;
import com.vaadin.flow.component.html.H3;
import com.vaadin.flow.component.html.Paragraph;

import java.util.List;

public class Stats extends Div {

    private final SearchBox searchBox = new SearchBox("Поиск");
    private final DataReader reader;

    public Stats(DataReader reader) {
        super();
        this.reader = reader;
        this.setClassName("stats-div");
        if (!this.reader.isEmpty()) {
            H3 label = new H3("Статистика");
            label.getStyle().set("margin-top", "20px");
            this.add(label);
            this.add(new Paragraph("Общая стоимость: "+this.reader.getTotalCost()));
            this.add(new Paragraph("Самый дешёвый товар: "+this.reader.getMostCheap()));
            this.add(searchBox);
            searchBox.addSearchButtonListener(e -> handleSearch());
        }
    }

    private void handleSearch() {
        Div searchResults = new Div();
        searchResults.setClassName("search-results");
        List<Product> products = this.reader.search(searchBox.getSearchQuery());
        if (products.isEmpty()) searchResults.add(new Paragraph("Ничего не найдено"));
        for (Product p : products)
            searchResults.add(new Paragraph(p.toString()));
        this.getChildren()
                .filter(x -> x.hasClassName("search-results"))
                .forEach(this::remove);
        this.add(searchResults);
    }
}
