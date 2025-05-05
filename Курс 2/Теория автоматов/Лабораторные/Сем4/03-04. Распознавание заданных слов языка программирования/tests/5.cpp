// Тест 5: Таблица умножения (цикл for)
#include <iostream>
using namespace std;

int main() {
    int n = 7;  // Таблица умножения для 7

    // Цикл от 1 до 10
    for (int i = 1; i <= 10; ++i)
        cout << n << " * " << i << " = " << n * i << endl;

    return 0;
}
