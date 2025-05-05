// Тест 8: Проверка числа на простоту (операторы деления и логики)
#include <iostream>
using namespace std;

int main() {
    int num = 29;
    bool isPrime = true;

    /* Проверка делимости от 2 до sqrt(num) */
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            isPrime = false;  // Нашли делитель — не простое
            break;
        }
    }

    // Выводим результат с тернарным оператором
    cout << num << (isPrime ? " is prime" : " is not prime") << endl;

    return 0;
}
