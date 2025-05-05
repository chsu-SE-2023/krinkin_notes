// Тест 2: Определение чётного или нечётного числа (оператор %, условный if)
#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;  // Ввод числа пользователем

    // Проверка на чётность
    if (num % 2 == 0)
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;

    return 0;
}
