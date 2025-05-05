// Тест 6: Факториал числа (цикл while)
#include <iostream>
using namespace std;
int main() {
    int n = 5;
    int result = 1;
    // Вычисляем факториал от 5
    while (n > 0) {
        result *= n;
        --n;  // Уменьшаем значение n
    }
    cout << "Factorial: " << result << endl;
    return 0;
}
