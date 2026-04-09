package chsu.oakrinkin.types;

import java.util.Set;

public class Linear implements Root {

    private final double a;
    private final double b;
    private final double res;

    public Linear(double a, double b, double res) {
        this.a = a;
        this.b = b;
        this.res = res;
    }

    @Override
    public Set<Double> compute() {
        return Set.of((res - b)/a);
    }

    @Override
    public String toString() {
        Set<Double> roots = compute();
        if (Double.isNaN((Double) roots.toArray()[0]))
            return "Нет решений!";
        else return "X = "+roots.toArray()[0];
    }

}
