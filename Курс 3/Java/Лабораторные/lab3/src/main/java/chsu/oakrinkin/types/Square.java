package chsu.oakrinkin.types;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Square implements Root {

    private final double a;
    private final double b;
    private final double c;

    public Square(double a, double b, double c, double res) {
        this.a = a;
        this.b = b;
        this.c = c - res;
    }

    @Override
    public Set<Double> compute() {
        double D = b*b - 4*a*c;
        double x1 = (-b+Math.sqrt(D))/2*a;
        double x2 = (-b-Math.sqrt(D))/2*a;
        return new HashSet<>(List.of(x1, x2));
    }

    @Override
    public String toString() {
        Set<Double> roots = compute();
        if (roots.size() == 1)
            if (Double.isNaN((Double) roots.toArray()[0]))
                return "Нет решений!";
            else return "X = "+roots.toArray()[0];
        else
            return "X1 = " + roots.toArray()[0] + ", X2 = " + roots.toArray()[1];
    }
}
