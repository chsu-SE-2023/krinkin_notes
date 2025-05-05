// Тест 10: Замена местами двух переменных без третьей (арифметика)
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    // Меняем местами значения без третьей переменной
    a = a + b; // a = 30
    b = a - b; // b = 10
    a = a - b; // a = 20

    cout << "a: " << a << ", b: " << b << endl;
    return 0;
}
