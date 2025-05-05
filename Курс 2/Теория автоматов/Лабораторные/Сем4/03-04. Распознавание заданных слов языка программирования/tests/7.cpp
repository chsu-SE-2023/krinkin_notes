// Тест 7: Обратный отсчёт с пропуском (цикл for, continue)
#include <iostream>
using namespace std;

int main() {
    // Обратный отсчёт от 10 до 0
    for (int i = 10; i >= 0; --i) {
        if (i == 5)
            continue;  // Пропустить число 5

        cout << i << " ";
    }

    cout << endl;
    return 0;
}
