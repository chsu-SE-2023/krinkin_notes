// Дан одномерный числовой массив. Отсоритировать элементы по возрастанию
// Первый эмент будем сравнивать со всеми остальными массива со всеми остальными и если он больше некоторого помением их местами. В результате на первом месте окажется минимальный

#include <iostream>

int main() {

    const int n = 10;

    int arr[n] = {65, 6, 9, 7, 23, 15, 87, 9, 0, 4};

    for (int a=0;a<n;a++) {
        std::cout << arr[a] << " ";
    }
    std::cout << std::endl;

    for (int a=0;a<n;a++) {
        for (int b=0;b<n;b++) {
            if (arr[a] > arr[b]) std::swap[arr[a], arr[b]];
        }
    }

    for (int a=0;a<n;a++) {
        std::cout << arr[a] << " ";
    }
    std::cout << std::endl;

    return 0;
}