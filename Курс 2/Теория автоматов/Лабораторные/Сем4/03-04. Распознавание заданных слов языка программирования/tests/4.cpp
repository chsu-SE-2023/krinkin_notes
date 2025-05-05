// Тест 4: Простое меню (switch-case)
#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. Say Hello\n2. Say Bye\nEnter choice: ";
    cin >> choice;  // Ввод выбора пользователем

    /* Обработка выбора с помощью оператора switch */
    switch(choice) {
        case 1:
            cout << "Hello!" << endl;
            break; // Обязательно прерываем выполнение
        case 2:
            cout << "Bye!" << endl;
            break;
        default:
            // Обработка неверного ввода
            cout << "Invalid choice." << endl;
    }

    return 0;
}
