package types;

public class Workpiece {
    private String name;
    private String id;
    private int count;

    public Workpiece(String name, String id, int count) {
        this.name = name;
        this.id = id;
        this.count = count;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    @Override
    public String toString() {
        return name + " (" + id + ") (" + count + "шт.)";
    }

}
