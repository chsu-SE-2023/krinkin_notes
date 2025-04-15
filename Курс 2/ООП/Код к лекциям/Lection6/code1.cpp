class Shape { // Абстрактный
public:
    void input(int a, int b);
    void print();
    virtual int S() = 0; // Площадь
    virtual int P() = 0; // Периметр
protected:
    int x, y;
};

class Shape1 {
    public:
    void input(int a, int b) {};
    void print() {};
    virtual int S() {
        // Реализация для этой фигуры
    };
    virtual int P() {
        // Реализация для этой фигуры
    };
};

int main() {
    Shape s0; // Неверно
    Shape* ps0; // Указатель
    Shape1 s1;
    return 0;
}