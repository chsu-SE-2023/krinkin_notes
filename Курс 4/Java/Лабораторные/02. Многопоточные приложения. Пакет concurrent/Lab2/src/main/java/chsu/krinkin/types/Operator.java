package chsu.krinkin.types;

public class Operator {

    private Customer customer = null;
    private int id = 0;

    public Operator(int id) {
        this.id = id;
    }

    public void connectCustomer(Customer customer) {
        this.customer = customer;
        this.customer.call();
    }

    public void disconnectCustomer() {
        this.customer.hang();
        this.customer = null;
    }

    public String getName() {
        return "Оператор "+id;
    }
}
