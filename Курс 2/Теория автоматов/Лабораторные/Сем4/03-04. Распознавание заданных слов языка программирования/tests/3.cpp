// Тест 3: Поиск наибольшего из трёх чисел (оператор if-else)
#include <iostream>
using namespace std;

int main() {
    float x = 10.5, y = 25.6, z = 15.3;
    float max;

    /* Определяем максимальное значение с помощью условных операторов */
    if (x > y && x > z)
        max = x;
    else if (y > z)
        max = y;
    else
        max = z;

    cout << "Max: " << max << endl;
    return 0;
}
