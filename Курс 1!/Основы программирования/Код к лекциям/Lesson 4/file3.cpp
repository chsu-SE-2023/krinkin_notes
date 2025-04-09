// Дмумерный числовой массив поменять местами. Первую строку с последней, вторую с предпоследней и т.д.

#include <iostream>
int main() {

    const int n = 7, m = 7;

    int arr[n][m];

    srand(time(0));

    for (int a=0;a<n;a++)
        for (int b=0;b<m;b++)
            arr[a][b] = std::rand() % 100;

    for (int a=0;a<n;a++) {
        for (int b=0;b<m;b++) {
            std::cout.width(4);
            std::cout << arr[a][b];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int a=0;a<n/2;a++) {
        std::swap(arr[a], arr[n-a-1]);
    }

    for (int a=0;a<n;a++) {
        for (int b=0;b<m;b++) {
            std::cout.width(4);
            std::cout << arr[a][b];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}