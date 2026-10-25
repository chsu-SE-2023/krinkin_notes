package chsu.oakrinkin.types;

public class Product {
    private String name;
    private int count;
    private double cost;

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

    public void setName(String name) {
        this.name = name;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

    @Override
    public String toString() {
        return name+" "+count+" "+cost;
    }
}
