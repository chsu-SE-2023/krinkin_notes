package chsu.oakrinkin.types;

public class Product {
    String name;
    int count;
    double cost;
    public Product(String name, int count, double cost) {
        this.name = name;
        this.count = count;
        this.cost = cost;
    }

    public String getName() {
        return name;
    }

    public int getCount() {
        return count;
    }

    public double getCost() {
        return cost;
    }

}
