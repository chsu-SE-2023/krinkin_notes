// Тест 1: Сумма и среднее трёх чисел (арифметические операторы)
#include <iostream>
using namespace std;

int main() {
    /* Объявление и инициализация переменных */
    int a = 5, b = 10, c = 15;

    // Вычисляем сумму
    int sum = a + b + c;

    // Вычисляем среднее (делим на 3.0, чтобы получить float)
    float average = sum / 3.0;

    // Выводим результат
    cout << "Sum: " << sum << ", Average: " << average << endl;
    return 0;
}
